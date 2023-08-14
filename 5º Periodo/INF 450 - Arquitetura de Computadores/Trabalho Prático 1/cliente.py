# Programação com Sockets
# Trabalho Prático 1 da Disciplina INF 452 - Redes de Computadores
# Objetivos: praticar conceitos de Sockets
# Criado por Rafael Zardo (ES105468) e Pedro Fiorio (ES105475) em 12/05/2023

# Informacoes IMPORTANTES:
# - Este arquivo contém toda implementação do cliente
# - A pasta meusArquivos contem os arquivos que podem ser enviados pelo /file
# - O /get so pode pegar arquivos da pasta arquivosServidor
# - A pasta arquivosRecebidos contem os arquivos obtidos a partir do /get

import socket
import threading

# Definicoes de conexao do servidor
HOST = 'localhost' 
PORT = 20000
enderecoServidor = (HOST,PORT)

# Função responsavel por enviar mensagems TCP para envio de arquivos ao servidor
def enviarTCP(mensagem):
    tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM) # Realiza uma conexao tcp para cada envio de arquivo
    tcp.connect(enderecoServidor) # Associa um endereço ao socket do servidor

    nomeArquivo = mensagem.split(" ")[1] 
    mensagemFormatada = "FILE:" + nomeArquivo + "\n"
    tcp.send(mensagemFormatada.encode()) # Envia a mensagem ao servidor do comando /file <nome>

    with open("./meusArquivos/" + nomeArquivo, "rb") as file: # Pega o arquivo da pasta meusArquivos
        dados = file.read() 
        tcp.sendall(dados) # Envia a mensagem os dados do arquivo para o servidor via TCP

    file.close()
    tcp.close()

# Função responsavel por enviar mensagems TCP para receber arquivos do servidor
def receberTCP(mensagem): 
    tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM) # Realiza uma conexao tcp para cada recebimento de arquivo
    tcp.connect(enderecoServidor) # Associa um endereço ao socket do servidor

    nomeArquivo = mensagem.split(" ")[1] 
    mensagemFormatada = "GET:" + nomeArquivo
    tcp.send(mensagemFormatada.encode()) # Envia a mensagem ao servidor do comando /get <nome>

    with open("./arquivosRecebidos/"+nomeArquivo, "wb") as file: # Salva o arquivo na pasta arquivosRecebidos
        while True:
            dados = tcp.recv(1024) # Recebe os dados do arquivos via TCP

            if not dados:
                break   

            file.write(dados)

    file.close()
    tcp.close()

# Função responsavel por receber mensagems ao servidor
def receberMensagem(udp):
    while True:
        mensagem, endereco = udp.recvfrom(1024) # Recebe a mensagem enviada pelo servidor
        mensagem = mensagem.decode()

        if ("INFO:" in mensagem): # O servidor retonar uma informação
            mensagemFormatada = mensagem.split(":")[1]
            print(mensagemFormatada)

        elif (mensagem == "BYE"): # O servidor retorna que a conexao pode ser encerrada
            break

        elif ("MSG:" in mensagem): # O servidor retorna uma mensagem
            mensagemFormatada = mensagem.split(":")
            nomeEmissor = mensagemFormatada[1]
            mensagemEmissor = mensagemFormatada[2]
            print(nomeEmissor + " disse: " + mensagemEmissor)

        else: # O servidor retorna uma lista
            print(mensagem)

# Função responsavel por enviar mensagems ao servidor
def enviarMensagem(udp, threadReceber):
    print("Nome de usuario: ")
    mensagem = input()
    mensagem = "USER:" + mensagem 
    udp.sendto(mensagem.encode(), enderecoServidor) # Envia a mensagem do novo usuário ao servidor

    threadReceber.start() # Após enviar uma mensagem, podemos iniciar as threads de recebimento de mensagem

    while True:
        mensagem = input()

        if ("/file" in mensagem):
            enviarTCP(mensagem) # Faz a conexão TCP para enviar files

            nomeArquivo = mensagem.split(" ")[1]
            mensagemFormatada = "FILE:" + nomeArquivo + "\n"
            udp.sendto(mensagemFormatada.encode(), enderecoServidor) # Envia a mensagem UDP ao servidor apos ter sucesso no envio do TCP
        
        elif ("/get" in mensagem):
            receberTCP(mensagem) # Faz a conexao TCP para receber files

        elif ("/list" in mensagem):
            udp.sendto("LIST".encode(), enderecoServidor) # Envia a mensagem UDP ao servidor

        elif (mensagem == "/bye"): # Ira solicitar ao servidor o fim da conexao, e por isso nao precisamos mais enviar mensagem
            udp.sendto("BYE".encode(), enderecoServidor) # Envia a mensagem UDP ao servidor
            break            

        else: # Se nao for nenhum dos comandos será uma msg
            mensagemFormatada = "MSG:" + mensagem # Envia a mensagem UDP ao servidor
            udp.sendto(mensagemFormatada.encode(), enderecoServidor)

# Funcão responsavel por inicializar as intâncias do cliente
def iniciarCliente():
    udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # Cria o socket UDP do cliente

    # Cria as threads para enviar e receber mensagens
    threadReceber = threading.Thread(target=receberMensagem, args=(udp, ))
    threadEnviar = threading.Thread(target=enviarMensagem, args=(udp, threadReceber))
    
    # Inicia a thread
    threadEnviar.start()

    # Aguarda até que ambas as threads terminem
    threadEnviar.join()
    threadReceber.join()

    udp.close()
    
if __name__ == '__main__':
    iniciarCliente()




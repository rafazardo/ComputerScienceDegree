# Programação com Sockets
# Trabalho Prático 1 da Disciplina INF 452 - Redes de Computadores
# Objetivos: praticar conceitos de Sockets
# Criado por Rafael Zardo (ES105468) e Pedro Fiorio (ES105475) em 12/05/2023

# Informacoes IMPORTANTES:
# - Este arquivo contém toda implementação do servidor
# - Os arquivos armazenados no cache do servidor estao na pasta arquivosServidor
# - O servidor nao possui uma condição de parada, assim que for ligado o mesmo permanece ligado

import socket
import threading

# Definicoes de conexao do servidor
HOST = '' 
PORT = 20000
enderecoServidor = (HOST,PORT)
clientesConectados = dict() # Armazena os clientes conectados no servidor 

# Função responsavel por enviar mensagems UDP ao cliente notificando uma nova entrada
def notificarEntrada(udp, nomeNovoCliente, enderecoNovoCliente):
    print(f"INFO:{nomeNovoCliente} entrou") # Mensagem de controle do serivdor

    mensagem = f"INFO:{nomeNovoCliente} entrou"
    mensagem = mensagem.encode()

    for endereco in clientesConectados:
        if (endereco != enderecoNovoCliente): # Envia para todos clientes, menos para ele mesmo
            udp.sendto(mensagem, endereco)            

# Função responsavel por enviar mensagems UDP ao cliente notificando uma nova saida
def notificarSaida(udp, nomeClienteSaida, enderecoClienteSaida):
    print(f"INFO:{nomeClienteSaida} saiu") # Mensagem de controle do serivdor

    mensagem = f"INFO:{nomeClienteSaida} saiu"
    mensagem = mensagem.encode()

    for endereco in clientesConectados:
        if (endereco != enderecoClienteSaida): # Envia para todos clientes, menos para ele mesmo
            udp.sendto(mensagem, endereco)        

# Função responsavel por enviar mensagems UDP ao cliente informando a lista de usuários conectados
def listarClientes(udp, enderecoClienteSolicitou):
    mensagem = "Clientes conectados: "

    for endereco in clientesConectados:
        mensagem += clientesConectados[endereco] + ", "

    mensagem = mensagem[:-2]
    mensagem = mensagem.encode()

    udp.sendto(mensagem, enderecoClienteSolicitou) 

# Função responsavel por enviar mensagems UDP ao cliente notificando uma nova mensagem
def notificarMensagem(udp, nomeClienteEnviou, enderecoClienteEnviou, mensagemClienteEnviou):
    mensagemClienteEnviouFormatada = mensagemClienteEnviou.split(":")[1]
    print("MSG:" + nomeClienteEnviou + ":" + mensagemClienteEnviouFormatada) # Mensagem de controle do serivdor
    
    mensagem = "MSG:" + nomeClienteEnviou + ":" + mensagemClienteEnviouFormatada
    mensagem = mensagem.encode()
    
    for endereco in clientesConectados:
        if (endereco != enderecoClienteEnviou): # Envia para todos clientes, menos para ele mesmo
            udp.sendto(mensagem, endereco)  

# Função responsavel por enviar mensagems UDP ao cliente notificando novos arquivos
def notificarArquivo(udp, nomeClienteEnviou, nomeArquivo, enderecoClienteEnviou):
    print(f"INFO:{nomeClienteEnviou} enviou {nomeArquivo}") # Mensagem de controle do serivdor
   
    mensagem = f"INFO:{nomeClienteEnviou} enviou {nomeArquivo}"
    mensagem = mensagem.encode()
    
    for endereco in clientesConectados:
        if (endereco != enderecoClienteEnviou): # Envia para todos clientes, menos para ele mesmo
            udp.sendto(mensagem, endereco)     

# Função responsavel por fazer o controle das conexoes TCP das threads
def conexaoTCP(conexao, cliente):
    comando = conexao.recv(1024).decode()
    nomeArquivo = comando.split(":")[1]
    
    if ("FILE:" in comando):
        nomeArquivo = nomeArquivo[:-1]

        with open("./arquivosServidor/"+nomeArquivo, "wb") as file: # Cria o arquivo na pasta do servidor arquivosServidor
            while True:
                dados = conexao.recv(1024)
                if not dados:
                    break
                file.write(dados)

        file.close()

    elif ("GET:" in comando):
        with open("./arquivosServidor/" + nomeArquivo, "rb") as file: # Pega o arquivo da pasta arquivosServidor
            dados = file.read() # Coleta o nome do arquivo para coleta-lo na pasta de meusArquivos do cliente
            conexao.sendall(dados) # Envia a mensagem os dados do arquivo para o servidor
        
        file.close()

    conexao.close() # Fecha a conexao da thread

    return 

# Função responsavel por gerenciar as threads de conexao do TCP
def gerenciarTCP(tcp):
    while True:
        conexao, cliente = tcp.accept()
        threadConexaoTCP = threading.Thread(target=conexaoTCP, args=(conexao, cliente))
        threadConexaoTCP.start()

# Funcão responsavel por estabelecer a conexao e mensagem dos clientes
def iniciarServicosUDP(udp):
    print("Aguardando conexao")

    while True:
        mensagem, endereco = udp.recvfrom(1024) # Recebe mensagem do cliente e armazena seu endereco
        mensagem = mensagem.decode()

        if ("USER:" in  mensagem and endereco not in clientesConectados): # Se for uma mensagem de novo usuario
            nome = mensagem.split(":")[1]
            clientesConectados[endereco] = nome # Adiciona esse cliente na lista de clientes conectados

            notificarEntrada(udp, nome, endereco)

        elif (mensagem == "BYE"):
            nome = clientesConectados[endereco]

            notificarSaida(udp, nome, endereco)

            del clientesConectados[endereco] # Remove o cliente da lista de clientes conectados

            udp.sendto("BYE".encode(), endereco) 
            
        elif (mensagem == "LIST"):
            listarClientes(udp, endereco)

        elif ("FILE:" in mensagem):
            nomeCliente = clientesConectados[endereco]
            nomeArquivo = mensagem.split(":")[1]
            nomeArquivo = nomeArquivo[:-1]

            notificarArquivo(udp, nomeCliente, nomeArquivo, endereco)

        elif ("MSG:" in mensagem):
            nome = clientesConectados[endereco]

            notificarMensagem(udp, nome, endereco, mensagem)

# Função responsavel por criar uma thread TCP para a mesma rolar em paralelo com o UDP
def iniciarServicosTCP(tcp):
    threadServicoTCP = threading.Thread(target=gerenciarTCP, args=(tcp, ))
    threadServicoTCP.start()

# Funcão responsavel por inicializar as intâncias do servidor
def iniciarServidor():
    udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # Cria o socket do servidor
    udp.bind(enderecoServidor) # Associa um endereço ao socket do servidor
    
    tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    tcp.bind(enderecoServidor)
    tcp.listen(50)

    print("[Servidor Iniciado]")
    iniciarServicosTCP(tcp)
    iniciarServicosUDP(udp)

    udp.close()
    tcp.close()

if __name__ == '__main__':
    iniciarServidor()
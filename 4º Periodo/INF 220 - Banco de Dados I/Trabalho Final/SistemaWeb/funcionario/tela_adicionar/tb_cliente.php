<!doctype html>
<html lang="pt-br">
    <head>
        <title> Funcionário | Tela Adicionar </title>
        <meta charset="utf-8">
        <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300&display=swap" rel="stylesheet">
        <link rel="stylesheet" href="../../css/normalize.css">
        <link rel="stylesheet" href="../../css/tela_adicionar.css">
        <link rel="icon" href="../../images/icon.png">     
    </head>
    <body>
        
        <header class="mainHeader">
            <h1 class="mainHeaderTitulo">
                Tela Adicionar<br>
                <strong>Tabela Cliente</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Cliente: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_cliente.php">
                
                    <label>Nome: </label>
                    <input placeholder="Digite aqui..." type="input" name="nome" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>E-mail: </label>
                    <input placeholder="Digite aqui..." type="input" name="email" class="botaoDefaultStroke"></input>       
                    <br>
                    <br>
                    
                    <label>Senha: </label>
                    <input placeholder="Digite aqui..." type="input" name="senha" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>
                    
                    <label>Telefone: </label>
                    <input placeholder="Digite aqui..." type="input" name="telefone" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>
                    
                    <label>Profissão: </label>
                    <input placeholder="Digite aqui..." type="input" name="profissao" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                    
                    
                    <label>Nacionalidade: </label>
                    <input placeholder="Digite aqui..." type="input" name="nacionalidade" class="botaoDefaultStroke"></input>       
                    <br>
                    <br>
                    
                    <label>Data Nascimento: </label>
                    <input type="date" name="dataNascimento" class="botaoDefaultStroke"></input>   
                    <br>
                    <br>    
                    
                    <label>Gênero: </label>
                    <select name="genero" class="botaoDefaultStroke">
                        <option>Masculino</option>   
                        <option>Feminino</option> 
                        <option>LGBTQIAP+</option> 
                        <option>Indefinido</option> 
                    </select>  
                    <br>
                    <br>  
                    
                    <label>Número Identidade: </label>
                    <input placeholder="Digite aqui..." type="input" name="numeroIdentidade" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br> 
                    
                    <label>Tipo Identidade: </label>
                    <input placeholder="Digite aqui..." type="input" name="tipoIdentidade" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>          
                    
                    <label>Orgão Expedidor: </label>
                    <input placeholder="Digite aqui..." type="input" name="orgaoExpedidorIdentidade" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>        
                    
                    <label>CPF: </label>
                    <input placeholder="Digite aqui..." type="input" name="cpf" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>               
                    
                    <label>Residência: </label>
                    <input placeholder="Digite aqui..." type="input" name="residencia" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                    
                    
                    <label>Cidade: </label>
                    <input placeholder="Digite aqui..." type="input" name="cidade" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                       
                    
                    <label>Estado: </label>
                    <select name="estado" class="botaoDefaultStroke">
                        <option>Acre</option>
                        <option>Alagoas</option>
                        <option>Amapá</option>
                        <option>Amazonas</option>
                        <option>Bahia</option>
                        <option>Ceará</option>
                        <option>Distrito Federal</option>
                        <option>Espírito Santo</option>
                        <option>Goiás</option>
                        <option>Maranhão</option>
                        <option>Mato Grosso</option>
                        <option>Mato Grosso do Sul</option>
                        <option>Minas Gerais</option>
                        <option>Pará</option>
                        <option>Paraíba</option>
                        <option>Paraná</option>
                        <option>Pernambuco</option>
                        <option>Piauí</option>
                        <option>Rio de Janeiro</option>
                        <option>Rio Grande do Norte</option>
                        <option>Rio Grande do Sul</option>
                        <option>Rondônia</option>
                        <option>Roraima</option>
                        <option>Santa Catarina</option>
                        <option>São Paulo</option>
                        <option>Sergipe</option>
                        <option>Tocantins</option>
                    </select>                   
                    <br>
                    <br>
                    
                    <label>País: </label>
                    <input placeholder="Digite aqui..." type="input" name="pais" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                         
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                    include('../../conexao.php');
                    
                    if(isset($_POST['nome']) and isset($_POST['email']) and isset($_POST['senha']) and isset($_POST['telefone']) and isset($_POST['profissao']) and isset($_POST['nacionalidade']) and isset($_POST['dataNascimento']) and isset($_POST['genero']) and isset($_POST['numeroIdentidade']) and isset($_POST['tipoIdentidade']) and isset($_POST['orgaoExpedidorIdentidade']) and isset($_POST['cpf']) and isset($_POST['residencia']) and isset($_POST['cidade']) and isset($_POST['estado']) and isset($_POST['pais'])) {
                         
                        $nome = $_POST['nome'];
                        $email = $_POST['email'];
                        $senha = $_POST['senha'];
                        $telefone = $_POST['telefone'];
                        $profissao = $_POST['profissao'];
                        $nacionalidade = $_POST['nacionalidade'];
                        $dataNascimento = $_POST['dataNascimento'];
                        $genero = $_POST['genero'];
                        $numeroIdentidade = $_POST['numeroIdentidade'];
                        $tipoIdentidade = $_POST['tipoIdentidade'];
                        $orgaoExpedidorIdentidade = $_POST['orgaoExpedidorIdentidade'];
                        $cpf = $_POST['cpf'];
                        $residencia = $_POST['residencia'];
                        $cidade = $_POST['cidade'];
                        $estado = $_POST['estado'];
                        $pais = $_POST['pais'];
    
                        mysqli_query($mysql, "
                        insert into Cliente (nome, email, senha, telefone, profissao, nacionalidade, dataNascimento, genero, numeroIdentidade, tipoIdentidade, orgaoExpedidorIdentidade, cpf, residencia, cidade, estado, pais) 
                        values ('".$nome."','".$email."',MD5('".$senha."'),'".$telefone."','".$profissao."','".$nacionalidade."','".$dataNascimento."','".$genero."','".$numeroIdentidade."','".$tipoIdentidade."','".$orgaoExpedidorIdentidade."','".$cpf."','".$residencia."','".$cidade."','".$estado."','".$pais."')") ;
                        
                        echo "<h2>Dado adicionado com sucesso!</h2>";
                    }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
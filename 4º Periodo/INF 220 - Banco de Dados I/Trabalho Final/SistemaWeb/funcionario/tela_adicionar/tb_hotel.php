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
                <strong>Tabela Hotel</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Hotel: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_hotel.php">
                
                    <label>Nome: </label>
                    <input placeholder="Digite aqui..." type="input" name="nome" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Telefone: </label>
                    <input placeholder="Digite aqui..." type="input" name="telefone" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Qntd. Quartos: </label>
                    <input placeholder="Digite aqui..." type="number" min="0" name="qntdQuartos" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>   
                    
                    <label>CEP: </label>
                    <input placeholder="Digite aqui..." type="input" name="cep" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>   
                    
                    <label>Cidade: </label>
                    <input placeholder="Digite aqui..." type="input" name="cidade" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>       
                    
                    <label>Bairro: </label>
                    <input placeholder="Digite aqui..." type="input" name="bairro" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>      
                    
                    <label>Número: </label>
                    <input placeholder="Digite aqui..." type="number" min="0" name="numero" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>      
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                    include('../../conexao.php');                
                    
                    if(isset($_POST['nome']) and isset($_POST['telefone']) and isset($_POST['qntdQuartos']) and isset($_POST['cep']) and isset($_POST['cidade']) and isset($_POST['bairro']) and isset($_POST['numero']) ) {
                         
                        $nome = $_POST['nome'];
                        $telefone = $_POST['telefone'];
                        $qntdQuartos = $_POST['qntdQuartos'];
                        $cep = $_POST['cep'];
                        $cidade = $_POST['cidade'];
                        $bairro = $_POST['bairro'];
                        $numero = $_POST['numero'];
    
                        mysqli_query($mysql, "
                        insert into Hotel (nome, telefone, qntdQuartos, cep, cidade, bairro, numero) 
                        values ('".$nome."','".$telefone."','".$qntdQuartos."','".$cep."','".$cidade."','".$bairro."','".$numero."')") ;
                        
                        echo "<h2>Dado adicionado com sucesso!</h2>";
                    }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
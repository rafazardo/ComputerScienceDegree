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
                <strong>Tabela Brinde</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Brinde: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_brinde.php">
                
                    <label>Nome: </label>
                    <input placeholder="Digite aqui..." type="input" name="nome" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Cor: </label>
                    <input placeholder="Digite aqui..." type="input" name="cor" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Fabricante: </label>
                    <input placeholder="Digite aqui..." type="input" name="fabricante" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>                    
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                    include('../../conexao.php');
                    
                    if(isset($_POST['nome']) and isset($_POST['cor']) and isset($_POST['fabricante']) ) {
                         
                        $nome = $_POST['nome'];
                        $cor = $_POST['cor'];
                        $fabricante = $_POST['fabricante'];
    
                        mysqli_query($mysql, "
                        insert into Brinde (nome, cor, fabricante) 
                        values ('".$nome."','".$cor."','".$fabricante."')") ;
                        
                        echo "<h2>Dado adicionado com sucesso!</h2>";
                    }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
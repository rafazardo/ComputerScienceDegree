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
                <strong>Tabela Consumo</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Consumo: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <?php
                    include('../../conexao.php');
                    
                    $result = mysqli_query($mysql, "select idConta from Conta order by idConta");
        
                    while ($row = mysqli_fetch_assoc($result)) {
                        $idContas[] = $row["idConta"];
                    }
                    
                    $result = mysqli_query($mysql, "select nome from Produto");    
                    
                    while ($row = mysqli_fetch_assoc($result)) {
                        $nomeProduto[] = $row["nome"];
                    }                    
                    
                ?>                
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_consumo.php">
                
                    <label>ID Conta: </label>
                    <select name="idConta" class="botaoDefaultStroke">
                        <?php foreach($idContas as $c) { ?>
                        <option><?php echo $c; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <label>Produto: </label>
                    <select name="nomeProduto" class="botaoDefaultStroke">
                        <?php foreach($nomeProduto as $p) { ?>
                        <option><?php echo $p; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <label>Qntd. do Produto: </label>
                    <input placeholder="Digite aqui..." type="numer" min="1" name="qntdDoProduto" class="botaoDefaultStroke"></input>  
                    <br>
                    <br>                    
                    
                    <label>Preço Total: </label>
                    <input placeholder="Digite aqui..." type="numer" min="1" name="precoTotal" class="botaoDefaultStroke"></input>                     
                    <br>
                    <br>
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                if(isset($_POST['idConta']) and isset($_POST['nomeProduto']) and isset($_POST['qntdDoProduto']) and isset($_POST['precoTotal']) ) {
                    
                    $qntdDoProduto = $_POST['qntdDoProduto'];
                    
                    $nomeProduto = $_POST['nomeProduto'];
                    $row1 = mysqli_query($mysql, "select idProduto from Produto where nome = '".$nomeProduto."'") or die(mysqli_error($mysql));
                    $idProduto = mysqli_fetch_assoc($row1);

                    $idConta = $_POST['idConta'];
                    $precoTotal = $_POST['precoTotal'];

                    mysqli_query($mysql, "
                    insert into Consumo (idConta, idProduto, qntdDoProduto, precoTotal) 
                    values ('".$idConta."','".$idProduto['idProduto']."','".$qntdDoProduto."','".$precoTotal."')") or die(mysqli_error($mysql));
                    
                    echo "<h2>Dado adicionado com sucesso!</h2>";
                }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
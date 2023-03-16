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
                <strong>Tabela Apartamento Arrumado</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Apartamento Arrumado: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <?php
                    include('../../conexao.php');
                    
                    $result = mysqli_query($mysql, "select nome from Funcionario");
        
                    while ($row = mysqli_fetch_assoc($result)) {
                        $funcionarios[] = $row["nome"];
                    }
                    
                    $result = mysqli_query($mysql, "select idApartamento from Apartamento order by idApartamento");    
                    
                    while ($row = mysqli_fetch_assoc($result)) {
                        $apartamentos[] = $row["idApartamento"];
                    }                    
                    
                ?>                
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_apartamento_arrumado.php">
                
                    <label>Fúncioario: </label>
                    <select name="nomeFuncionario" class="botaoDefaultStroke">
                        <?php foreach($funcionarios as $f) { ?>
                        <option><?php echo $f; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <label>ID Apartamento: </label>
                    <select name="idApartamento" class="botaoDefaultStroke">
                        <?php foreach($apartamentos as $a) { ?>
                        <option><?php echo $a; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <label>Data da Limpeza: </label>
                    <input placeholder="Digite aqui..." type="date" name="dia" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                if(isset($_POST['nomeFuncionario']) and isset($_POST['idApartamento']) and isset($_POST['dia'] )) {
                    
                    
                    $dia = $_POST['dia'];
                    
                    $nomeFuncionario = $_POST['nomeFuncionario'];
                    $row1 = mysqli_query($mysql, "select idFuncionario from Funcionario where nome = '".$nomeFuncionario."'") or die(mysqli_error($mysql));
                    $idFuncionario = mysqli_fetch_assoc($row1);

                    $idApartamento = $_POST['idApartamento'];

                    mysqli_query($mysql, "
                    insert into apartamentos_arrumados (idFuncionario, idApartamento, dia) 
                    values ('".$idFuncionario['idFuncionario']."','".$idApartamento."','".$dia."')") or die(mysqli_error($mysql));
                    
                    echo "<h2>Dado adicionado com sucesso!</h2>";
                }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
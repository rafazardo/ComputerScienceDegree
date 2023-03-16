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
                <strong>Tabela Funcionario</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Funcionário: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <?php
                    include('../../conexao.php');
                    
                    $result = mysqli_query($mysql, "select nome from Hotel");
        
                    while ($row = mysqli_fetch_assoc($result)) {
                        $hoteis[] = $row["nome"];
                    }
                    
                    $result = mysqli_query($mysql, "select nome from Cargo");    
                    
                    while ($row = mysqli_fetch_assoc($result)) {
                        $cargos[] = $row["nome"];
                    }                    
                    
                ?>                
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_funcionario.php">
                
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
                    
                    <label>Hotel: </label>
                    <select name="hotel" class="botaoDefaultStroke">
                        <?php foreach($hoteis as $h) { ?>
                        <option><?php echo $h; ?></option>
                        <?php } ?>
                    </select>
                    <br>
                    <br>
                    
                    <label>Cargo: </label>
                    <select name="cargo" class="botaoDefaultStroke">
                        <?php foreach($cargos as $c) { ?>
                        <option><?php echo $c; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                if(isset($_POST['nome']) and isset($_POST['email']) and isset($_POST['senha'] )) {
                    
                    $nome = $_POST['nome'];
                    $email = $_POST['email'];
                    $senha = $_POST['senha'];
                    
                    $nomeHotel = $_POST['hotel'];
                    $row1 = mysqli_query($mysql, "select idHotel from Hotel where nome = '".$nomeHotel."'") or die(mysqli_error($mysql));
                    $idHotel = mysqli_fetch_assoc($row1);
                    
                    $nomeCargo = $_POST['cargo'];
                    $row2 =  mysqli_query($mysql, "select idCargo from Cargo where nome = '".$nomeCargo."'") or die(mysqli_error($mysql)); 
                    $idCargo = mysqli_fetch_assoc($row2);
                    
                    mysqli_query($mysql, "
                    insert into Funcionario (nome, email, senha, idHotel, idCargo) 
                    values ('".$nome."','".$email."',MD5('".$senha."'),'".$idHotel['idHotel']."','".$idCargo['idCargo']."')") or die(mysqli_error($mysql));
                    
                    echo "<h2>Dado adicionado com sucesso!</h2>";
                }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
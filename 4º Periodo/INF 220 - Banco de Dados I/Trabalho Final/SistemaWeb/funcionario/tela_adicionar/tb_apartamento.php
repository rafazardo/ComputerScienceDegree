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
                <strong>Tabela Apartamento</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados do Apartamento: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <?php
                    include('../../conexao.php');
                    
                    $result = mysqli_query($mysql, "select nome from Hotel");
        
                    while ($row = mysqli_fetch_assoc($result)) {
                        $hoteis[] = $row["nome"];
                    }
                    
                ?>                   
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_apartamento.php">
                
                    <label>Qntd. Camas Solteiro: </label>
                    <input placeholder="Digite aqui..." type="number" min="0" name="qntdCamaSolteiro" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Qntd. Camas Casal: </label>
                    <input placeholder="Digite aqui..." type="number" min="0" name="qntdCamaCasal" class="botaoDefaultStroke"></input>    
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
                    
                    <label>Número: </label>
                    <input placeholder="Digite aqui..." type="number" min="0" name="numero" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>   
                    
                    <label>Ocupado:</label>
                    <select name="ocupado" class="botaoDefaultStroke">
                        <option>Sim</option>
                        <option>Nao</option>
                    </select>
                    <br>
                    <br>   
                    
                    <label>Dados Adicionais: </label>
                    <input type="checkbox" name="adaptado" class="botaoDefaultStroke"> Adaptado</input>  
                    <br>
                    <input type="checkbox" name="frigobar" class="botaoDefaultStroke"> Frigobar</input>
                    <br>
                    <br>                    
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                    
                    if(isset($_POST['qntdCamaSolteiro']) and isset($_POST['qntdCamaCasal']) and isset($_POST['hotel']) and isset($_POST['numero']) and isset($_POST['ocupado']) ) {
                         
                        $qntdCamaSolteiro = $_POST['qntdCamaSolteiro'];
                        $qntdCamaCasal = $_POST['qntdCamaCasal'];
                        
                        $nomeHotel = $_POST['hotel'];
                        $row1 = mysqli_query($mysql, "select idHotel from Hotel where nome = '".$nomeHotel."'") or die(mysqli_error($mysql));
                        $idHotel = mysqli_fetch_assoc($row1);                        
                        
                        $numero = $_POST['numero'];
                        if ($_POST['ocupado'] == "Sim") {
                            $ocupado = 1;
                        }
                        else {
                            $ocupado = 0;
                        }
                        
                        $adaptado = 0;
                        if (isset($_POST['adaptado'])) 
                            if($_POST['adaptado'] == "on") 
                                $adaptado = 1;
                        
                        $frigobar = 0;
                        if (isset($_POST['frigobar'])) 
                            if($_POST['frigobar'] == "on") 
                                $frigobar = 1;                        

    
                        mysqli_query($mysql, "
                        insert into Apartamento (qntdCamaSolteiro, qntdCamaCasal, adaptado, frigobar, idHotel, numero, ocupado) 
                        values ('".$qntdCamaSolteiro."','".$qntdCamaCasal."','".$adaptado."','".$frigobar."','".$idHotel['idHotel']."','".$numero."','".$ocupado."')") ;
                        
                        echo "<h2>Dado adicionado com sucesso!</h2>";
                    }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
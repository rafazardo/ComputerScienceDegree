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
                <strong>Tabela Reserva</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Preencha os dados da Reserva: </h2>
                <p>Listagem dos campos armazenados no nosso bando de dados SQL</p>
                
                <?php
                    include('../../conexao.php');
                    
                    $result = mysqli_query($mysql, "select nome from Cliente");
                    while ($row = mysqli_fetch_assoc($result)) {
                        $clientes[] = $row["nome"];
                    }                    
                    
                    $result = mysqli_query($mysql, "select idApartamento from Apartamento order by idApartamento");
                    while ($row = mysqli_fetch_assoc($result)) {
                        $idApartametos[] = $row["idApartamento"];
                    }
                    
                    $result = mysqli_query($mysql, "select idConta from Conta");    
                    while ($row = mysqli_fetch_assoc($result)) {
                        $idContas[] = $row["idConta"];
                    }               
                    
                    $result = mysqli_query($mysql, "select nome from Brinde");    
                    while ($row = mysqli_fetch_assoc($result)) {
                        $brinde[] = $row["nome"];
                    }                        
                    
                ?>                
                
                <form method="post" action="../../funcionario/tela_adicionar/tb_reserva.php">
                
                    <label>Cidade Origem: </label>
                    <input placeholder="Digite aqui..." type="text"  name="cidadeOrigem" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>   
                    
                    <label>Estado Origem: </label>
                    <input placeholder="Digite aqui..." type="text"  name="estadoOrigem" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>   
                    
                    <label>País Origem: </label>
                    <input placeholder="Digite aqui..." type="text"  name="paisOrigem" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                  
                    
                    <label>Cidade Destino: </label>
                    <input placeholder="Digite aqui..." type="text"  name="cidadeDestino" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>            
                    
                    <label>Estado Destino: </label>
                    <input placeholder="Digite aqui..." type="text"  name="estadoDestino" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>                    
                    
                    <label>País Destino: </label>
                    <input placeholder="Digite aqui..." type="text"  name="paisDestino" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>         
                    
                    <label>Motivo Hospedagem: </label>
                    <select name="motivoHospedagem" class="botaoDefaultStroke">
                        <option>Férias</option>
                        <option>Negócios</option>
                        <option>Congresso</option>
                        <option>Estudos</option>
                        <option>Saúde</option>
                        <option>Outro</option>
                    </select>
                    <br>
                    <br>  
                    
                    <label>Meio Transporte: </label>
                    <select name="meioTransporte" class="botaoDefaultStroke">
                        <option>Automóvel</option>
                        <option>Avião</option>
                        <option>Navio</option>
                        <option>Ônibus</option>
                        <option>Trem</option>
                        <option>Outro</option>
                    </select>
                    <br>
                    <br>    
                    
                    <label>Forma Pagamento: </label>
                    <select name="formaPagamento" class="botaoDefaultStroke">
                        <option>Dinheiro</option>
                        <option>Pix</option>
                        <option>Cartão de crédito</option>
                        <option>Cartão de débito</option>
                    </select>
                    <br>
                    <br>                       
                
                    <label>Data Entrada: </label>
                    <input placeholder="Digite aqui..." type="date" name="dataEntrada" class="botaoDefaultStroke"></input>    
                    <br>
                    <br>
                    
                    <label>Data Saída: </label>
                    <input placeholder="Digite aqui..." type="date" name="dataSaida" class="botaoDefaultStroke"></input>       
                    <br>
                    <br>
                    
                    <label>Número de Pessoas: </label>
                    <input placeholder="Digite aqui..." type="number" min="1" name="qntdPessoas" class="botaoDefaultStroke"></input>                    
                    <br>
                    <br>
                    
                    <label>Cliente: </label>
                    <select name="cliente" class="botaoDefaultStroke">
                        <?php foreach($clientes as $c) { ?>
                        <option><?php echo $c; ?></option>
                        <?php } ?>
                    </select>
                    <br>
                    <br>
                    
                    <label>ID Apartamento: </label>
                    <select name="apartamento" class="botaoDefaultStroke">
                        <?php foreach($idApartametos as $a) { ?>
                        <option><?php echo $a; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>
                    
                    <label>ID Conta: </label>
                    <select name="conta" class="botaoDefaultStroke">
                        <?php foreach($idContas as $c) { ?>
                        <option><?php echo $c; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>     
                    
                    <label>Brinde: </label>
                    <select name="brinde" class="botaoDefaultStroke">
                        <?php foreach($brinde as $b) { ?>
                        <option><?php echo $b; ?></option>
                        <?php } ?>
                    </select>
                    <br>  
                    <br>                    
                    
                    <input type="submit" value="Adicionar" class="botaoDefault">
                
                </form>
                
                <?php
                
                if(isset($_POST['cidadeOrigem']) and isset($_POST['estadoOrigem']) and isset($_POST['paisOrigem']) and isset($_POST['cidadeDestino']) and isset($_POST['estadoDestino']) and isset($_POST['paisDestino']) and isset($_POST['motivoHospedagem']) and isset($_POST['meioTransporte']) and isset($_POST['dataEntrada']) and isset($_POST['dataSaida']) and isset($_POST['qntdPessoas']) and isset($_POST['cliente']) and isset($_POST['apartamento']) and isset($_POST['conta']) and isset($_POST['formaPagamento']) and isset($_POST['brinde']) ) {
                    
                    $cidadeOrigem = $_POST['cidadeOrigem'];
                    $estadoOrigem = $_POST['estadoOrigem'];
                    $paisOrigem = $_POST['paisOrigem'];
                    $cidadeDestino = $_POST['cidadeDestino'];
                    $estadoDestino = $_POST['estadoDestino'];
                    $paisDestino = $_POST['paisDestino'];
                    $motivoHospedagem = $_POST['motivoHospedagem'];
                    $meioTransporte = $_POST['meioTransporte'];
                    $dataEntrada = $_POST['dataEntrada'];
                    $dataSaida = $_POST['dataSaida'];
                    $qntdPessoas = $_POST['qntdPessoas'];
                    $formaPagamento = $_POST['formaPagamento'];
                    
                    $cliente = $_POST['cliente'];
                    $row1 = mysqli_query($mysql, "select idCliente from Cliente where nome = '".$cliente."'") or die(mysqli_error($mysql));
                    $idCliente = mysqli_fetch_assoc($row1);
                    
                    $brinde = $_POST['brinde'];
                    $row1 = mysqli_query($mysql, "select idBrinde from Brinde where nome = '".$brinde."'") or die(mysqli_error($mysql));
                    $idBrinde = mysqli_fetch_assoc($row1);                    
                    
                    $idApartamento = $_POST['apartamento'];
                    $idConta = $_POST['conta'];
                    
                    mysqli_query($mysql, "
                    insert into Reserva (cidadeOrigem, estadoOrigem, paisOrigem, cidadeDestino, estadoDestino, paisDestino, motivoHospedagem, meioTransporte, dataEntrada, dataSaida, qntdPessoas, idCliente, idConta, idApartamento, formaPagamento, idBrinde) 
                    values ('".$cidadeOrigem."','".$estadoOrigem."','".$paisOrigem."', '".$cidadeDestino."', '".$estadoDestino."', '".$paisDestino."','".$motivoHospedagem."','".$meioTransporte."','".$dataEntrada."','".$dataSaida."','".$qntdPessoas."','".$idCliente['idCliente']."','".$idConta."','".$idApartamento."','".$formaPagamento."','".$idBrinde['idBrinde']."')") or die(mysqli_error($mysql));
                    
                    echo "<h2>Dado adicionado com sucesso!</h2>";
                }
                
                ?>
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
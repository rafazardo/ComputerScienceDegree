<!doctype html>
<html lang="pt-br">
    <head>
        <title> Funcionário | Tela Consulta </title>
        <meta charset="utf-8">
        <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300&display=swap" rel="stylesheet">
        <link rel="stylesheet" href="../../css/normalize.css">
        <link rel="stylesheet" href="../../css/tela_funcionario.css">
        <link rel="icon" href="../../images/icon.png">   
    </head>
    <body>
        
        <header class="mainHeader">
            <h1 class="mainHeaderTitulo">
                Tela Consulta<br>
                <strong>Tabela Reserva</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Dados Obtidos</h2>
                <p>Listagem dos dados armazenados no nosso bando de dados SQL</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Cidade Origem</th>
                            <th>Estado Origem</th>
                            <th>País Origem</th>
                            <th>Cidade Destino</th>
                            <th>Estado Destino</th>
                            <th>País Destino</th>                            
                            <th>Motivo Hospedagem</th>
                            <th>Meio Transporte</th>
                            <th>Data Entrada</th>
                            <th>Data Saída</th>
                            <th>Qntd Pessoas</th>
                            <th>Cliente</th>
                            <th>ID Conta</th>
                            <th>ID Apartamento</th>
                            <th>Forma Pagamento</th>
                            <th>Brinde</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, "
                                            select idReserva, cidadeOrigem, estadoOrigem, paisOrigem, cidadeDestino, estadoDestino, paisDestino, motivoHospedagem, meioTransporte,dataEntrada, dataSaida, qntdPessoas, Cliente.nome as nomeCliente, idConta, idApartamento, formaPagamento, Brinde.nome as nomeBrinde 
                                            from Reserva inner join Cliente on Reserva.idCliente = Cliente.idCliente inner join Brinde on Reserva.idBrinde = Brinde.idBrinde order by idReserva;");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['idReserva']}</td>
                                            <td>{$row['cidadeOrigem']}</td>
                                            <td>{$row['estadoOrigem']}</td>
                                            <td>{$row['paisOrigem']}</td>
                                            <td>{$row['cidadeDestino']}</td>
                                            <td>{$row['estadoDestino']}</td>
                                            <td>{$row['paisDestino']}</td>
                                            <td>{$row['motivoHospedagem']}</td>
                                            <td>{$row['meioTransporte']}</td>
                                            <td>{$row['dataEntrada']}</td>
                                            <td>{$row['dataSaida']}</td>
                                            <td>{$row['qntdPessoas']}</td>
                                            <td>{$row['nomeCliente']}</td>
                                            <td>{$row['idConta']}</td>
                                            <td>{$row['idApartamento']}</td>
                                            <td>{$row['formaPagamento']}</td>
                                            <td>{$row['nomeBrinde']}</td>
                                        </tr>";
                                    }
                                }       
                         ?>
                     </tbody>
                </table>                
                
                
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
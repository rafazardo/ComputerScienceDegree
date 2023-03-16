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
                <strong>Tabelas Personalizadas</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Consulta 1</h2>
                <p>Listagem do <u>nome</u> dos clientes hospedados na filial <u>Rio de Janeiro</u>, no período <u>26/02/22 a 01/03/22</u> armazenados no nosso bando de dados SQL!</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Nome</th>
                            <th>Hotel</th>
                            <th>Data Entrada</th>
                            <th>Data Saída</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, "
                                select idReserva, Cliente.nome as nomeCliente, Hotel.nome as nomeHotel, dataEntrada, dataSaida 
from Reserva inner join Apartamento on Reserva.idApartamento  = Apartamento.idApartamento 
inner join Hotel on Hotel.idHotel = Apartamento.idHotel 
inner join Cliente on Cliente.idCliente  = Reserva.idCliente 
where dataEntrada between '2022-02-26' and '2022-03-01' and dataSaida between '2022-02-26' and '2022-03-01' and Hotel.nome = 'Rio de Janeiro';");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['idReserva']}</td>
                                            <td>{$row['nomeCliente']}</td>
                                            <td>{$row['nomeHotel']}</td>
                                            <td>{$row['dataEntrada']}</td>
                                            <td>{$row['dataSaida']}</td>
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
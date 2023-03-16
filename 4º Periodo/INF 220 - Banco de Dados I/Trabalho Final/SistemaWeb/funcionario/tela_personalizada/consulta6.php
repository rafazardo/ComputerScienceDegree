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

                <h2>Consulta 6</h2>
                <p>Listagem da Filial e nome dos clientes com 5 maiores faturas; armazenados no nosso bando de dados SQL!</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>Reserva</th>
                            <th>Cliente</th>
                            <th>Hotel</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, 
                                "SELECT Reserva.idReserva as numReserva, Cliente.nome as nomeCliente, Hotel.nome as nomeHotel FROM Cliente INNER JOIN Reserva INNER JOIN Apartamento 
                                INNER JOIN Hotel INNER JOIN Conta WHERE Cliente.idCliente = Reserva.idCliente AND 
                                Apartamento.idApartamento = Reserva.idApartamento AND Apartamento.idHotel = Hotel.idHotel AND
                                Reserva.idConta = Conta.idConta ORDER BY Conta.precoTotal DESC LIMIT 5;");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['numReserva']}</td>
                                            <td>{$row['nomeCliente']}</td>
                                            <td>{$row['nomeHotel']}</td>
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
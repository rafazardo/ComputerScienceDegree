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

                <h2>Consulta 3</h2>
                <p>Listagem do <u>nome</u>, <u>hotel</u> e <u>número do quarto</u> dos clientes que consumiram “<u>RedBull</u>” em qualquer data armazenados no nosso bando de dados SQL!</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>Nome</th>
                            <th>Hotel</th>
                            <th>Numero Quarto</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, 
                                "select Cliente.nome as nomeCliente, Hotel.nome as nomeHotel, Apartamento.numero as numeroApartamento 
                                    from Consumo inner join Conta on Consumo.idConta = Conta.idConta 
                                    inner join Reserva on Reserva.idConta = Conta.idConta 
                                    inner join Apartamento on Reserva.idApartamento = Apartamento.idApartamento 
                                    inner join Hotel on Hotel.idHotel = Apartamento.idHotel 
                                    inner join Cliente on Reserva.idCliente = Cliente.idCliente 
                                    where Consumo.idProduto = 3 
                                    group by Cliente.idCliente;");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['nomeCliente']}</td>
                                            <td>{$row['nomeHotel']}</td>
                                            <td>{$row['numeroApartamento']}</td>
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
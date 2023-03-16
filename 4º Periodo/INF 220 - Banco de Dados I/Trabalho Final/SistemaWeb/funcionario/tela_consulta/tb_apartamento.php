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
                <strong>Tabela Apartamento</strong>,<br> 
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
                            <th>Camas Solteiro</th>
                            <th>Camas Casal</th>
                            <th>Adptado</th>
                            <th>Frigobar</th>
                            <th>Hotel</th>
                            <th>Numero</th>
                            <th>Ocupado</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, "
                                select idApartamento, qntdCamaSolteiro, qntdCamaCasal, adaptado, frigobar, Hotel.nome as nomeHotel, Apartamento.numero as
                                numApartamento, ocupado
                                from Apartamento inner join Hotel on Apartamento.idHotel = Hotel.idHotel order by idApartamento;
                            ;");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['idApartamento']}</td>
                                            <td>{$row['qntdCamaSolteiro']}</td>
                                            <td>{$row['qntdCamaCasal']}</td>";
                                            $adaptado;
                                            if ($row['adaptado']==1) {
                                                $adaptado="Sim";
                                            }
                                            else {
                                                $adaptado="Não";
                                            }
                                            echo "<td>{$adaptado}</td>";
                                            $frigobar;
                                            if ($row['frigobar']==1) {
                                                $frigobar="Sim";
                                            }
                                            else {
                                                $frigobar="Não";
                                            }
                                            echo "<td>{$frigobar}</td>
                                            <td>{$row['nomeHotel']}</td>
                                            <td>{$row['numApartamento']}</td>";
                                            $ocupado;
                                            if ($row['ocupado']==1) {
                                                $ocupado="Sim";
                                            }
                                            else {
                                                $ocupado="Não";
                                            }
                                            echo "<td>{$ocupado}</td>
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
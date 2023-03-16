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

                <h2>Consulta 4</h2>
                <p>Listagem do número de quartos tipo “<u>1 Cama de Casal</u>” em cada filial armazenados no nosso bando de dados SQL!</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>Hotel</th>
                            <th>Número de Quartos</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, 
                                "select Hotel.nome as nomeHotel, count(idApartamento) as contador 
                                from Hotel inner join Apartamento on Hotel.idHotel = Apartamento.idHotel 
                                where Apartamento.qntdCamaCasal = 1 
                                group by nomeHotel;
                            ");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['nomeHotel']}</td>
                                            <td>{$row['contador']}</td>
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
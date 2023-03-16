<!doctype html>
<html lang="pt-br">
    <head>
        <title> Funcionário | Tela Remover </title>
        <meta charset="utf-8">
        <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300&display=swap" rel="stylesheet">
        <link rel="stylesheet" href="../../css/normalize.css">
        <link rel="stylesheet" href="../../css/tela_remover.css">
        <link rel="icon" href="../../images/icon.png">   
    </head>
    <body>
        
        <header class="mainHeader">
            <h1 class="mainHeaderTitulo">
                Tela Remover<br>
                <strong>Tabela Apartamento</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Remover Dados</h2>
                <p>Selecione o apartamento que deseja deletar do nosso banco de dados SQL!</p>

                <form action="../../funcionario/tela_remover/tb_apartamento.php" method="post">

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
                            <th>Ocupado </th>
                            <th></th>
                        </tr>
                        </thead>

                        <tbody>        
                            <?php 
                                include('../../conexao.php');
                                    
                                $result = mysqli_query($mysql, "
                                    select idApartamento, qntdCamaSolteiro, qntdCamaCasal, adaptado, frigobar, Hotel.nome as nomeHotel, Hotel.numero as
                                    numHotel, ocupado 
                                    from Apartamento inner join Hotel on Apartamento.idHotel = Hotel.idHotel order by idApartamento;
                                ;");

                                if(isset($_POST['idApartamento'])) {
                                    $idApartamento = $_POST['idApartamento'];          
                                    mysqli_query($mysql, "
                                    delete from apartamento where idApartamento =".$idApartamento) or die(mysqli_error($mysql));
                                    header('Refresh:0');
                                }         
                                
                                

                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo " <tr>
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
                                            <td>{$row['numHotel']}</td>";
                                            $ocupado;
                                            if ($row['ocupado']==1) {
                                                $ocupado="Sim";
                                            }
                                            else {
                                                $ocupado="Não";
                                            }
                                            echo "<td>{$ocupado}</td>
                                            <td><input class='botaoDefault' type='submit' name='idApartamento' value='Deletar' onClick='this.value = {$row['idApartamento']}' ></td>
                                        </tr>";
                                    }
                                }       
                            ?> 
                        <tbody> 
                    </table>
                </form>     
            </section>
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
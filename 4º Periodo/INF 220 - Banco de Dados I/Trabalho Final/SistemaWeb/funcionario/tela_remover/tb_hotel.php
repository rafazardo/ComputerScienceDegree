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
                <strong>Tabela Hotel</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Remover Dados</h2>
                <p>Selecione o hotel que deseja deletar do nosso banco de dados SQL!</p>

                <form action="../../funcionario/tela_remover/tb_hotel.php" method="post">

                    <table class="table">
                        <thead>
                        <tr>
                            <th>ID</th>
                            <th>Nome</th>
                            <th>Telefone</th>
                            <th>CEP</th>
                            <th>Cidade</th>
                            <th>Bairro</th>
                            <th>Número</th>
                            <th></th>
                        </tr>
                        </thead>

                        <tbody>        
                            <?php 
                                include('../../conexao.php');
                                
                                $result = mysqli_query($mysql, "select * from hotel;");

                                if(isset($_POST['idHotel'])) {
                                    $idHotel = $_POST['idHotel'];          
                                    mysqli_query($mysql, "
                                    delete from Hotel where idHotel =".$idHotel) or die(mysqli_error($mysql));
                                    header('Refresh:0');
                                }        

                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo " <tr>
                                            <td>{$row['idHotel']}</td>
                                            <td>{$row['nome']}</td>
                                            <td>{$row['telefone']}</td>
                                            <td>{$row['cep']}</td>
                                            <td>{$row['cidade']}</td>
                                            <td>{$row['bairro']}</td>
                                            <td>{$row['numero']}</td>
                                            <td><input class='botaoDefault' type='submit' name='idHotel' value='Deletar' onClick='this.value = {$row['idHotel']}' ></td>
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
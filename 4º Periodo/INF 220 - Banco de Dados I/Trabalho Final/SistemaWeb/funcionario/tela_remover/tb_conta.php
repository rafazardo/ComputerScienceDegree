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
                <strong>Tabela Conta</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Remover Dados</h2>
                <p>Selecione a conta que deseja deletar do nosso banco de dados SQL!</p>

                <form action="../../funcionario/tela_remover/tb_conta.php" method="post">

                    <table class="table">
                        <thead>
                        <tr>
                            <th>ID</th>
                            <th>Preço Total</th>
                            <th></th>
                        </tr>
                        </thead>

                        <tbody>        
                            <?php 
                                include('../../conexao.php');
                                
                                $result = mysqli_query($mysql, "select * from conta;");

                                if(isset($_POST['idConta'])) {
                                    $idConta = $_POST['idConta'];          
                                    mysqli_query($mysql, "
                                    delete from Conta where idConta =".$idConta) or die(mysqli_error($mysql));
                                    header('Refresh:0');
                                }        

                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo " <tr>
                                            <td>{$row['idConta']}</td>
                                            <td>{$row['precoTotal']}</td>
                                            <td><input class='botaoDefault' type='submit' name='idConta' value='Deletar' onClick='this.value = {$row['idConta']}' ></td>
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
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
                <strong>Tabela Apartamento Arrumdo</strong>,<br> 
                <br>
                <a href="../../funcionario/tela_inicial.php" class="mainHeaderLink">Voltar</a>
                <br>
                <a href="../../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Remover Dados</h2>
                <p>Selecione o apartamento arrumado que deseja deletar do nosso banco de dados SQL!</p>

                <form action="../../funcionario/tela_remover/tb_apartamento_arrumado.php" method="post">

                    <table class="table">
                        <thead>
                        <tr>
                            <th>Funcionário</th>
                            <th>Apartamento</th>
                            <th>Dia</th>
                            <th></th>
                        </tr>
                        </thead>

                        <tbody>        
                            <?php 
                                include('../../conexao.php');
                                    
                                $result = mysqli_query($mysql, 
                                    "select Funcionario.nome as nomeFuncionario, idApartamento, dia 
                                    from apartamentos_arrumados inner join funcionario on apartamentos_arrumados.idFuncionario = Funcionario.idFuncionario;
                                ");

                                if(isset($_POST['idApartamento'])) {
                                    $idApartamento = $_POST['idApartamento'];          
                                    mysqli_query($mysql, "
                                    delete from apartamento where idApartamento =".$idApartamento) or die(mysqli_error($mysql));
                                    header('Refresh:0');
                                }         
                                
                                

                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo " <tr>
                                            <td>{$row['nomeFuncionario']}</td>
                                            <td>{$row['idApartamento']}</td>
                                            <td>{$row['dia']}</td>
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
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

                <h2>Consulta 2</h2>
                <p>Listagem do <u>nome</u> das faxineiras que limparam o <u>quarto 401</u>, na filial <u>Rio de Janeiro</u>, no período <u>26/02/2022 a
01/03/22</u> armazenados no nosso bando de dados SQL!</p>
                
                
                <table class="table">
                    <thead>
                        <tr>
                            <th>Funcionário</th>
                            <th>Apartamento</th>
                            <th>Dia</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql, 
                                "select Funcionario.nome as nomeFuncionario, idApartamento, dia 
                                from apartamentos_arrumados inner join funcionario on apartamentos_arrumados.idFuncionario = Funcionario.idFuncionario 
                                where dia between '2022-02-26' and '2022-03-01';
                            ");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['nomeFuncionario']}</td>
                                            <td>{$row['idApartamento']}</td>
                                            <td>{$row['dia']}</td>
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
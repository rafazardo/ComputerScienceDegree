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
                <strong>Tabela Consumo</strong>,<br> 
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
                            <th>ID Conta</th>
                            <th>Nome</th>
                            <th>Quantidade</th>
                            <th>Preço Total</th>
                        </tr>
                     </thead>
                     <tbody>
                         <?php 
                            include('../../conexao.php');
                
                            $result = mysqli_query($mysql,"
                                select idConta, Produto.nome as produtoNome, qntdDoProduto, Consumo.precoTotal as consumoTotal
                                from Consumo inner join Produto on Consumo.idProduto = Produto.idProduto;
                            ");
                                
                                if (mysqli_num_rows($result)) {
                                    while ($row = mysqli_fetch_array($result)) {
                                        echo "<tr>
                                            <td>{$row['idConta']}</td>
                                            <td>{$row['produtoNome']}</td>
                                            <td>{$row['qntdDoProduto']}</td>
                                            <td>{$row['consumoTotal']}</td>
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
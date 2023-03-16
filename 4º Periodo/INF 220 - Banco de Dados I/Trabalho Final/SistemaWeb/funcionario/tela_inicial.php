<?php

    session_start();
    
    if (!isset($_SESSION['idFuncionario']) && isset($_SESSION['nome'])) {
        header("Location:http://15.204.135.205/index.html");
        exit();
    }

?>


<!doctype html>
<html lang="pt-br">
    <head>
        <title> Funcionário | Tela Inicial </title>
        <meta charset="utf-8">
        <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300&display=swap" rel="stylesheet">
        <link rel="stylesheet" href="../css/normalize.css">
        <link rel="stylesheet" href="../css/tela_funcionario.css">
        <link rel="icon" href="../images/icon.png">   
    </head>
    <body>
        
        <header class="mainHeader">
            <h1 class="mainHeaderTitulo">
                Bem vindo!<br>
                <strong><?php echo $_SESSION['nome']; ?></strong>,<br> 
                <br>
                <a href="../index.html" class="mainHeaderLink">Sair da Seção</a>
            </h1>            
        </header>
        
        <main class="mainContent">
            
            <section class="mainContentSection">

                <h2>Tabela Funcionário</h2>
                <p>Modifique, insira ou delete da Tabela de Funcionários do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_funcionario.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Funcionário</a>
                <a href="../funcionario/tela_remover/tb_funcionario.php" title="Veja mais" class="botaoDefaultStroke">Remover Funcionário</a>
                <a href="../funcionario/tela_consulta/tb_funcionario.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>


            <section class="mainContentSection">

                <h2>Tabela Cliente</h2>
                <p>Modifique, insira ou delete da Tabela de Clientes do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_cliente.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Cliente</a>
                <a href="../funcionario/tela_remover/tb_cliente.php" title="Veja mais" class="botaoDefaultStroke">Remover Cliente</a>
                <a href="../funcionario/tela_consulta/tb_cliente.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>            

            <section class="mainContentSection">

                <h2>Tabela Reserva</h2>
                <p>Modifique, insira ou delete da Tabela de Reservas do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_reserva.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Reserva</a>
                <a href="../funcionario/tela_remover/tb_reserva.php" title="Veja mais" class="botaoDefaultStroke">Remover Reserva</a>
                <a href="../funcionario/tela_consulta/tb_reserva.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>             
            
            <section class="mainContentSection">

                <h2>Tabela Apartamento</h2>
                <p>Modifique, insira ou delete da Tabela de Apartamentos do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_apartamento.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Apartamento</a>
                <a href="../funcionario/tela_remover/tb_apartamento.php" title="Veja mais" class="botaoDefaultStroke">Remover Apartamento</a>
                <a href="../funcionario/tela_consulta/tb_apartamento.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>          
            
            <section class="mainContentSection">

                <h2>Tabela Hotel</h2>
                <p>Modifique, insira ou delete da Tabela de Hotels do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_hotel.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Hotel</a>
                <a href="../funcionario/tela_remover/tb_hotel.php" title="Veja mais" class="botaoDefaultStroke">Remover Hotel</a>
                <a href="../funcionario/tela_consulta/tb_hotel.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>      
            
            <section class="mainContentSection">

                <h2>Tabela Apartamento Arrumado</h2>
                <p>Modifique, insira ou delete da Tabela de Apartamento Arrumados do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_apartamento_arrumado.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Ap. Arrumado</a>
                <a href="../funcionario/tela_remover/tb_apartamento_arrumado.php" title="Veja mais" class="botaoDefaultStroke">Remover Ap. Arrumado</a>
                <a href="../funcionario/tela_consulta/tb_apartamento_arrumado.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>             
            
            <section class="mainContentSection">
 
                <h2>Tabela Cargo</h2>
                <p>Modifique, insira ou delete da Tabela de Cargos do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_cargo.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Cargo</a>
                <a href="../funcionario/tela_remover/tb_cargo.php" title="Veja mais" class="botaoDefaultStroke">Remover Cargo</a>
                <a href="../funcionario/tela_consulta/tb_cargo.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>            
            
            <section class="mainContentSection">
 
                <h2>Tabela Conta</h2>
                <p>Modifique, insira ou delete da Tabela de Contas do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_conta.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Conta</a>
                <a href="../funcionario/tela_remover/tb_conta.php" title="Veja mais" class="botaoDefaultStroke">Remover Conta</a>
                <a href="../funcionario/tela_consulta/tb_conta.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>            

            <section class="mainContentSection">
 
                <h2>Tabela Consumo</h2>
                <p>Modifique, insira ou delete da Tabela de Consumos do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_consumo.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Consumo</a>
                <a href="../funcionario/tela_remover/tb_consumo.php" title="Veja mais" class="botaoDefaultStroke">Remover Consumo</a>
                <a href="../funcionario/tela_consulta/tb_consumo.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>            

            <section class="mainContentSection">
 
                <h2>Tabela Produto</h2>
                <p>Modifique, insira ou delete da Tabela de Produtos do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_produto.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Produto</a>
                <a href="../funcionario/tela_remover/tb_produto.php" title="Veja mais" class="botaoDefaultStroke">Remover Produto</a>
                <a href="../funcionario/tela_consulta/tb_produto.php" title="Veja mais" class="botaoDefaultStroke">Consultar Tabela</a>
                
            </section>    
            
            <section class="mainContentSection">
 
                <h2>Tabela Brinde</h2>
                <p>Modifique, insira ou delete da Tabela de Brindes do nosso banco de dados SQL!</p>
                
                <a href="../funcionario/tela_adicionar/tb_brinde.php" title="Veja mais" class="botaoDefaultStroke">Adicionar Brinde</a>
                <a href="../funcionario/tela_remover/tb_brinde.php" title="Veja mais" class="botaoDefaultStroke">Remover Brinde</a>
                <a href="../funcionario/tela_consulta/tb_brinde.php" title="Veja mais" class="botaoDefaultStroke">Consultar Brinde</a>
                
            </section>               
            
            <section class="mainContentSection">
 
                <h2>Consultas Personalizadas</h2>
                <p>Lista de consultas personalizadas do sistema Hoteis Bom Sono!</p>
                
                <a href="../funcionario/tela_personalizada/consulta1.php" title="Veja mais" class="botaoDefaultStroke">Consulta 1</a>
                <a href="../funcionario/tela_personalizada/consulta2.php" title="Veja mais" class="botaoDefaultStroke">Consulta 2</a>  
                <a href="../funcionario/tela_personalizada/consulta3.php" title="Veja mais" class="botaoDefaultStroke">Consulta 3</a>  
                <a href="../funcionario/tela_personalizada/consulta4.php" title="Veja mais" class="botaoDefaultStroke">Consulta 4</a>        
                <a href="../funcionario/tela_personalizada/consulta5.php" title="Veja mais" class="botaoDefaultStroke">Consulta 5</a>
                <a href="../funcionario/tela_personalizada/consulta6.php" title="Veja mais" class="botaoDefaultStroke">Consulta 6</a>       
                <a href="../funcionario/tela_personalizada/consulta7.php" title="Veja mais" class="botaoDefaultStroke">Consulta 7</a>                
            </section>             
        </main>

        <footer class="mainFooter"></footer>
        
    </body>
</html>
-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Tempo de geração: 13/01/2023 às 04:54
-- Versão do servidor: 8.0.24
-- Versão do PHP: 8.0.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `hoteisbomsono`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `apartamento`
--

CREATE TABLE `apartamento` (
  `idApartamento` int NOT NULL,
  `qntdCamaSolteiro` int NOT NULL,
  `qntdCamaCasal` int NOT NULL,
  `numero` int NOT NULL,
  `ocupado` tinyint(1) DEFAULT NULL,
  `adaptado` tinyint(1) DEFAULT NULL,
  `frigobar` tinyint(1) DEFAULT NULL,
  `idHotel` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `apartamento`
--

INSERT INTO `apartamento` (`idApartamento`, `qntdCamaSolteiro`, `qntdCamaCasal`, `numero`, `ocupado`, `adaptado`, `frigobar`, `idHotel`) VALUES
(3, 1, 1, 202, 0, 0, 1, 7),
(4, 2, 2, 401, 0, 0, 1, 7),
(5, 2, 1, 802, 1, 0, 1, 8),
(6, 2, 1, 803, 1, 0, 1, 8);

-- --------------------------------------------------------

--
-- Estrutura para tabela `apartamentos_arrumados`
--

CREATE TABLE `apartamentos_arrumados` (
  `idFuncionario` int NOT NULL,
  `idApartamento` int NOT NULL,
  `dia` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `apartamentos_arrumados`
--

INSERT INTO `apartamentos_arrumados` (`idFuncionario`, `idApartamento`, `dia`) VALUES
(4, 4, '2022-02-26'),
(5, 4, '2022-03-01'),
(6, 4, '2022-02-28'),
(7, 4, '2022-02-27');

-- --------------------------------------------------------

--
-- Estrutura para tabela `brinde`
--

CREATE TABLE `brinde` (
  `idBrinde` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `cor` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `fabricante` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `brinde`
--

INSERT INTO `brinde` (`idBrinde`, `nome`, `cor`, `fabricante`) VALUES
(2, 'Chaveiro 2 Hoteis', 'Branco', 'Chaveiros SA'),
(3, 'Camisa Hotel Delivery', 'Azul Marinho', 'Camisetas Bom Gosto'),
(4, 'Garrafa Termina BomSono', 'Azul', 'Pets S.A'),
(5, 'Boneca Customizada', 'Rosa', 'Bonekinhas Company'),
(6, 'Caneca Personalizada', 'Verde', 'Canecas SA');

-- --------------------------------------------------------

--
-- Estrutura para tabela `cargo`
--

CREATE TABLE `cargo` (
  `idCargo` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `salario` float DEFAULT NULL,
  `comissao` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `cargo`
--

INSERT INTO `cargo` (`idCargo`, `nome`, `salario`, `comissao`) VALUES
(4, 'Faxineira', 1980, 0),
(5, 'Catador de Lixo', 1200, 0),
(6, 'Analista de Banco de Dados', 7500, 0),
(7, 'Limpador de Piscina', 3000, 0),
(8, 'Garçom', 3000, 0),
(9, 'Cozinheiro', 5000, 0),
(10, 'Cantor', 4000, 5);

-- --------------------------------------------------------

--
-- Estrutura para tabela `cliente`
--

CREATE TABLE `cliente` (
  `idCliente` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `email` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `senha` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `telefone` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `profissao` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `nacionalidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `dataNascimento` date DEFAULT NULL,
  `genero` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `numeroIdentidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `tipoIdentidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `orgaoExpedidorIdentidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `cpf` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `residencia` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `cidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `estado` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `pais` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `cliente`
--

INSERT INTO `cliente` (`idCliente`, `nome`, `email`, `senha`, `telefone`, `profissao`, `nacionalidade`, `dataNascimento`, `genero`, `numeroIdentidade`, `tipoIdentidade`, `orgaoExpedidorIdentidade`, `cpf`, `residencia`, `cidade`, `estado`, `pais`) VALUES
(12, 'Carol Sales', 'carolsales4118@aol.ca', 'e8d95a51f3af4a3b134bf6bb680a213a', '50 53155-0531', 'Advogado', 'Brasileiro', '1987-08-29', 'Feminino', '7352717', 'Carteira de identidade', 'Polícia Civil', '950.201.580-02', 'Rua boa', 'Carapicuíba', 'São Paulo', 'Brasil'),
(13, 'McKenzie Lima', 'mckenzielima@hotmail.org', 'e8d95a51f3af4a3b134bf6bb680a213a', '68 21505-4056', 'Pintor', 'Brasileiro', '1990-09-15', 'Feminino', '2782845', 'Carteira de identidade', 'Polícia Civil', '197.542.314-07', 'Rua Presidente Salles', 'Belém', 'Pará', 'Brasil'),
(14, 'Callie Cunha', 'calliecunha7381@hotmail.com', 'e8d95a51f3af4a3b134bf6bb680a213a', '27 57012-2436', 'Zelador', 'Brasileiro', '2002-09-21', 'Masculino', '7707236', 'RG', 'SSP', '412.058.529-22', 'Rua boa', 'Aparecida de Goiânia', 'Goiás', 'Brasil'),
(15, 'Macon Diniz', 'macondiniz@google.couk', 'e8d95a51f3af4a3b134bf6bb680a213a', '24 77138-1122', 'Programador', 'Brasileiro', '1978-02-24', 'Feminino', '5264677', 'Carteira de identidade', 'Polícia Civil', '955.503.746-88', 'Rua boa', 'Recife', 'Pernambuco', 'Brasil'),
(16, 'Colt Rosa', 'coltrosa2390@google.couk', 'e8d95a51f3af4a3b134bf6bb680a213a', '47 81637-3852', 'Programador', 'Brasileiro', '1993-06-28', 'Feminino', '8719606', 'Carteira de identidade', 'Polícia Civil', '137.743.731-17', 'Rua Presidente Salles', 'Águas Lindas de Goiás', 'Goiás', 'Brasil'),
(17, 'Rafael Zardo', 'rafael.zardo@outlook.com', '9135d8523ad3da99d8a4eb83afac13d1', '28 99983-7469', 'Estudante', 'Brasileiro', '2003-04-08', 'Masculino', '1234567', 'Carteira de Identidade', 'Policia Civil', '158.205.927-60', 'Condominio Via Campus', 'Vicosa', 'Minas Gerais', 'Brasil'),
(18, 'Michael Menezes', 'michaelmenezes@outlook.ca', 'e8d95a51f3af4a3b134bf6bb680a213a', '84 77811-8095', 'Professor', 'Brasileiro', '1970-12-22', 'Feminino', '1372578', 'RG', 'SSP', '213.661.757-82', 'Rua Pedro Álvarez', 'Montes Claros', 'Minas Gerais', 'Brasil'),
(19, 'Shelley Mendes', 'shelleymendes@icloud.couk', 'e8d95a51f3af4a3b134bf6bb680a213a', '82 93728-8226', 'Agricultor', 'Brasileiro', '1974-10-29', 'Feminino', '8583226', 'RG', 'Polícia Civil', '412.411.482-81', 'Rua do limoeiro', 'Cascavel', 'Paraná', 'Brasil'),
(20, 'Pedro Fiorio', 'pedro.fiorio@outlook.com', 'c6cc8094c2dc07b700ffcc36d64e2138', '28 99983-4587', 'Estudante', 'Brasileiro', '2002-06-05', 'Indefinido', '5647892', 'RG', 'Catedral Brasileira', '256.448.789-45', 'Santa Monica', 'Vicosa', 'Minas Gerais', 'Brasil'),
(22, 'Thiago ', 'thiago@gmail.com', '8c278462dc2f486dd9697edc17eff391', '31 98412-3000', 'Professor', 'Brasileiro', '1998-06-19', 'Masculino', '98566020', 'RG', 'Polícia Civil', '126.317.566-06', 'Rua PH Holfs, 560', 'Viçosa', 'Acre', 'Brasil');

-- --------------------------------------------------------

--
-- Estrutura para tabela `consumo`
--

CREATE TABLE `consumo` (
  `idConta` int NOT NULL,
  `idProduto` int NOT NULL,
  `qntdDoProduto` int DEFAULT NULL,
  `precoTotal` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `consumo`
--

INSERT INTO `consumo` (`idConta`, `idProduto`, `qntdDoProduto`, `precoTotal`) VALUES
(11, 3, 1, 5),
(24, 3, 1, 5),
(24, 10, 2, 28);

--
-- Gatilhos `consumo`
--
DELIMITER $$
CREATE TRIGGER `contConsumoTotal` AFTER INSERT ON `consumo` FOR EACH ROW BEGIN
    UPDATE Conta SET precoTotal = precoTotal + NEW.precoTotal WHERE idConta = NEW.idConta;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `contConsumoTotalSub` BEFORE DELETE ON `consumo` FOR EACH ROW BEGIN
    UPDATE Conta SET precoTotal = precoTotal - OLD.precoTotal WHERE idConta = OLD.idConta;
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `conta`
--

CREATE TABLE `conta` (
  `idConta` int NOT NULL,
  `precoTotal` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `conta`
--

INSERT INTO `conta` (`idConta`, `precoTotal`) VALUES
(5, 0),
(11, 5),
(14, 0),
(15, 0),
(16, 0),
(17, 0),
(18, 0),
(19, 0),
(20, 0),
(21, 0),
(22, 0),
(23, 0),
(24, 33),
(25, 0);

-- --------------------------------------------------------

--
-- Estrutura para tabela `funcionario`
--

CREATE TABLE `funcionario` (
  `idFuncionario` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `email` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `senha` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `idCargo` int DEFAULT NULL,
  `idHotel` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `funcionario`
--

INSERT INTO `funcionario` (`idFuncionario`, `nome`, `email`, `senha`, `idCargo`, `idHotel`) VALUES
(4, 'Marceline Pauli', 'marcelipaulii@outlook.com', '81abf7fc4d66f9ca9a54890663d70b8d', 4, 7),
(5, 'Lorenna Vogas Queiroz', 'lorenna.queiroz@geradornv.com.br', '575155c1e97938759774e30c5d0421c8', 4, 7),
(6, 'Vivian Miranda Carino', 'vivian.carino@geradornv.com.br', '631e550691f4a72590d903582d7e2060', 4, 7),
(7, 'Suellem Alfradique Carneiro', 'suellem.carneiro@geradornv.com.br', '1bbab1284ffe562abb58d1e8f9827ec5', 4, 7),
(9, 'Vitor Souza', 'vitor@gmail.com', '997d13b90da22b35ce43bebdd332ad11', 4, 7),
(10, 'Pedro Fiofio', 'pedro@gmail.com', 'c6cc8094c2dc07b700ffcc36d64e2138', 4, 8),
(11, 'Raquel Alves Giacomini', 'raquel.giacomini@geradornv.com.br', '080bcdc90c5be1974b07419dff162cec', 4, 8),
(12, 'Rafael Zardo', 'rafael.zardo@outlook.com', '9135d8523ad3da99d8a4eb83afac13d1', 6, 8);

-- --------------------------------------------------------

--
-- Estrutura para tabela `hotel`
--

CREATE TABLE `hotel` (
  `idHotel` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `telefone` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `qntdQuartos` int DEFAULT NULL,
  `cep` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `cidade` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `bairro` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `numero` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `hotel`
--

INSERT INTO `hotel` (`idHotel`, `nome`, `telefone`, `qntdQuartos`, `cep`, `cidade`, `bairro`, `numero`) VALUES
(7, 'Rio de Janeiro', '21 20653-9422', 60, '22630-012', 'Rio de Janeiro', 'Barra da Tijuca', 4400),
(8, 'Porto Alegre', '27 30453-9112', 60, '91260-000', 'Porto Alegre', 'Morro Santana', 5800),
(9, 'Guarujá', '51 99976-0938', NULL, '36570-073', 'Viçosa', 'Santo Antonio', 303);

-- --------------------------------------------------------

--
-- Estrutura para tabela `produto`
--

CREATE TABLE `produto` (
  `idProduto` int NOT NULL,
  `nome` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `preco` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `produto`
--

INSERT INTO `produto` (`idProduto`, `nome`, `preco`) VALUES
(1, 'Espumante Chandon Rose 750', 120),
(3, 'RedBull', 5),
(4, 'Almoço', 15),
(5, 'Lanche', 6),
(6, 'Cafe Expresso', 11),
(7, 'Jantar', 18),
(8, 'Cerveja Skol', 14),
(10, 'Refrigerante Coca-Cola', 14),
(11, 'Refrigerante H2oH Limoneto', 16),
(12, 'Refrigerante Guaraná', 17),
(13, 'Chips Doritos', 7),
(14, 'Chips Fandangos', 9),
(15, 'Cerveja Skol Beats', 12),
(16, 'Prato de Churrasco', 34);

-- --------------------------------------------------------

--
-- Estrutura para tabela `reserva`
--

CREATE TABLE `reserva` (
  `idReserva` int NOT NULL,
  `cidadeOrigem` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `estadoOrigem` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `paisOrigem` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `cidadeDestino` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `estadoDestino` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `paisDestino` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `motivoHospedagem` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `meioTransporte` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `dataEntrada` date DEFAULT NULL,
  `dataSaida` date DEFAULT NULL,
  `qntdPessoas` int DEFAULT NULL,
  `idCliente` int DEFAULT NULL,
  `idConta` int DEFAULT NULL,
  `idApartamento` int DEFAULT NULL,
  `formaPagamento` varchar(100) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `idBrinde` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `reserva`
--

INSERT INTO `reserva` (`idReserva`, `cidadeOrigem`, `estadoOrigem`, `paisOrigem`, `cidadeDestino`, `estadoDestino`, `paisDestino`, `motivoHospedagem`, `meioTransporte`, `dataEntrada`, `dataSaida`, `qntdPessoas`, `idCliente`, `idConta`, `idApartamento`, `formaPagamento`, `idBrinde`) VALUES
(19, 'Vicosa', 'Minas Gerais', 'Brasil', 'Alegre', 'Espírito Santo', 'Brasil', 'Férias', 'Avião', '2022-12-16', '0022-12-20', 2, 20, 20, 3, 'Pix', 3),
(20, 'Vicosa', 'Minas Gerais', 'Brasil', 'Viçosa', 'Minas Gerais', 'Brasil', 'Férias', 'Trem', '2023-01-02', '2023-01-08', 2, 20, 21, 5, 'Cartão de débito', 3),
(21, 'Vicosa', 'Minas Gerais', 'Brasil', 'São Paulo', 'São Paulo', 'Brasil', 'Congresso', 'Automóvel', '2023-06-15', '2023-06-22', 1, 20, 22, 4, 'Cartão de débito', 2),
(22, 'Castelo', 'Espirito Santo', 'Brasil', 'Cachoeiro', 'Espirito Santo', 'Brasil', 'Férias', 'Automóvel', '2022-04-08', '2022-04-09', 3, 20, 11, 3, 'Dinheiro', 2),
(23, 'Viçosa', 'Acre', 'Brasil', 'Rio de Janeiro', 'Rio de Janeiro', 'Brasil', 'Férias', 'Automóvel', '2022-12-22', '2022-12-27', 1, 22, 24, 4, 'Pix', 4),
(24, 'Vicosa', 'Minas Gerais', 'Brasil', 'a', 'a', 'a', 'Férias', 'Automóvel', '4292-08-09', '9292-02-29', 2, 20, 25, 3, 'Dinheiro', 5);

--
-- Gatilhos `reserva`
--
DELIMITER $$
CREATE TRIGGER `criarConta` AFTER INSERT ON `reserva` FOR EACH ROW BEGIN
    insert into conta (precoTotal) values (0);
END
$$
DELIMITER ;

--
-- Índices de tabelas apagadas
--

--
-- Índices de tabela `apartamento`
--
ALTER TABLE `apartamento`
  ADD PRIMARY KEY (`idApartamento`),
  ADD KEY `fkIdHotelApartamento` (`idHotel`);

--
-- Índices de tabela `apartamentos_arrumados`
--
ALTER TABLE `apartamentos_arrumados`
  ADD PRIMARY KEY (`idFuncionario`,`idApartamento`),
  ADD KEY `fkIdApartamentoArrumados` (`idApartamento`);

--
-- Índices de tabela `brinde`
--
ALTER TABLE `brinde`
  ADD PRIMARY KEY (`idBrinde`);

--
-- Índices de tabela `cargo`
--
ALTER TABLE `cargo`
  ADD PRIMARY KEY (`idCargo`);

--
-- Índices de tabela `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`idCliente`);

--
-- Índices de tabela `consumo`
--
ALTER TABLE `consumo`
  ADD PRIMARY KEY (`idConta`,`idProduto`),
  ADD KEY `fkIdProduto` (`idProduto`);

--
-- Índices de tabela `conta`
--
ALTER TABLE `conta`
  ADD PRIMARY KEY (`idConta`);

--
-- Índices de tabela `funcionario`
--
ALTER TABLE `funcionario`
  ADD PRIMARY KEY (`idFuncionario`),
  ADD KEY `fkIdCargo` (`idCargo`),
  ADD KEY `fkIdHotel` (`idHotel`);

--
-- Índices de tabela `hotel`
--
ALTER TABLE `hotel`
  ADD PRIMARY KEY (`idHotel`);

--
-- Índices de tabela `produto`
--
ALTER TABLE `produto`
  ADD PRIMARY KEY (`idProduto`);

--
-- Índices de tabela `reserva`
--
ALTER TABLE `reserva`
  ADD PRIMARY KEY (`idReserva`),
  ADD KEY `fkIdCliente` (`idCliente`),
  ADD KEY `fkIdConta` (`idConta`),
  ADD KEY `fkIdApartamento` (`idApartamento`),
  ADD KEY `fkIdBrinde` (`idBrinde`);

--
-- AUTO_INCREMENT de tabelas apagadas
--

--
-- AUTO_INCREMENT de tabela `apartamento`
--
ALTER TABLE `apartamento`
  MODIFY `idApartamento` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `brinde`
--
ALTER TABLE `brinde`
  MODIFY `idBrinde` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `cargo`
--
ALTER TABLE `cargo`
  MODIFY `idCargo` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de tabela `cliente`
--
ALTER TABLE `cliente`
  MODIFY `idCliente` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT de tabela `conta`
--
ALTER TABLE `conta`
  MODIFY `idConta` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT de tabela `funcionario`
--
ALTER TABLE `funcionario`
  MODIFY `idFuncionario` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT de tabela `hotel`
--
ALTER TABLE `hotel`
  MODIFY `idHotel` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT de tabela `produto`
--
ALTER TABLE `produto`
  MODIFY `idProduto` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT de tabela `reserva`
--
ALTER TABLE `reserva`
  MODIFY `idReserva` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- Restrições para dumps de tabelas
--

--
-- Restrições para tabelas `apartamento`
--
ALTER TABLE `apartamento`
  ADD CONSTRAINT `fkIdHotelApartamento` FOREIGN KEY (`idHotel`) REFERENCES `hotel` (`idHotel`) ON DELETE CASCADE;

--
-- Restrições para tabelas `apartamentos_arrumados`
--
ALTER TABLE `apartamentos_arrumados`
  ADD CONSTRAINT `fkIdApartamentoArrumados` FOREIGN KEY (`idApartamento`) REFERENCES `apartamento` (`idApartamento`) ON DELETE CASCADE,
  ADD CONSTRAINT `fkIdFuncionario` FOREIGN KEY (`idFuncionario`) REFERENCES `funcionario` (`idFuncionario`) ON DELETE CASCADE;

--
-- Restrições para tabelas `consumo`
--
ALTER TABLE `consumo`
  ADD CONSTRAINT `fkIdContaConsumo` FOREIGN KEY (`idConta`) REFERENCES `conta` (`idConta`) ON DELETE CASCADE,
  ADD CONSTRAINT `fkIdProduto` FOREIGN KEY (`idProduto`) REFERENCES `produto` (`idProduto`) ON DELETE CASCADE;

--
-- Restrições para tabelas `funcionario`
--
ALTER TABLE `funcionario`
  ADD CONSTRAINT `fkIdCargo` FOREIGN KEY (`idCargo`) REFERENCES `cargo` (`idCargo`) ON DELETE CASCADE,
  ADD CONSTRAINT `fkIdHotel` FOREIGN KEY (`idHotel`) REFERENCES `hotel` (`idHotel`) ON DELETE CASCADE;

--
-- Restrições para tabelas `reserva`
--
ALTER TABLE `reserva`
  ADD CONSTRAINT `fkIdApartamento` FOREIGN KEY (`idApartamento`) REFERENCES `apartamento` (`idApartamento`) ON DELETE CASCADE,
  ADD CONSTRAINT `fkIdBrinde` FOREIGN KEY (`idBrinde`) REFERENCES `brinde` (`idBrinde`),
  ADD CONSTRAINT `fkIdCliente` FOREIGN KEY (`idCliente`) REFERENCES `cliente` (`idCliente`) ON DELETE CASCADE,
  ADD CONSTRAINT `fkIdConta` FOREIGN KEY (`idConta`) REFERENCES `conta` (`idConta`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

/*
MySql
- Exercicio 1 INF 220 - Banco de Dados
- Objetivos: Treinar comandos da lingaguagem MySql
- Criado por Rafael Zardo em 06/11/2022
*/

-- Modelo Logico do BD:
-- Companhia(c-nome, CNPJ, cidade, ramoAtiv)
-- Empregado(e-nome, sexo, cidade, chefe*)
--  chefe referencia Empregado.e-nome
-- Trabalha(c-nome*, e-nome*, salário)
--  c-nome referencia Companhia.c-nome
--  e-nome referencia Empregado.e-nome

-- Definindo a base de dados
CREATE DATABASE EMPREGADOS;
USE EMPREGADOS; 

-- Definindo as tabelas
CREATE TABLE COMPANHIA (compNome VARCHAR(100) NOT NULL PRIMARY KEY, CNPJ INT, cidade VARCHAR(100), ramoAtiv VARCHAR(100));

CREATE TABLE EMPREGADO (empNome VARCHAR(100) NOT NULL PRIMARY KEY, sexo VARCHAR(100), cidade VARCHAR(100), chefe VARCHAR(100), 
FOREIGN KEY (chefe) REFERENCES EMPREGADO (empNome) ON DELETE CASCADE);

CREATE TABLE TRABALHA (compNome VARCHAR(100), empNome VARCHAR(100), PRIMARY KEY (compNome, empNome), salario INT,
FOREIGN KEY (compNome) REFERENCES COMPANHIA (compNome) ON DELETE CASCADE, FOREIGN KEY (empNome) REFERENCES EMPREGADO (empNome) ON DELETE CASCADE); 

-- Alimentando tabela com dados 
INSERT INTO COMPANHIA VALUES ('UFV', 1457895, 'Vicosa', 'Escolar'); 
INSERT INTO COMPANHIA VALUES ('Beleaf', 17895, 'Sao Paulo', 'Tecnologia');
INSERT INTO COMPANHIA VALUES ('SoTrampo', 7895, 'China', 'Qualquer Coisa');
INSERT INTO COMPANHIA VALUES ('Bicos Temporarios S.A', 7895, 'Afeganistao', 'Bicos');

INSERT INTO EMPREGADO VALUES ('Salles', 'Masculino', 'Vicosa', 'Salles');
INSERT INTO EMPREGADO VALUES ('Thiago', 'Masculino', 'Vicosa', 'Salles');
INSERT INTO EMPREGADO VALUES ('Rafael', 'Masculino', 'Vicosa', 'Thiago');
INSERT INTO EMPREGADO VALUES ('Keila', 'Feminino', 'Sao Paulo', 'Keila');
INSERT INTO EMPREGADO VALUES ('Pedro', 'Masculino', 'Rio de Janeiro', 'Thiago');
INSERT INTO EMPREGADO VALUES ('Fabio', 'Masculino', 'Santa Catarina', 'Rafael');
INSERT INTO EMPREGADO VALUES ('Jose Silva', 'Masculino', 'Pernambuco', 'Jose Silva');
INSERT INTO EMPREGADO VALUES ('Andre', 'Masculino', 'Pernambuco', 'Andre');
INSERT INTO EMPREGADO VALUES ('Kaique', 'Masculino', 'Pernambuco', 'Jose Silva');

INSERT INTO TRABALHA VALUES ('UFV', 'Salles', 150000);
INSERT INTO TRABALHA VALUES ('UFV', 'Thiago', 14000);
INSERT INTO TRABALHA VALUES ('Beleaf', 'Rafael', 1500);
INSERT INTO TRABALHA VALUES ('Beleaf', 'Keila', 7000);
INSERT INTO TRABALHA VALUES ('SoTrampo', 'Pedro', 1600);
INSERT INTO TRABALHA VALUES ('SoTrampo', 'Jose Silva', 210);
INSERT INTO TRABALHA VALUES ('SoTrampo', 'Andre', 500);
INSERT INTO TRABALHA VALUES ('SoTrampo', 'Kaique', 1600);
INSERT INTO TRABALHA VALUES ('Bicos Temporarios S.A', 'Fabio', 1600);

-- Consultas e alteracoes
-- Exercicio A) Liste os nomes de todos os empregados que trabalham para a “SóTrampo”.
SELECT empNome 
FROM TRABALHA 
WHERE compNome = 'SoTrampo';

-- Exercicio B) Nomes e cidades de residência de todos os empregados da “SóTrampo”.
SELECT TRABALHA.empNome, cidade 
FROM EMPREGADO INNER JOIN TRABALHA ON EMPREGADO.empNome = TRABALHA.empNome 
WHERE compNome = 'SoTrampo';

-- Exercicio C) Nome, sexo e cidade de todos os empregados que trabalham na “SóTrampo” e ganham mais de R$380,00.
SELECT TRABALHA.empNome, sexo, cidade 
FROM EMPREGADO INNER JOIN TRABALHA ON EMPREGADO.empNome = TRABALHA.empNome 
WHERE compNome = 'SoTrampo' and salario > 380;

-- Exercicio D) Encontre todos os empregados que moram e trabalham na mesma cidade.
SELECT EMPREGADO.empNome, sexo, EMPREGADO.cidade, chefe
FROM TRABALHA INNER JOIN EMPREGADO ON TRABALHA.empNome = EMPREGADO.empNome INNER JOIN COMPANHIA ON TRABALHA.compNome = COMPANHIA.compNome 
WHERE COMPANHIA.cidade = EMPREGADO.cidade;

-- Exercicio E) Encontre todos os empregados que moram na mesma cidade de seu gerente.
SELECT EMPREGADO.empNome, EMPREGADO.sexo, EMPREGADO.cidade, EMPREGADO.chefe 
FROM EMPREGADO, (SELECT * FROM EMPREGADO WHERE empNome = chefe) GERENTES 
WHERE EMPREGADO.cidade = GERENTES.cidade and EMPREGADO.empNome != GERENTES.empNome;

-- Exercicio F) Liste os empregados que não trabalham na “SóTrampo”.
SELECT EMPREGADO.empNome, sexo, cidade, chefe 
FROM EMPREGADO INNER JOIN TRABALHA ON EMPREGADO.empNome = TRABALHA.empNome 
WHERE compNome != 'SoTrampo';

-- Exercicio G) Liste o número de empregados de cada Companhia.
SELECT COMPANHIA.compNome, COUNT(empNome) AS qntdEmp
FROM TRABALHA INNER JOIN COMPANHIA ON TRABALHA.compNome = COMPANHIA.compNome
GROUP BY compNome;

-- Exercicio H) Qual companhia possui o maior número de empregados?
SELECT ANY_VALUE(compNome) AS maiorComp, MAX(qntdEmp) AS qntdEmp
FROM (SELECT COMPANHIA.compNome, COUNT(empNome) AS qntdEmp FROM TRABALHA INNER JOIN COMPANHIA ON TRABALHA.compNome = COMPANHIA.compNome 
GROUP BY compNome) EMPREGADOS;

-- Exercicio I) Altere o BD para informar que o “José da Silva” mudou-se para Viçosa.
CREATE TRIGGER seMudou BEFORE UPDATE ON EMPREGADO FOR EACH ROW SET @cidade = NEW.cidade, @empNome = NEW.empNome;

SELECT @empNome AS Empregado, @cidade AS 'Se mudou Para';

UPDATE EMPREGADO 
SET cidade = 'Sao Paulo'
WHERE empNome = 'Rafael'; 

-- Exercicio J) Adicione R$15,00 ao salário de todos os empregados da “SóTrampo”.
UPDATE TRABALHA 
SET salario = salario + 15 
WHERE compNome = 'SoTrampo';

-- Exercicio K) Adicione R$30,00 ao salário de todos os gerentes da “SóTrampo”.
UPDATE TRABALHA INNER JOIN EMPREGADO ON TRABALHA.empNome = EMPREGADO.empNome
SET salario = salario + 30
WHERE TRABALHA.empNome = chefe and compNome = 'SoTrampo';

-- Exercicio L) Elimine todos os contratos de trabalho da empresa “Bicos Temporários S.A.”.
DELETE FROM TRABALHA
WHERE compNome = 'Bicos Temporarios S.A';

-- Exercicio M) Especifique a visão (EquipeZeSilva) na qual o gerente “José da Silva” só terá acesso aos dados (incluindo salário) de seus subordinados.
CREATE VIEW EquipeZeSilva AS
SELECT EMPREGADO.empNome, EMPREGADO.sexo, EMPREGADO.cidade, EMPREGADO.chefe, salario
FROM TRABALHA INNER JOIN EMPREGADO ON TRABALHA.empNome = EMPREGADO.empNome
WHERE EMPREGADO.empNome != chefe and chefe = 'Jose Silva';

-- Exercicio N) Elimine a visão EquipeZeSilva.
DROP VIEW EquipeZeSilva;

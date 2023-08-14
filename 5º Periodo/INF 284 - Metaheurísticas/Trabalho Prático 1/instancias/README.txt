Formato do arquivo de coordenadas (tspp):
linha 1: n, o número de cidades
Próximas n linhas: i x y, sendo i um contador de 1 a n e (x,y) a coordenada da cidade i

Formato arquivo de multas (txt):
linha 1: n, o número de cidades
próximas n linhas: matriz n x n, as multas (a_ij = multa paga na cidade i se for a j-ésima da rota)

arquivos zero.txt: sem multa (problema = TSP)
arquivos cedo.txt: algumas cidades preferem atendimento cedo (multa nas últimas posições)
arquivos mix.txt:  algumas cidades preferem atendimento cedo e outras preferem tarde (multa nas últimas ou nas primeiras posições)  

Obs.: arquivos .tsp são os originais da TSPLIB, mas no trabalho podem usar os .tspp
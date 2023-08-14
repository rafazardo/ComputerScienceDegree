plot-tspp.py arq.tspp [arq.rota]
# plota as cidades, a rota e o custo da rota
# arq.tspp é o arquivo com as coordenadas das cidades (entrada do TSPP)
# arq.rota (opcional) é uma rota (lista de inteiros) - se nao for fornecido, plota uma rota sequencial

Ex:
python3 plot-tspp.py berlin52.tspp
python3 plot-tspp.py berlin52.tspp berlin52.rota

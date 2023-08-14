import matplotlib.pyplot as plt
import math
import sys

# Função para calcular o custo da rota (sem as multas!)
def calculate_cost(route, coords):
    cost = 0
    for i in range(len(route)-1):
        city1 = coords[route[i]-1]
        city2 = coords[route[i+1]-1]
        dist = math.sqrt((city1[0]-city2[0])**2 + (city1[1]-city2[1])**2)
        cost += int(dist+0.5)   # round
    city1 = coords[route[-1]-1]
    city2 = coords[route[0]-1]
    dist = math.sqrt((city1[0]-city2[0])**2 + (city1[1]-city2[1])**2)
    cost += int(dist+0.5)   # round
    return round(cost)

# Arquivos de entrada
if len(sys.argv) < 2:
    print("Informe o arquivo de coordenadas na linha de comando (opcionalmente o de rota).")
    sys.exit(1)

arq_coords = sys.argv[1]

# Ler as coordenadas
with open(arq_coords, 'r') as f:
    n = int(f.readline().strip()) # Número de cidades
    coords = []
    for i in range(n):
        line = f.readline().strip().split()
        coords.append((float(line[1]), float(line[2])))

# Ler a rota
if len(sys.argv) > 2:
    arq_route = sys.argv[2]
    with open(arq_route, 'r') as f:
        route_str = f.readline().strip().split()
    route = [int(i) for i in route_str]
# ou gerar uma sequencial
else:
    route = list(range(1, n+1))

# Calcular custo da rota
cost = calculate_cost(route, coords)

# plotar as cidades e a rota
x, y = zip(*coords)
plt.scatter(x, y)
for i, coord in enumerate(coords):
    plt.annotate(str(i+1), xy=coord, xytext=(5, 5), textcoords='offset points')
x_ordered = [x[i-1] for i in route]
y_ordered = [y[i-1] for i in route]
x_ordered.append(x[route[0]-1])
y_ordered.append(y[route[0]-1])
plt.plot(x_ordered, y_ordered)
plt.title(f"Cost = {cost:.2f}")

plt.show()

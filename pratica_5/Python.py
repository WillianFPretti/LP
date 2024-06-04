def men_cam(matriz, origem, destino):
    # Definindo o valor para infinito
    Inf = 9999
    
    # Inicializando listas de distâncias e visitados
    distancias = [Inf] * len(matriz)
    visitados = [False] * len(matriz)
    
    # A distância da origem para ela mesma é zero
    distancias[origem] = 0
    
    # Encontrar o menor caminho
    for _ in range(len(matriz)):
        # Encontrar o vértice não visitado mais próximo da origem
        min_dist = Inf
        for i in range(len(matriz)):
            if distancias[i] < min_dist and not visitados[i]:
                min_dist = distancias[i]
                u = i
        
        # Marcar o vértice como visitado
        visitados[u] = True
        
        # Atualizar as distâncias dos vértices adjacentes
        for v in range(len(matriz)):
            if not visitados[v] and matriz[u][v] != Inf:
                distancias[v] = min(distancias[v], distancias[u] + matriz[u][v])
    
    # Retorna a distância mínima do nó origem para o nó destino
    return distancias[destino]

# Exemplo de uso:
origem = 0  # Vértice de origem
destino = 8  # Vértice de destino
print("Distância mínima entre os nós {} e {}: {}".format(origem, destino, men_cam))

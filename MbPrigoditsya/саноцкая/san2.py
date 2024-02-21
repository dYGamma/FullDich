def floyd_warshall(graph):
    vertices = list(graph.keys())
    num_vertices = len(vertices)

    # Инициализация матрицы расстояний
    distances = [[float('infinity')] * num_vertices for _ in range(num_vertices)]
    for i in range(num_vertices):
        distances[i][i] = 0
        for neighbor, weight in graph[i + 1].items():
            distances[i][neighbor - 1] = weight

    # Алгоритм Флойда-Уоршелла
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if distances[i][k] + distances[k][j] < distances[i][j]:
                    distances[i][j] = distances[i][k] + distances[k][j]

    return distances

# Ваш граф
graph = {
    1: {2: 125, 3: 105},
    2: {1: 125, 3: 135, 4: 75},
    3: {1: 105, 2: 135, 4: 80, 5: 140},
    4: {2: 75, 3: 80, 5: 110},
    5: {3: 140, 4: 110}
}

shortest_distances_floyd_warshall = floyd_warshall(graph)
print("Floyd-Warshall Shortest Distances:")
for row in shortest_distances_floyd_warshall:
    print(row)

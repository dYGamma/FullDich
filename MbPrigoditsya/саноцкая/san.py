import heapq

def dijkstra(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Ваш граф
graph = {
    1: {2: 125, 3: 105},
    2: {1: 125, 3: 135, 4: 75},
    3: {1: 105, 2: 135, 4: 80, 5: 140},
    4: {2: 75, 3: 80, 5: 110},
    5: {3: 140, 4: 110}
}

start_vertex = 1
shortest_distances_dijkstra = dijkstra(graph, start_vertex)
print("Dijkstra's Shortest Distances:", shortest_distances_dijkstra)

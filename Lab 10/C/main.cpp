#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::pair<long long int, std::pair<long long int, long long int>>> edges;
std::vector<std::pair<long long int, std::pair<long long int, long long int>>> MST;
std::vector<long long int> vertices;

long long int find_set(long long int cur_vertex) {
    bool found = vertices[cur_vertex] == cur_vertex;
    if (found) {
        return cur_vertex;
    }

    else {
        return vertices[cur_vertex] = find_set(vertices[cur_vertex]);
    }
}

void unite_sets(long long int vertex_1, long long int vertex_2) {
    if (find_set(vertex_1) != find_set(vertex_2)) vertices[find_set(vertex_2)] = find_set(vertex_1);
}

void Kruskal(long long int num_of_vertices, long long int num_of_edges) {
    for (int i = 0; i < num_of_edges; ++i) {
        auto min_edge = edges[i];
        if (find_set(min_edge.second.first) != find_set(min_edge.second.second)) {
            unite_sets(min_edge.second.first, min_edge.second.second);
            MST.push_back(min_edge);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    vertices.resize(N + 1);
    int vertex_1, vertex_2, weight;
    for (int i = 0; i < M; ++i) {
        std::cin >> vertex_1 >> vertex_2 >> weight;
        edges.push_back(std::make_pair(weight, std::make_pair(vertex_1, vertex_2)));
    }

    std::sort(edges.begin(), edges.end());
    for (int i = 0; i < N; ++i) vertices[i] = i;

    Kruskal(N, M);
    long long int summary = 0;
    for (auto i = MST.begin(); i != MST.end(); ++i) {
        summary += i -> first;
    }

    std::cout << summary << std::endl;
    return 0;
}
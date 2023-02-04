#include <iostream>
#include <vector>

enum Part {
    none,
    first,
    second
};

int N = 0, M = 0;
bool flag = true;
std::vector<std::vector<int>> adjacency_list;
std::vector<int> vertices;
std::vector<Part> parts;

Part get_part(int vertex_index) {
    return parts[vertex_index];
}

void visit(int current_vertex) {
    for (int j = 0; j < adjacency_list[current_vertex].size(); j++) {
        if (get_part(adjacency_list[current_vertex][j]) == none) {
            if (get_part(current_vertex) == first) {
                parts[adjacency_list[current_vertex][j]] = second;
            }

            if (get_part(current_vertex) == second) {
                parts[adjacency_list[current_vertex][j]] = first;
            }

            visit(adjacency_list[current_vertex][j]);
        }

        if (get_part(current_vertex) == get_part(adjacency_list[current_vertex][j])) flag = false;
    }
}

void DFS() {
    for (int i = 0; i < N; i++) {
        if (parts[i] == none) {
            parts[i] = first;
            visit(vertices[i]);
        }
    }
}

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    std::cin >> N;
    std::cin >> M;
    adjacency_list.resize(N);
    vertices.resize(N);
    parts.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
        adjacency_list[vertex_2 - 1].push_back(vertex_1 - 1);
    }

    for (int i = 0; i < N; i++) {
        vertices[i] = i;
        parts[i] = none;
    }

    DFS();
    if (flag) {
        std::cout << "YES" << std::endl;
    }

    else std::cout << "NO" << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
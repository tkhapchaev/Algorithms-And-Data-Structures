#include <iostream>
#include <vector>
#include <stack>

enum Colour {
    white,
    gray,
    black
};

int N = 0, M = 0;
std::vector<std::vector<int>> adjacency_list;
std::stack<int> sorted_vertices;
std::vector<Colour> colours;
std::vector<int> vertices;
std::vector<int> result;

Colour get_colour(int vertex_index) {
    return colours[vertex_index];
}

void visit(int current_vertex) {
    colours[current_vertex] = gray;
    for (int j = 0; j < adjacency_list[current_vertex].size(); j++) {
        if (get_colour(adjacency_list[current_vertex][j]) == white) {
            visit(adjacency_list[current_vertex][j]);
        }
    }

    colours[current_vertex] = black;
    sorted_vertices.push(vertices[current_vertex]);
}

void topological_sort() {
    for (int i = 0; i < N; i++) {
        if (get_colour(i) == white) {
            visit(vertices[i]);
        }
    }
}

bool find_hamiltonian_path() {
    for (int i = 0; i < result.size() - 1; i++) {
        bool path = false;
        for (int j = 0; j < adjacency_list[result[i]].size(); j++) {
            if (adjacency_list[result[i]][j] == result[i + 1]) path = true;
        }

        if (!path) return false;
    }

    return true;
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    std::cin >> N >> M;
    adjacency_list.resize(N);
    vertices.resize(N);
    colours.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
    }

    for (int i = 0; i < N; i++) {
        vertices[i] = i;
        colours[i] = white;
    }

    topological_sort();
    for (int i = 0; i < N; i++) {
        result.push_back(sorted_vertices.top());
        sorted_vertices.pop();
    }

    if (find_hamiltonian_path()) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
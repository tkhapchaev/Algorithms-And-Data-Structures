#include <iostream>
#include <vector>

enum Colour {
    white,
    gray,
    black
};

int N = 0, M = 0;
std::vector<std::vector<int>> adjacency_list;
std::vector<Colour> colours;
std::vector<int> components;
std::vector<int> vertices;

Colour get_colour(int vertex_index) {
    return colours[vertex_index];
}

void visit(int current_vertex, int current_components_num) {
    colours[current_vertex] = gray;
    components[current_vertex] = current_components_num;
    for (int j = 0; j < adjacency_list[current_vertex].size(); j++) {
        if (colours[adjacency_list[current_vertex][j]] == white) {
            visit(adjacency_list[current_vertex][j], current_components_num);
        }
    }

    colours[current_vertex] = black;
}

int DFS() {
    int components_counter = 0;
    for (int i = 0; i < N; i++) {
        if (get_colour(i) == white) {
            visit(vertices[i], components_counter);
            ++components_counter;
        }
    }

    return components_counter;
}

int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    std::cin >> N;
    std::cin >> M;
    adjacency_list.resize(N);
    components.resize(N);
    vertices.resize(N);
    colours.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
        adjacency_list[vertex_2 - 1].push_back(vertex_1 - 1);
    }

    for (int i = 0; i < N; i++) {
        vertices[i] = i;
        colours[i] = white;
    }

    std::cout << DFS() << std::endl;
    for (int j = 0; j < N; j++) {
        std::cout << components[j] + 1 << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
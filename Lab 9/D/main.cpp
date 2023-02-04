#include <iostream>
#include <vector>
#include <stack>

enum Colour {
    white,
    gray,
    black
};

int N = 0, M = 0;
std::vector<std::vector<int>> adjacency_list_inverted;
std::vector<std::vector<int>> adjacency_list;
std::stack<int> sorted_vertices;
std::vector<int> components;
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

void visit_inverted(int current_vertex, int current_components_num) {
    colours[current_vertex] = gray;
    components[current_vertex] = current_components_num;
    for (int j = 0; j < adjacency_list_inverted[current_vertex].size(); j++) {
        if (get_colour(adjacency_list_inverted[current_vertex][j]) == white) {
            visit_inverted(adjacency_list_inverted[current_vertex][j], current_components_num);
        }
    }

    colours[current_vertex] = black;
}

int DFS() {
    int components_counter = 0;
    for (int i = 0; i < N; i++) {
        if (get_colour(result[i]) == white) {
            components_counter++;
            visit_inverted(result[i], components_counter);
        }
    }

    return components_counter;
}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    std::cin >> N >> M;
    adjacency_list_inverted.resize(N);
    adjacency_list.resize(N);
    components.resize(N);
    vertices.resize(N);
    colours.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
        adjacency_list_inverted[vertex_2 - 1].push_back(vertex_1 - 1);
    }

    for (int i = 0; i < N; i++) {
        vertices[i] = i;
        colours[i] = white;
    }

    topological_sort();
    for (int i = 0; i < N; i++) {
        colours[i] = white;
        result.push_back(sorted_vertices.top());
        sorted_vertices.pop();
    }

    std::cout << DFS() << std::endl;
    for (int j = 0; j < N; j++) {
        std::cout << components[j] << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
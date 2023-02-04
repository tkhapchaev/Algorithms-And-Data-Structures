#include <iostream>
#include <vector>
#include <stack>

enum Colour {
    white,
    gray,
    black
};

int N = 0, M = 0;
bool flag = true;
std::vector<std::vector<int>> adjacency_list;
std::vector<Colour> colours;
std::vector<int> vertices;
std::stack<int> sorted_vertices;

Colour get_colour(int vertex_index) {
    return colours[vertex_index];
}

void visit(int current_vertex) {
    colours[current_vertex] = gray;
    for (int j = 0; j < adjacency_list[current_vertex].size(); j++) {
        if (get_colour(adjacency_list[current_vertex][j]) == white) {
            visit(adjacency_list[current_vertex][j]);
        }

        else if (get_colour(adjacency_list[current_vertex][j]) == gray) {
            flag = false;
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

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    std::cin >> N;
    std::cin >> M;
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
    if (flag) {
        for (int i = 0; i < N; i++) {
            std::cout << sorted_vertices.top() + 1 << " ";
            sorted_vertices.pop();
        }
    }

    else std::cout << -1 << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
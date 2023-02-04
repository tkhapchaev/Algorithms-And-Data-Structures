#include <iostream>
#include <vector>

enum Colour {
    white,
    gray,
    black
};

bool cycle_flag = false;
int N = 0, M = 0, cycle_start = 0, cycle_end = 0;
std::vector<std::vector<int>> adjacency_list;
std::vector<Colour> colours;
std::vector<int> vertices;
std::vector<int> result;
std::vector<int> cycle;

Colour get_colour(int vertex_index) {
    return colours[vertex_index];
}

void visit(int current_vertex) {
    colours[current_vertex] = gray;
    cycle.push_back(current_vertex);
    for (int j = 0; j < adjacency_list[current_vertex].size(); j++) {
        if (get_colour(adjacency_list[current_vertex][j]) == white) {
            visit(adjacency_list[current_vertex][j]);
        }

        if (get_colour(adjacency_list[current_vertex][j]) == gray) {
            cycle_start = adjacency_list[current_vertex][j];
            cycle_end = current_vertex;
            cycle_flag = true;
            result = cycle;
        }
    }

    colours[current_vertex] = black;
    cycle.pop_back();
}

void DFS() {
    for (int i = 0; i < N; i++) {
        if (get_colour(i) == white) {
            visit(vertices[i]);
        }
    }
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    std::cin >> N;
    std::cin >> M;
    colours.resize(N);
    vertices.resize(N);
    adjacency_list.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
    }

    for (int i = 0; i < N; i++) {
        vertices[i] = i;
        colours[i] = white;
    }

    DFS();
    if (cycle_flag) {
        std::cout << "YES" << std::endl;
        int start_index = 0, end_index = 0;
        std::vector<int> output;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == cycle_start) start_index = i;
            if (result[i] == cycle_end) end_index = i;
        }

        for (int i = start_index; i <= end_index; i++) {
           output.push_back(result[i] + 1);
        }

        for (int i = 0; i < output.size(); i++) std::cout << output[i] << " ";
    }

    else std::cout << "NO" << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
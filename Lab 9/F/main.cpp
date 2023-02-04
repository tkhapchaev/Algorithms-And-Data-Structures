#include <iostream>
#include <vector>
#include <queue>

enum Colour {
    white,
    black
};

int N = 0, M = 0, start = 0;
std::vector<std::vector<int>> adjacency_list;
std::vector<int> distances;
std::vector<Colour> colour;

void BFS(int starting_vertex) {
    std::queue<int> queue;
    queue.push(starting_vertex);
    distances[starting_vertex] = 0;
    colour[starting_vertex] = black;
    while (queue.size() != 0) {
        int cur_vertex = queue.front(), next_vertex;
        queue.pop();
        for (int i = 0; i < adjacency_list[cur_vertex].size(); i++) {
            next_vertex = adjacency_list[cur_vertex][i];
            if (colour[next_vertex] == white) {
                queue.push(next_vertex);
                colour[next_vertex] = black;
                distances[next_vertex] = distances[cur_vertex] + 1;
            }
        }
    }
}

void who_is_winner() {
    std::vector<int> vertex_degree;
    vertex_degree.resize(N);
    int min_distance = 1000000;
    for (int i = 0; i < vertex_degree.size(); i++) {
        vertex_degree[i] = adjacency_list[i].size();
    }

    for (int i = 0; i < distances.size(); i++) {
        if (distances[i] < min_distance && distances[i] != 0 && vertex_degree[i] == 0 && colour[i] == black) {
            min_distance = distances[i];
        }
    }

    if (min_distance % 2 == 0) std::cout << "Second player wins" << std::endl;
    if (min_distance % 2 == 1) std::cout << "First player wins" << std::endl;
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    std::cin >> N >> M >> start;
    adjacency_list.resize(N);
    distances.resize(N);
    colour.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
    }

    for (int i = 0; i < N; i++) {
        colour[i] = white;
    }

    BFS(start - 1);
    who_is_winner();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
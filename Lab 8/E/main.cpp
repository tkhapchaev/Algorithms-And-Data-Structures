#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector<std::vector<int>> adjacency_list;

void BFS() {
    std::vector<int> is_passed (N, false), distances (N, -1);
    std::queue<int> queue;
    queue.push(0);
    distances[0] = 0;
    is_passed[0] = true;
    while (queue.size() != 0) {
        int cur_vertex = queue.front(), next_vertex;
        queue.pop();
        for (int i = 0; i < adjacency_list[cur_vertex].size(); i++) {
            next_vertex = adjacency_list[cur_vertex][i];
            if (is_passed[next_vertex] == false) {
                queue.push(next_vertex);
                is_passed[next_vertex] = true;
                distances[next_vertex] = distances[cur_vertex] + 1;
            }
        }
    }

    for (int j = 0; j < distances.size(); j++) std::cout << distances[j] << " ";
}

int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    std::cin >> N;
    std::cin >> M;
    adjacency_list.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
        adjacency_list[vertex_2 - 1].push_back(vertex_1 - 1);
    }

    BFS();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N = 0, M = 0; std::cin >> N >> M;
    std::vector<std::vector<int>> adjacency_list;
    adjacency_list.resize(N);
    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
        adjacency_list[vertex_2 - 1].push_back(vertex_1 - 1);
    }

    for (int i = 0; i < N; i++) {
        std::cout << adjacency_list[i].size() << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
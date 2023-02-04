#include <iostream>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; std::cin >> N;
    int M; std::cin >> M;
    std::vector<std::vector<int>> adjacency_matrix;
    adjacency_matrix.resize(N);
    for(int i = 0; i < N; i++) {
        adjacency_matrix[i].resize(N);
    }

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    int vertex_1, vertex_2;
    for (int i = 0; i < M; i++) {
        std::cin >> vertex_1 >> vertex_2;
        adjacency_matrix[vertex_1 - 1][vertex_2 - 1] += 1;
        adjacency_matrix[vertex_2 - 1][vertex_1 - 1] += 1;
    }

    bool flag = false;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjacency_matrix[i][j] == adjacency_matrix[j][i]) {
                if (adjacency_matrix[i][j] != 1 && adjacency_matrix[i][j] != 0) flag = true;
            }
        }
    }

    if (flag) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    fclose(stdout);
    return 0;
}
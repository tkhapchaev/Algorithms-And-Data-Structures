#include <iostream>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; std::cin >> N;
    std::vector<std::vector<int>> adjacency_matrix;
    adjacency_matrix.resize(N);
    for(int i = 0; i < N; i++) {
        adjacency_matrix[i].resize(N);
    }

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> adjacency_matrix[i][j];
        }
    }

    bool flag = true;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjacency_matrix[i][j] == 1) {
                if (i != j && adjacency_matrix[j][i] == 0) flag = false;
                if (i == j) flag = false;
            }
        }
    }

    if (flag) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    fclose(stdout);
    return 0;
}
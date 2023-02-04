#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adjacency_matrix;

void Floyd_Warshall(int num_of_vertices) {
    for (int i = 0; i < num_of_vertices; ++i) {
        for (int j = 0; j < num_of_vertices; ++j) {
            for (int k = 0; k < num_of_vertices; ++k) {
                if (adjacency_matrix[j][i] + adjacency_matrix[i][k] < adjacency_matrix[j][k]) {
                    adjacency_matrix[j][k] = adjacency_matrix[j][i] + adjacency_matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < num_of_vertices; ++i) {
        for (int j = 0; j < num_of_vertices; ++j) {
            if (i != j) cout << adjacency_matrix[i][j] << " ";
            else cout << 0 << " ";
        }

        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    adjacency_matrix.resize(N);
    for (auto &i: adjacency_matrix) i.resize(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            adjacency_matrix[i][j] = 1000000;
        }
    }

    for (int i = 0; i < M; ++i) {
        int vertex_1, vertex_2, weight;
        cin >> vertex_1 >> vertex_2 >> weight;
        adjacency_matrix[vertex_1 - 1][vertex_2 - 1] = weight;
    }

    Floyd_Warshall(N);
    return 0;
}
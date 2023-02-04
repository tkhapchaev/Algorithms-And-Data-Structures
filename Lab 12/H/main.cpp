#include <iostream>
#include <vector>

#define MODULE static_cast<long long>(1e9)

void init(int N, std::vector<std::vector<long long>>& D, std::vector<long long>& shirts) {
    D.resize(N);
    shirts.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> shirts[i];
        D[i].resize(N);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                D[i][j] = 1;
            }

            else D[i][j] = 0;
        }
    }
}

#define RESULT D[0][N - 1]

void get_result(int N, std::vector<std::vector<long long>>& D, std::vector<long long>& shirts) {
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j + i < N; ++j) {
            if (shirts[j] == shirts[j + i]) {
                long long temp = D[j + 1][j + i] + D[j][j + i - 1];
                D[j][j + i] = (temp + 1) % MODULE;
            }

            else {
                long long temp = D[j + 1][j + i] + D[j][j + i - 1];
                long long counter = D[j + 1][j + i - 1];
                D[j][j + i] = (temp - counter + MODULE) % MODULE;
            }
        }
    }

    std::cout << RESULT % MODULE;
}

int main() {
    std::vector<std::vector<long long>> D;
    std::vector<long long> shirts;
    int N; std::cin >> N;
    init(N, D, shirts);
    get_result(N, D, shirts);
}
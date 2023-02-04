#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> D;

//[ [ noreturn ] ] void get_result(int i, int j) {

void get_result(int i, int j) {
    ++D[i][j];
    if (j <= M - 3 && i > 0) {
        get_result(i - 1, j + 2);
    }

    if (j <= M - 3 && i <= N - 2) {
        get_result(i + 1, j + 2);
    }

    if (i <= N - 3 && j <= M - 2) {
        get_result(i + 2, j + 1);
    }

    if (i <= N - 3 && j > 0) {
        get_result(i + 2, j - 1);
    }

    else return ;
}

void init() {
    D.resize(N);
    for (auto& it: D) {
        it.resize(M);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            D[i][j] = 0;
        }
    }

    D[0][0] = 1;
}

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    cin >> N >> M;
    init();
    get_result(0, 0);
    cout << D[N - 1][M - 1];
}
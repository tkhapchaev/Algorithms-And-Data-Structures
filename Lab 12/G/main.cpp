#include <iostream>
#include <vector>

#define MAX_SIZE 100001

using namespace std;

int i, k, S, cur_weight, N;
vector<int> D, weights;

void init() {
    cin >> S >> N;
    weights.resize(N);
    D.resize(MAX_SIZE);

    for (int j = 0; j < N; ++j) {
        cin >> weights[j];
    }

    D[0] = 1;
    k = D[0];
}

void get_result(int counter) {
    for (int j = 0; j < N; ++j) {
        cur_weight = weights[j];
        for (i = S; i >= cur_weight; --i) {
            bool flag = false;
            if (D[i - cur_weight] == 1) {
                flag = true;
            }

            if (flag) {
                D[i] = 1;
                k = i;
            }
        }
    }

    i = S;
    int answer;
    while (true) {
        if (D[i] > 0) {
            answer = i;
            break;
        }

        --i;
    }

    cout << answer;
}

int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    init();
    get_result(k);
}
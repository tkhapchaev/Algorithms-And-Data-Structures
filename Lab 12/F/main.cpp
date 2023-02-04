#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> D;
vector<int> weight;

void mark_vertex(int vertex) {
    // if (D[vertex][0] != NULL && D[vertex][1] != NULL) {
    D[vertex][0] = 0;
    D[vertex][1] = weight[vertex];
}

void get_result(int vertex) {
    mark_vertex(vertex);
    for (auto& it: graph[vertex]) {
        get_result(it);
        if (D[it][0] >= D[it][1]) {
            D[vertex][0] += D[it][0];
        }

        else {
            D[vertex][0] += D[it][1];
        }

        D[vertex][1] += D[it][0];
    }
}

int main() {
    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);
    int N, vertex, root;
    cin >> N; graph.resize(N);
    weight.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> vertex >> weight[i];
        if (vertex == 0) {
            root = i;
        }

        else graph[vertex - 1].push_back(i);
    }

    D.resize(N);
    for (auto& i: D) i.resize(2);
    get_result(root);

    int answer;
    if (D[root][0] >= D[root][1]) {
        answer = D[root][0];
    }

    else answer = D[root][1];

    cout << answer;
}
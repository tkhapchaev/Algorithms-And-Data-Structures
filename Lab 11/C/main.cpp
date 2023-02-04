#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, pair<int, int>>> edges;

void Bellman_Ford(int num_of_vertices, int num_of_edges) {
    vector<int> distances (num_of_vertices, INT_MAX);
    distances[0] = 0;
    for (int i = 0; i < num_of_vertices - 1; ++i) {
        bool relaxed = false;
        for (int j = 0; j < num_of_edges * 2; ++j) {
            if (distances[edges[j].second.first] != INT_MAX) {
                if (distances[edges[j].second.second] > distances[edges[j].second.first] + edges[j].first) {
                    distances[edges[j].second.second] = distances[edges[j].second.first] + edges[j].first;
                    relaxed = true;
                }
            }
        }

        if (!relaxed) break;
    }

    for (auto &i: distances) cout << i << " ";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int vertex_1, vertex_2, weight;
        cin >> vertex_1 >> vertex_2 >> weight;
        edges.push_back(make_pair(weight, make_pair(vertex_1 - 1, vertex_2 - 1)));
        edges.push_back(make_pair(weight, make_pair(vertex_2 - 1, vertex_1 - 1)));
    }

    Bellman_Ford(N, M);
    return 0;
}
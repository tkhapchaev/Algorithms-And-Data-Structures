#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<long long, pair<int, int>>> edges;

void restore_path(vector<int> parents, int starting_vertex, int num_of_vertices) {
    vector<int> result;
    for (int i = 0; i < num_of_vertices; ++i) starting_vertex = parents[starting_vertex];

    for (int cur_vertex = starting_vertex; result.size() == 0 || cur_vertex != starting_vertex; cur_vertex = parents[cur_vertex]) {
        result.push_back(cur_vertex);
    }

    result.push_back(starting_vertex);
    cout << result.size() << "\n";
    for (int i = result.size() - 1; i >= 0; --i) cout << result[i] + 1 << " ";
}

void Bellman_Ford(int num_of_vertices, int num_of_edges) {
    vector<int> parents(num_of_vertices, -1);
    vector<long long> distances (num_of_vertices, INT64_MAX);
    distances[0] = 0;
    short cycle_start;
    for (int i = 0; i < num_of_vertices; ++i) {
        cycle_start = -1;
        for (int j = 0; j < num_of_edges; ++j) {
            if (distances[edges[j].second.first] != INT_MAX) {
                if (distances[edges[j].second.second] > distances[edges[j].second.first] + edges[j].first) {
                    distances[edges[j].second.second] = distances[edges[j].second.first] + edges[j].first;
                    parents[edges[j].second.second] = edges[j].second.first;
                    cycle_start = edges[j].second.second;
                }
            }
        }
    }

    if (cycle_start != -1) {
        cout << "YES" << "\n";
        restore_path(parents, cycle_start, num_of_vertices);
    }

    else cout << "NO" << "\n";
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N = 0, M = 0; cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long weight;
            cin >> weight;
            edges.push_back(make_pair(weight, make_pair(i, j)));
            ++M;
        }
    }

    Bellman_Ford(N, M);
    return 0;
}
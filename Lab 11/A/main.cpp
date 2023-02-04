#include <set>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<pair<int64_t, int>>> adjacency_list;

inline int64_t Dijkstra(int num_of_vertices, int starting_vertex, int finishing_vertex) {
    vector<int64_t> distances (num_of_vertices, INT64_MAX);
    set<pair<int64_t, int>> queue;

    distances[starting_vertex] = 0;
    queue.insert({0, starting_vertex});

    while (!queue.empty()) {
        pair<int64_t, int> cur_path;
        cur_path = *queue.begin();
        queue.erase(cur_path);
        int cur_vertex;
        cur_vertex = cur_path.second;

        if (cur_path.first < distances[cur_vertex]) continue;

        for (auto &it: adjacency_list[cur_vertex]) {
            int64_t cur_distance, vertex_to;
            vertex_to = it.second;
            if (distances[cur_vertex] + it.first < distances[vertex_to]) {
                queue.erase({ distances[vertex_to], vertex_to });
                distances[vertex_to] = distances[cur_vertex] + it.first;
                queue.insert({ distances[vertex_to], vertex_to });
            }
        }
    }

    return distances[finishing_vertex];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, start, finish; cin >> N >> start >> finish;
    adjacency_list.resize(N);
    int64_t weight;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> weight;
            if (weight != -1 && weight != 0) {
                adjacency_list[i].push_back({ weight, j });
            }
        }
    }

    int64_t result = Dijkstra(N, start - 1, finish - 1);
    if (result != INT64_MAX) cout << result;
    else cout << -1;

    return 0;
}
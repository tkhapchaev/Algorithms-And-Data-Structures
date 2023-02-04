#include <vector>
#include <iostream>

using namespace std;

#define INT64_MAX 8e18

enum Colour {
    white,
    gray,
    black
};

vector<pair<long long, pair<int, int>>> edges;
vector<vector<int>> adjacency_list;
std::vector<Colour> colours;
vector<int> negative_cycle;

Colour get_colour(int vertex_index) {
    return colours[vertex_index];
}

void DFS(int current_vertex) {
    colours[current_vertex] = gray;
    for (int j = 0; j < adjacency_list[current_vertex].size(); ++j) {
        if (colours[adjacency_list[current_vertex][j]] == white) {
            DFS(adjacency_list[current_vertex][j]);
        }
    }

    colours[current_vertex] = black;
}

void Bellman_Ford(int num_of_vertices, int num_of_edges, int starting_vertex) {
    vector<int> parents(num_of_vertices);
    vector<long long> distances (num_of_vertices, INT64_MAX);
    distances[starting_vertex] = 0;
    short cycle_start;
    for (int i = 0; i < num_of_vertices; ++i) {
        cycle_start = -1;
        for (int j = 0; j < num_of_edges; ++j) {
            if (distances[edges[j].second.first] != INT64_MAX) {
                if (distances[edges[j].second.second] > distances[edges[j].second.first] + edges[j].first) {
                    if (distances[edges[j].second.first] + edges[j].first > -INT64_MAX) {
                        distances[edges[j].second.second] = distances[edges[j].second.first] + edges[j].first;
                    }

                    else distances[edges[j].second.second] = -INT64_MAX;
                    distances[edges[j].second.second] = distances[edges[j].second.first] + edges[j].first;

                    if (i == num_of_vertices - 1) negative_cycle.push_back(edges[j].second.second);
                    parents[edges[j].second.second] = edges[j].second.first;
                    cycle_start = edges[j].second.second;
                }
            }
        }
    }

    if (cycle_start != -1) {
        for (auto &it: negative_cycle) {
            for (int i = 0; i < num_of_vertices; ++i) {
                it = parents[it];
            }

            DFS(it);
        }
    }

    for (int i = 0; i < num_of_vertices; ++i) {
        if (distances[i] <= -INT64_MAX || colours[i] == black) cout << "-" << "\n";
        else if (distances[i] == INT64_MAX) cout << "*" << "\n";
        else cout << distances[i] << "\n";
    }
}

int main() {
    /*
     *
     *
     * KILL ME PLEASE ^_^
     *
     *
     */

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, start; cin >> N >> M >> start;
    adjacency_list.resize(N);
    colours.resize(N);

    for (int i = 0; i < M; ++i) {
        int vertex_1, vertex_2;
        long long weight;
        cin >> vertex_1 >> vertex_2 >> weight;
        edges.push_back(make_pair(weight, make_pair(vertex_1 - 1, vertex_2 - 1)));
        adjacency_list[vertex_1 - 1].push_back(vertex_2 - 1);
    }

    Bellman_Ford(N, M, start - 1);
    return 0;
}
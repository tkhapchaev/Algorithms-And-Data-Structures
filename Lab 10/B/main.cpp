#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> vertices;
vector<double> distances;
vector<bool> is_visited;

double get_distance(pair<int, int> vertex_1, pair<int, int> vertex_2) {
    return sqrt((vertex_2.first - vertex_1.first) * (vertex_2.first - vertex_1.first) + (vertex_2.second - vertex_1.second) * (vertex_2.second - vertex_1.second));
}

double find_MST() {
    double summary = 0;
    for (int i = 0; i < N; ++i) {
        int cur_vertex = -1;
        for (int j = 0; j < N; ++j)
            if (!is_visited[j]) {
                if (cur_vertex < 0) cur_vertex = j;
                else if (distances[j] < distances[cur_vertex]) cur_vertex = j;
            }

        is_visited[cur_vertex] = true;
        for (int k = 0; k < N; ++k) {
            if (!is_visited[k] && cur_vertex != k) {
                if (get_distance(vertices[cur_vertex], vertices[k]) < distances[k]) {
                    distances[k] = get_distance(vertices[cur_vertex], vertices[k]);
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) summary += distances[i];
    return summary;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        vertices.push_back(make_pair(X, Y));
        is_visited.push_back(false);
        distances.push_back(INT_MAX);
    }

    distances[0] = 0;
    cout.precision(10);
    cout << find_MST() << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> D;
vector<int> sequence;
vector<int> position;
vector<int> parents;
vector<int> answer;
int length = 0;

int binary_search(int value) {
    return (int)(upper_bound(D.begin(), D.end(), value) - D.begin());
}

void save_previous(int i, int j) {
    position[j] = i;
    parents[i] = position[j - 1];
    if (j >= length) {
        length = j;
    }
}

void get_answer() {
    auto previous = position[length];
    while (previous != -1) {
        answer.push_back(sequence[previous]);
        previous = parents[previous];
    }

    reverse(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(auto& it: answer) {
        cout << it << " ";
    }
}

int main() {
    int N; cin >> N;
    D.resize(N + 1);
    sequence.resize(N + 1);
    position.resize(N + 1);
    parents.resize(N + 1);

    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    D[0] = -INT_MAX;
    position[0] = -1;
    for (int i = 1; i <= N; ++i) {
        D[i] = INT_MAX;
    }

    for (int i = 0; i < N; ++i) {
        int j = binary_search(sequence[i]);
        if (D[j - 1] < sequence[i] && sequence[i] < D[j]) {
            D[j] = sequence[i];
            save_previous(i, j);
        }
    }

    get_answer();
}
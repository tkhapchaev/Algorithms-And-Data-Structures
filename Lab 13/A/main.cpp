#include <iostream>
#include <vector>

using namespace std;

int main() {
    string P, T;
    cin >> P >> T;
    vector<int> index;
    int N = T.length(), M = P.length();

    for (int i = 0; i <= N - M; ++i) {
        string sample;
        for (int j = i; j <= i + M - 1; ++j) {
            sample += T[j];
        }

        if (P == sample) {
            index.push_back(i);
        }
    }

    cout << index.size() << endl;
    for (auto it: index) {
        cout << it + 1 << " ";
    }
}
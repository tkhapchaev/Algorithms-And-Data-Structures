#include <iostream>
#include <vector>

using namespace std;

void prefix_function(string& input, vector<int>& prefix) {
    int j;
    prefix.resize(input.length());
    for (auto& it: prefix) {
        it = 0;
    }

    for (int i = 1; i < input.length(); ++i) {
        j = prefix[i - 1];
        while (j > 0 && input[j] != input[i]) {
            j = prefix[j - 1];
        }

        if (input[i] != input[j]) {
            prefix[i] = j;
            continue;
        }

        else {
            ++j;
        }

        prefix[i] = j;
    }
}

void KMP(string& T, string& P, vector<int> prefix) {
    vector<int> result;
    for (int i = 0; i < T.length(); ++i) {
        if (P.length() == prefix[P.length() + i + 1]) {
            int j = i - P.length() + 2;
            result.push_back(j);
        }
    }

    cout << result.size() << endl;
    for (auto& it: result) {
        cout << it << " ";
    }
}

int main() {
    string P, T;
    cin >> P >> T;
    vector<int> prefix;
    string sample = P + "#" + T;
    prefix_function(sample, prefix);
    KMP(T, P, prefix);
}
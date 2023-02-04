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

int main() {
    string S; cin >> S;
    vector<int> prefix;
    prefix_function(S, prefix);

    for (auto& it: prefix) {
        cout << it << " ";
    }
}
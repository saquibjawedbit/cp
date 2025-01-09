#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> subsequence_indices[n + 1]; // To store indices of each subsequence
    queue<int> zero_queue, one_queue;      // To manage available '0's and '1's
    int current_sequence = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (!one_queue.empty()) {
                // Continue a subsequence ending in '1'
                int seq = one_queue.front();
                one_queue.pop();
                subsequence_indices[seq].push_back(i + 1);
                zero_queue.push(seq);
            } else {
                // Start a new subsequence
                current_sequence++;
                subsequence_indices[current_sequence].push_back(i + 1);
                zero_queue.push(current_sequence);
            }
        } else { // s[i] == '1'
            if (!zero_queue.empty()) {
                // Continue a subsequence ending in '0'
                int seq = zero_queue.front();
                zero_queue.pop();
                subsequence_indices[seq].push_back(i + 1);
                one_queue.push(seq);
            } else {
                // No valid subsequence can start with '1'
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (!one_queue.empty()) {
        // If there are unfinished subsequences ending in '1', it's invalid
        cout << -1 << endl;
        return 0;
    }

    // Output the result
    cout << current_sequence << endl;
    for (int i = 1; i <= current_sequence; i++) {
        cout << subsequence_indices[i].size();
        for (int idx : subsequence_indices[i]) {
            cout << " " << idx;
        }
        cout << endl;
    }

    return 0;
}

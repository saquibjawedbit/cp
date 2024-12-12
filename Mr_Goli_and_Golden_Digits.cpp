#include <bits/stdc++.h>
using namespace std;

#define ll long long

string removeKDigits(string num, int k) {
    vector<char> stack;
    function<void(int)> dfs = [&](int index) {
        if (index == num.size()) return;
        char digit = num[index];
        while (!stack.empty() && stack.back() > digit && k > 0) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
        dfs(index + 1);
    };
    dfs(0);
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        k--;
    }
    string result(stack.begin(), stack.end());
    int nonZeroIndex = 0;
    while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }
    result = result.substr(nonZeroIndex);
    return result.empty() ? "0" : result;
}

int main() {
    ll tc = 1;
    for (ll t = 1; t <= tc; t++) {
        string num;
        ll k;
        cin >> num >> k;
        cout << removeKDigits(num, k) << endl;
    }
    return 0;
}

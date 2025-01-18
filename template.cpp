#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> solve(int node, map<int, vector<pair<int, int>>> &adjList, vector<int> &nums, map<int, bool> &isVisited, map<int, bool> &visited) {
        vector<int> ans = {INT_MIN, INT_MAX};
        isVisited[node] = 1;
        if(node != -1) visited[nums[node]] = 1;

        for(auto [j, w]: adjList[node]) {
            if(!isVisited[j] && !visited[nums[j]]) {
                vector<int> nAns = solve(j, adjList, nums, isVisited, visited);

                nAns[0] += w;
                nAns[1] += 1;

                if(nAns[0] >= ans[0]) {
                    ans[0] = nAns[0];
                    ans[1] = min(ans[1], nAns[1]);
                }
            }   
        }

        if(ans[0] == INT_MIN) return {0, 0};

        if(node != -1) visited[nums[node]] = 0;
        return ans;
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = edges.size();
        map<int, vector<pair<int, int>>> adjList;
        for(auto &v: edges) {
            int mini = min(v[0], v[1]);
            int maxi = max(v[0], v[1]);
            adjList[mini].push_back({maxi, v[2]});
        }

        vector<int> ans = {INT_MIN, INT_MAX};
        for(int i = 0; i <= n; i++) {
            map<int, bool> isVisited;
            map<int, bool> visited;
            vector<int> nAns = solve(i, adjList, nums, isVisited, visited);
            if(nAns[0] >= ans[0]) {
                ans[0] = nAns[0];
                ans[1] = min(nAns[1]+1, ans[1]);
            }
        } 
    
        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> edges(n, vector<int>(3));
    for(auto &v: edges) {
        for(auto &x: v) cin >> x;
    }
    int x; cin >> x;
    vector<int> nums(x);
    for(auto &v: nums) cin >> v;
    vector<int> ans = Solution().longestSpecialPath(edges, nums);

    for(auto v: ans) cout << v << " ";
}
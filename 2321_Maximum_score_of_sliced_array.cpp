#include <bits/stdc++.h>

using namespace std;


 int solve(vector<int>& nums1, vector<int>& nums2, int index, int state) {
        if(index >= nums1.size()) return 0;

        int ul = 0, ur= 0;

        if(state == 0) {
            ul = solve(nums1, nums2, index+1, 1) + nums2[index];
            ur = solve(nums1, nums2, index+1, 0) + nums1[index];
        }
        else if(state == 1) {
            ul = solve(nums1, nums2, index+1, 2) + nums1[index];
            ur = solve(nums1, nums2, index+1, 1) + nums2[index];
        }
        else {
            ul = solve(nums1, nums2, index+1, 2) + nums1[index];
        }
        return max(ul, ur);

    }


    int solve2(vector<int>& nums1, vector<int>& nums2, int index, int state) {
        if(index >= nums1.size()) return 0;

        int ul = 0, ur= 0;

        if(state == 0) {
            ul = solve(nums1, nums2, index+1, 1) + nums1[index];
            ur = solve(nums1, nums2, index+1, 0) + nums2[index];
        }
        else if(state == 1) {
            ul = solve(nums1, nums2, index+1, 2) + nums2[index];
            ur = solve(nums1, nums2, index+1, 1) + nums1[index];
        }
        else {
            ul = solve(nums1, nums2, index+1, 2) + nums2[index];
        }
        return max(ul, ur);

    }


int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int ans =  solve(nums1, nums2, 0, 0);
        int nAns = solve2(nums1, nums2, 0, 0);
        return max(ans, nAns);

    }

int main() {
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);

    for(auto &v: nums1) cin >> v;
    for(auto &v: nums2) cin >> v;

    int ans = maximumsSplicedArray(nums1, nums2);

    cout << ans << endl;


}
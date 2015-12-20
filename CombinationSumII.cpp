class Solution {

private:
    vector<vector<int>> vs;
    bool vis[1000];

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int arr[1000];
        memset(vis, 0, sizeof(bool) * 1000);
        sort(candidates.begin(), candidates.end());
        helper(arr, 0, 0, candidates, target);
        return vs;
    }

    void helper(int c[], int p, int sum, vector<int>& candidates, int target) {
        if (sum == target) {
            vector<int> v;
            for (int i = 0; i < p; i++) v.push_back(c[i]);
            vs.push_back(v);
        }
        if (sum > target) {  
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (p != 0 && candidates[i] < c[p-1]) continue;
            if (vis[i]) continue;
            vis[i] = true;
            c[p] = candidates[i];
            helper(c, p + 1, sum + candidates[i], candidates, target);
            vis[i] = false;
            while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i]) {
                i++;
            }
        }
    }

};

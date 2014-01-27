#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int> > ret;
            if (num.size() < 3)
                return ret;
            for (int i=0;i < num.size()-2;i++) {
                if (i && num[i] == num[i-1])
                    continue;
                int lf = i+1, rt = num.size()-1;
                while (lf < rt) {
                    int t = num[lf]+num[rt];
                    if (t > -num[i])
                        rt--;
                    else if (t < -num[i])
                        lf++;
                    else {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[lf]);
                        v.push_back(num[rt]);
                        if (ret.empty() || v != ret.back())
                            ret.push_back(v);
                        rt--;
                        lf++;
                    }
                }
            }
            return ret;
        }
};
int main()
{
    Solution so;
    vector<int> v;
    for (int i=0;i < 3;i++)
        v.push_back(0);
    vector<vector<int> > ans = so.threeSum(v);
    cout << ans.size() << endl;
    for (int i=0;i < ans.size();i++) {
        for (int j=0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

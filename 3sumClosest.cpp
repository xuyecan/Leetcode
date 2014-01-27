#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            int ret = 0x3fffffff;
            int sum;
            if (num.size() < 3)
                return ret;
            for (int i=0;i < num.size()-2;i++) {
                if (i && num[i] == num[i-1])
                    continue;
                int lf = i+1, rt = num.size()-1;
                while (lf < rt) {
                    int t = num[lf]+num[rt];
                    t = target-t;

                    int dis = abs(t-num[i]);
                    if (dis < ret) {
                        ret = dis;
                        sum = num[i]+num[lf]+num[rt];
                    }
                    if (t > num[i])
                        lf++;
                    else if (t < num[i])
                        rt--;
                    else {
                        rt--;
                        lf++;
                    }
                }
            }
            return sum;
        }
};
int main()
{
    Solution so;
    vector<int> v;
    v.push_back(-1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(-4);
    cout << so.threeSumClosest(v, 1) << endl;
}

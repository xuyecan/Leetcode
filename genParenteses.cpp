#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ret;
            gen("", 0, 0, n, ret);
            return ret;
        }

        void gen(string cur, int lf, int rt, int n, vector<string> &ret) {
            if (rt == n) {
                ret.push_back(cur);
                return ;
            }

            if (lf < n)
                gen(cur+'(', lf+1, rt, n, ret);
            if (lf > rt)
                gen(cur+')', lf, rt+1, n, ret);
        }
};

int main()
{
    Solution so;
    vector<string> v = so.generateParenthesis(3);
    for (int i=0;i < v.size();i++)
        cout << v[i] << endl;
    return 0;
}

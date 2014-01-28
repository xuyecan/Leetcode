#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            dig[2] = "abc";
            dig[3] = "def";
            dig[4] = "ghi";
            dig[5] = "jkl";
            dig[6] = "mno";
            dig[7] = "pqrs";
            dig[8] = "tuv";
            dig[9] = "wxyz";
            dig[0] = " ";
            dig[1] = "";

            vector<string> ret;
            dfs(digits, 0, "", ret);
            return ret;
        }

        void dfs(string digits, int pos, string cur, vector<string> &ret) {
            if (pos == digits.length()) {
                ret.push_back(cur);
                return;
            }
            int digit = digits[pos]-'0';
            for (int i=0;i < dig[digit].length();i++)
                dfs(digits, pos+1, cur+dig[digit][i], ret);
        }

        string dig[11];
};

int main()
{
    Solution so;
    vector<string> v = so.letterCombinations("234");
    for (int i=0;i < v.size();i++)
        cout << v[i] << endl;
    return 0;
}

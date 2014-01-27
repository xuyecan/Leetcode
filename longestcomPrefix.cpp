#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0)
                return "";
            string comm = strs[0];
            int len = comm.length();
            for (int i=1;i < strs.size();i++) {
                int j;
                for (j=0;j < len && j < strs[i].length();j++)
                    if (comm[j] != strs[i][j]) {
                        len = j;
                        break;
                    }
                if (j == strs[i].length())
                    len = j;
            }
            return comm.substr(0, len);
        }
};

int main()
{
    vector<string> strs;
    Solution so;
    strs.push_back("aaa");
    strs.push_back("aa");
    strs.push_back("a");
    cout << so.longestCommonPrefix(strs) << endl;
}

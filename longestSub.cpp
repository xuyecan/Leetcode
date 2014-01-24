#include <iostream>
#include <string>
#include <memory.h>
using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLen = 0;
            int rec[256];
            int beg = 0;
            for (int i=0;i < 256;i++) rec[i] = -1;

            for (int i=0;i < s.length();i++) {
                if (rec[s[i]] != -1) {
                    if (maxLen < i-beg)
                        maxLen = i-beg;

                    for (int j=beg;j < rec[s[i]];j++)
                        rec[s[j]] = -1;
                    beg = rec[s[i]]+1;
                }
                rec[s[i]] = i;
            }
            if (maxLen < s.length()-beg)
                maxLen = s.length()-beg;
            return maxLen;
        }
};

int main()
{
    Solution s;
    string str = "hchzvfrkmlnozjk";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <memory.h>
#include <cstdlib>

using namespace std;


const int maxn = 1000 + 1;
class Solution {
    public:
        string longestPalindrome(string s) {
            memset(dp, 0, sizeof(dp));
            int beg, end;

            if (s.length() <= 1)
                return s;

            for (int i=0;i < s.length();i++)
                dp[i][0] = 1;
            for (int i=0;i < s.length()-1;i++)
                if (s[i] == s[i+1]) {
                    dp[i][1] = 1;
                    beg = i, end = i+1;
                }
            for (int i=0;i < s.length();i++)
                for (int j=0;j+i < s.length();j++) {
                    if (s[j] == s[j+i] && dp[j+1][i-2]) {
                        dp[j][i] = 1;
                        beg = j, end = j+i;
                    }
                }
            return s.substr(beg, end-beg+1);
        }

        bool dp[maxn][maxn];
};

Solution so;
int main()
{
    string s = "abb";
    cout << so.longestPalindrome(s) << endl;
    return 0;
}

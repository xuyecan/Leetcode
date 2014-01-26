#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if (*s == 0 && *p == 0)
                return true;
            else if (*p == 0)
                return false;
            else if (*(p+1) == '*') {
                if (*s == 0)
                    return isMatch(s, p+2);
                else if (*s == *p || *p == '.')
                    return isMatch(s+1, p) || isMatch(s, p+2);
                else
                    return isMatch(s, p+2);
            }
            else {
                if (*s == 0)
                    return false;
                else if (*s == *p || *p == '.')
                    return isMatch(s+1, p+1);
                return false;
            }
        }
};


int main()
{
    const char *s = "a";
    const char *p = ".*";
    Solution so;
    cout << so.isMatch(s, p) << endl;
}

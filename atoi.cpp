#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;


#define INF 2147483647
#define NINF -2147483648
class Solution {
    public:
        int atoi(const char *str) {
            long long ret = 0;
            int dn = 0;
            int len = strlen(str);
            bool isBeg = true, isPos = true;

            for (int i=0;i < len;i++) {
                if (str[i] == '+' && isBeg) {
                    isPos = true;
                    isBeg = false;
                }
                else if (str[i] == '-' && isBeg) {
                    isPos = false;
                    isBeg = false;
                }
                else if(str[i] == ' ' && isBeg)
                    ;
                else if (str[i] < '0' || str[i] > '9') {
                    break;
                }
                else {
                    ret = ret*10 + (str[i] - '0');
                    dn++;
                    if (dn > 13) break;
                    isBeg = false;
                }
            }
            if (!isPos)
                ret = -ret;
            if (dn == 0)
                return 0;
            else if (ret < NINF)
                return NINF;
            else if (ret > INF)
                return INF;
            else
                return (int)ret;
        }
};

int main()
{
    char str[10] = " -ds3 4f";
    Solution so;
    cout << so.atoi(str) << endl;
}

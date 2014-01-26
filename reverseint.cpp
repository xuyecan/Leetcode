#include <iostream>

using namespace std;


class Solution {
    public:
        int reverse(int x) {
            long long tx = (x < 0 ? -x : x);
            long long ret = 0;
            while (tx) {
                ret = ret*10 + tx%10;
                tx /= 10;
            }
            if (ret > 0x7fffffff)
                return 0;
            else if (x < 0)
                return  0-(int)ret;
            else
                return (int)ret;
        }
};

int main()
{
    int a = -1000000003;
    Solution so;
    cout << so.reverse(a) << endl;
    return 0;
}

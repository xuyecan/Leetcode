#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            long long dd = (long long)dividend;
            dd = abs(dd);
            long long di = (long long)divisor;
            di = abs(di);

            if (dd < di)
                return 0;

            int ret = 0;

            while (dd >= di) {
                long long tmp = di;

                long long cnt = 0;
                while (dd >= tmp) {
                    dd -= tmp;
                    ret += (1 << cnt);
                    tmp <<= 1;
                    cnt++;
                }
            }
            return (dividend^divisor) >> 31 ? -ret: ret;
        }
};

int main() {
    Solution so;
    cout << so.divide(-2147483648, 1) << endl;
}

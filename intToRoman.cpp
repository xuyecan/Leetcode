#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            string ret;
            int base[4][4] = {
                {9000, 5000, 4000, 1000},
                {900, 500, 400, 100},
                {90, 50, 40, 10},
                {9, 5, 4, 1}
            };
            string mapper[4][4] = {
                {"", "", "", "M"},
                {"CM", "D", "CD", "C"},
                {"XC", "L", "XL", "X"},
                {"IX", "V", "IV", "I"}
            };
            for (int i=0;i < 4;i++) {
                for (int j=0;j < 4;j++) {
                    while (num-base[i][j] >= 0) {
                        ret += mapper[i][j];
                        num -= base[i][j];
                    }
                }
            }
            return ret;
        }
};

int main()
{
    Solution so;
    int i = 550;
    while (cin >> i)
        cout << so.intToRoman(i) << endl;
}

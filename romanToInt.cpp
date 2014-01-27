#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;


class Solution {
    public:
        int romanToInt(string s) {
            char single[15] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
            int ref[15] = {1, 5, 10, 50, 100, 500, 1000};
            map<char, int> mapper;
            map<char, int> idx;
            for (int i=0;i < 7;i++) {
                mapper[single[i]] = ref[i];
                idx[single[i]] = i;
            }

            int ret = 0;
            for (int i=0;i < s.length();i++) {
                if (i+1 < s.length() && idx[s[i]] < idx[s[i+1]])
                    ret -= mapper[s[i]];
                else
                    ret += mapper[s[i]];
            }
            return ret;
        }
};

int main()
{
    Solution so;
    cout << so.romanToInt("DCCCXC") << endl;
}

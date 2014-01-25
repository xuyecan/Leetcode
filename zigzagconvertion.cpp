#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if (s.empty()) return s;
            if (nRows == 0) return "";
            if (nRows == 1) return s;

            string ret;

            for (int i=0;i < nRows;i++) {
                for (int j=i;j < s.length();) {
                    int t = -(nRows*2-2) + (j/(nRows*2-2) + 1) * ((nRows*2-2)*2);
                    if (i == 0 || i == nRows-1)
                        ret += s[j];
                    else {
                        ret += s[j];
                        int tn = t-j;
                        if (tn < s.length())
                            ret += s[tn];
                    }

                    j += (nRows*2 - 2);
                }
            }
            return ret;
        }
};

Solution so;
int main()
{
    string s = "abcde";
    cout << so.convert(s, 4) << endl;
}

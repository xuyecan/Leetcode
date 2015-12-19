
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            int count, k = 0;
            string tmp = "";
            while (k < s.length()) {
                count = 1;
                k++;
                while (k < s.length() && s[k] == s[k - 1]) {
                    count++;
                    k++;
                }
                tmp += ('0' + count);
                tmp += s[k - 1];
            }
            s = tmp;
        }

        return s;
    }
};

int main() {

    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}

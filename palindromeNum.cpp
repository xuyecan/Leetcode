#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            int t = x;
            int rev = 0;
            if (x == 0) return true;
            if (x < 0) return false;

            while (t) {
                rev = rev*10 + t%10;
                t /= 10;
            }

            if (rev == x)
                return true;
            return false;
        }
};


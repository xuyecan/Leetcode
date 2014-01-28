#include <stack>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            char match[256];
            match['('] = ')';
            match['['] = ']';
            match['{'] = '}';
            stack<char> st;
            for (int i=0;i < s.length();i++) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    st.push(s[i]);
                else {
                    if (st.empty())
                        return false;
                    else if (match[st.top()] == s[i])
                        st.pop();
                    else
                        break;
                }
            }
            return st.empty();
        }
};

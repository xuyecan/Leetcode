#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;


map<int, int>::iterator iter;
class Solution {
    public:
        vector<int> twoSum(vector<int> &number, int target) {
            map<int, int> m;
            vector<int> ret;
            for (int i = 0;i < number.size();i++)
            {
                iter = m.find(target - number[i]);
                if (iter != m.end())
                {
                    ret.push_back(iter->second + 1);
                    ret.push_back(i+1);
                    return ret;
                }
                m[number[i]] = i;
            }
            return ret;
        }
};

Solution s;
int main()
{
    vector<int> v;
    v.push_back(-3);
    v.push_back(4);
    v.push_back(3);
    v.push_back(90);
    vector<int> ret = s.twoSum(v, 0);
    cout << ret[0] << " " << ret[1] << endl;
}

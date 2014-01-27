#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int> &height) {
            if (height.size() < 2)
                return 0;

            int b = 0, e = height.size()-1;
            int max_area = -1;
            while (b < e) {
                max_area = max(max_area, (e-b)*min(height[b], height[e]));
                if (height[b] < height[e])
                    b++;
                else
                    e--;
            }
            return max_area;
        }
};

int main()
{
    Solution so;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    cout << so.maxArea(v) << endl;;
}

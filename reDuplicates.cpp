#include <iostream>
using namespace std;


class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if (n <= 1)
                return n;

            int idx = 0;
            for (int i=0;i < n;i++)
                if (i && A[i] == A[i-1])
                    continue;
                else
                    A[idx++] = A[i];
            return idx;
        }
};

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cstdlib>

using namespace std;

class Solution {
    public:
        double getMedian(int a[], int b, int e)
        {
            if ((e-b+1)%2)
                return a[(b+e)/2];
            else
                return ((double)a[(b+e)/2] + a[(b+e+1)/2]) / 2;
        }
        double findMedianSortedArrays(int A[], int m, int B[], int n)
        {
            if (m == 0){
                return getMedian(B, 0, n-1);
            }
            else if (n == 0){
                return getMedian(A, 0, m-1);
            }
            else
            return findMedianSortedArrays(A, 0, m-1, B, 0, n-1);
        }
        double findMedianSortedArrays(int a[], int ab, int ae, int b[], int bb, int be)
        {
            if (ae-ab > be-bb)
                return findMedianSortedArrays(b, bb, be, a, ab, ae);
            else if (ae-ab <= 1 && be-bb <= 1){
                int *tmp = new int[10];
                int idx = 0;
                for (int i=ab;i <= ae;i++) tmp[idx++] = a[i];
                for (int i=bb;i <= be;i++) tmp[idx++] = b[i];
                sort(tmp, tmp+idx);
                return getMedian(tmp, 0, idx-1);
            }
            else if (ae-ab <= 1){
                int *tmp = new int[10];
                int idx = 0;
                if ((be-bb+1)%2){
                    for (int i=ab;i <= ae;i++) tmp[idx++] = a[i];
                    for (int i=(bb+be)/2-1;i <= (bb+be)/2+1;i++) tmp[idx++] = b[i];
                    sort(tmp, tmp+idx);
                    return getMedian(tmp, 0, idx-1);
                }
                else {
                    for (int i=ab;i <= ae;i++) tmp[idx++] = a[i];
                    for (int i=(bb+be)/2-1;i <= (bb+be)/2+2;i++) tmp[idx++] = b[i];
                    sort(tmp, tmp+idx);
                    return getMedian(tmp, 0, idx-1);
                }
            }
            else{
                int amid = a[(ab+ae)/2];
                int bmid = b[(bb+be)/2];
                int amididx = (ab+ae)/2;
                int bmididx = (bb+be)/2;
                if (a[amididx] > b[bmididx]){
                    if ((ae-ab+1)%2)
                        return findMedianSortedArrays(a, ab, amididx, b, bb+(ae-amididx), be);
                    else
                        return findMedianSortedArrays(a, ab, amididx+1, b, bb+(ae-amididx-1), be);
                }
                else{
                    return findMedianSortedArrays(a, amididx, ae, b, bb, be-(amididx-ab));
                }
            }
        }
};

int main()
{
    Solution s;
    int a[0] = {};
    int b[2] = {2, 3};
    cout << s.findMedianSortedArrays(a, 0, b, 2) << endl;
}

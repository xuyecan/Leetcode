class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int cnt = 0;
            for (int i=0;i < n-cnt;i++) {
                if (A[i] == elem) {
                    A[i] ^= A[n-cnt-1] ^= A[i] ^= A[n-cnt-1];
                    cnt++;
                    i--;
                }
            }
            return n-cnt;
        }
};

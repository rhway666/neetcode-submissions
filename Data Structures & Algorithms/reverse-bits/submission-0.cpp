class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int cnt = 0;
        while (n > 0) {
            ans <<= 1;
            ans |= (n & 1u);
            cnt++;
            n >>= 1;
        }
        while (cnt < 32) {
            ans <<= 1;
            cnt++;
        }
        return ans;
    }
};

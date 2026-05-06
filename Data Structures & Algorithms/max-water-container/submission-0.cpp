class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        // [1,7,2,5,4,7,3,6,9,1]
        //  l                 r  
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            maxA = max(maxA, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;
    }
};

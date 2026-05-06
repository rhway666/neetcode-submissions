class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int heaviest = stones.back() - stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (heaviest != 0) {
                stones.push_back(heaviest);
            }
        }
        return stones.size() > 0 ? stones[0] : 0; 
    }
};

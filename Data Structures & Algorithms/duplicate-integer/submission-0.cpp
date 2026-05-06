class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // a^a = 0
        unordered_set<int> hash;
        for (auto& n : nums) {
            if (hash.count(n)) return true;
            else hash.insert(n);
        }
        return false;
    }
};

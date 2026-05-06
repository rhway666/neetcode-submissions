class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash;
        for (auto& ss : s) {
            hash[ss]++;
        }
        for (auto& tt : t) {
            if (!hash.count(tt)) return false;
            hash[tt]--;
            if (hash[tt] == 0) hash.erase(tt);
        }
        return hash.empty();
    }
};

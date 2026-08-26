class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> h_map(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            h_map[s[i] - 'a']++;
            h_map[t[i] - 'a']--;
        }
        
        for (auto cnt : h_map) {
            if (cnt != 0) return false;
        }
        return true;
    }
};

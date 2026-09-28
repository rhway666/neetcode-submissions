class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> m;
        // abcdba
        while (r < n) {
            auto it = m.find(s[r]);
            if (it != m.end()) {
                // 重複了
                int idx = it->second;
                while (l < idx + 1) {
                    m.erase(s[l]);
                    l++;
                }
            } else {
                ans = max(r - l + 1, ans);
            }
            m[s[r]] = r;
            r++;
        }
        return ans;
    }
};

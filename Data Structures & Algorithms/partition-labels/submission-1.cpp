class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_occur(26, 0);
        vector<int> ans;
        int l = 0;
        int r = 0;
        int curr_len;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last_occur[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; ++i) {
            r = max(r, last_occur[s[i] - 'a']);
            if (i == last_occur[s[r] - 'a']){
                ans.push_back(r - l + 1);
                l = i + 1;
            }
        }
        return ans;
    }
};

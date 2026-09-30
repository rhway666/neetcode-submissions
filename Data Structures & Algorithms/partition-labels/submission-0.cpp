class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> total_map;
        for (auto c : s) {
            total_map[c]++;
        }

        vector<int> ans;
        int n = s.size();
        int l = 0;
        int r = 0;
        unordered_map<char, int> curr_map;
        while (r < n) {
            
            curr_map[s[r]]++;
            if (curr_map[s[r]] == total_map[s[r]]) {
                bool can_split = true;
                for (auto element : curr_map) {
                    // cout << element.first << " : " << element.second << endl;
                    if (element.second != total_map[element.first]){
                        can_split = false;
                        break;
                    }
                }
                if (can_split) {
                    ans.push_back(r - l + 1);
                    l = r + 1;
                }
            }
            r++;
        }
        return ans;
    }
};

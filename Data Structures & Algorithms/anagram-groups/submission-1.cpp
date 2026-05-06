class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_mp;
        for (auto& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            sorted_mp[sorted].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& group : sorted_mp) {
            //second是 vector<string>
            ans.push_back(group.second); 
        }
        return ans;
    }
};

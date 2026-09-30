class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int curr = n - 1;
        stack<pair<int, int>> s;
        vector<int> ans(n, 0);
        // [69,73,71,74]
        while (curr >= 0) {
            if (s.empty()) {
                ans[curr] = 0;
            } else {
                while (!s.empty()) {
                    auto [idx, tem] = s.top();
                    if (temperatures[curr] >= tem) {
                        s.pop();
                        if (s.empty()) ans[curr] = 0;
                    } else {
                        ans[curr] = idx - curr;
                        break;
                    }
                }  
            }
            s.push({curr, temperatures[curr]});
            curr--;
        } 
        return ans;
    }
};

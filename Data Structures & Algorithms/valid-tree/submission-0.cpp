class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        vector<bool> seen(n, false);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int, int>> q;
        q.push({0, -1});
        seen[0] = true;
        while (!q.empty()) {
            auto curr_node = q.front();
            int curr = curr_node.first;
            int prev = curr_node.second;
            q.pop();
            for (int nei : adj[curr]) {
                if (nei == prev) {
                    continue;
                } else if (seen[nei] == true) {
                    return false;
                } else {
                    q.push({nei, curr});
                    seen[nei] = true;
                }
            }
        }
        for (auto s : seen) {
            if (s == false) return false;
        }
        return true;
    }
};
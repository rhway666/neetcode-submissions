class Solution {
public:
    bool dfs(unordered_set<int>& curr_seen, unordered_set<int>& his_seen, unordered_map<int, vector<int>>& map, int course) {
        if (curr_seen.count(course)) return false;
        if (his_seen.count(course)) return true;
        curr_seen.insert(course);
        for (int pre : map[course]) {
            if (!dfs(curr_seen, his_seen, map, pre)) return false; 
        }
        curr_seen.erase(course);
        his_seen.insert(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)  {
        // [[1,3][2,5][3,6][6,1]]
        unordered_map<int, vector<int>> map;
        for (auto p : prerequisites) {
            map[p[0]].push_back(p[1]);
        }
        unordered_set<int> his_seen;
        for (auto m : map) {
            unordered_set<int> curr_seen;
            int course = m.first;
            if (!dfs(curr_seen, his_seen, map, course)) {
                return false;
            }

        }
        return true;
    }
};

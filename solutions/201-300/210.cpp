class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses == 1) {
            return vector<int>({ 0 });
        }
        vector<vector<int>> link_map(numCourses); // 记录该节点的后继项
        vector<int> ideg(numCourses); // 记录该节点的入度
        for (vector<int> &prerequisite : prerequisites) {
            link_map[prerequisite[1]].push_back(prerequisite[0]);
            ideg[prerequisite[0]]++;
        }
        queue<int> s;
        unordered_set<int> visited;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            // 入度为0的节点添加到S
            if (ideg[i] == 0) {
                s.push(i);
                visited.insert(i);
            }
        }
        while (!s.empty()) {
            int node = s.front();
            ans.push_back(node);
            // std::cout << "node " << node << std::endl;
            for (int &v : link_map[node]) {
                ideg[v]--;
                // std::cout << v << " " << ideg[v] << std::endl;
            }
            // link_map[node].clear();

            for (int i = 0; i < numCourses; i++) {
                if (ideg[i] == 0 && (visited.find(i) == visited.end())) {
                    s.push(i);
                    visited.insert(i);
                }
            }
            s.pop();
        }
        for (int &d : ideg) {
            if (d != 0) {
                return vector<int>();
            }
        }
        return ans;
    }
};
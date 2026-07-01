class Solution {
public:
    bool iscycle(int src, vector<bool>& vis, vector<bool>& recp,
                 vector<vector<int>>& edges) {

        vis[src] = true;
        recp[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (src == u) {
                if (!vis[v]) {
                    if (iscycle(v, vis, recp, edges))
                        return true;
                }
                else if (recp[v]) {
                    return true;
                }
            }
        }

        recp[src] = false;
        return false;
    }

    void topologic(int src, vector<bool>& vis, stack<int>& s,
                   vector<vector<int>>& edges) {

        vis[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (src == u) {
                if (!vis[v]) {
                    topologic(v, vis, s, edges);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {

        vector<bool> vis(numCourses, false);
        vector<bool> recp(numCourses, false);
        vector<int> ans;

        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (iscycle(i, vis, recp, edges))
                    return ans;   // Empty vector
            }
        }

        
        vis.assign(numCourses, false);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topologic(i, vis, s, edges);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
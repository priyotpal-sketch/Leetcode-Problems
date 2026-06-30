class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<bool> vis(n, false);

        pq.push({0, 0});   // {cost, node}

        int ans = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = true;
            ans += cost;

            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int dist = abs(points[node][0] - points[i][0]) +
                               abs(points[node][1] - points[i][1]);

                    pq.push({dist, i});
                }
            }
        }

        return ans;
    }
};
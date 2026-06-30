class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &x : flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int> dist(n,INT_MAX);

        queue<pair<int,int>> q;

        q.push({src,0});
        dist[src]=0;

        int stops=0;

        while(!q.empty() && stops<=k){

            int size=q.size();

            vector<int> temp=dist;

            while(size--){

                auto curr=q.front();
                q.pop();

                int node=curr.first;
                int cost=curr.second;

                for(auto &it:adj[node]){

                    int next=it.first;
                    int wt=it.second;

                    if(cost+wt<temp[next]){

                        temp[next]=cost+wt;
                        q.push({next,temp[next]});
                    }
                }
            }

            dist=temp;
            stops++;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
class Solution {
public:
    bool iscycle(int src,vector<bool>&vis,vector<bool>&recp,vector<vector<int>>&p){
        vis[src]=true;
        recp[src]=true;
       for(int i=0;i<p.size();i++){
        int v=p[i][0];
        int u=p[i][1];
        if(u==src){
            if(!vis[v]){
                if (iscycle(v,vis,recp,p)){
                    return true;
                }
                
            }
            else if(recp[v]){
                return true;
            }

        }

       }
    
       recp[src]=false;
       return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<bool>vis(n,false);
        vector<bool>recp(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recp,p)){
                return false;
                }
            }
        }
    
        return true;

        
    }
};
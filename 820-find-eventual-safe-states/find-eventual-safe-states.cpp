class Solution {
public:  
    bool dfs(int v,vector<bool>&vis,vector<bool>&dfsvis,vector<vector<int>>&graph,vector<bool>&cycle){
        vis[v]=true;
        dfsvis[v]=true;
        for(auto it:graph[v]){//O(Edges)
            if(!vis[it]){
                if(dfs(it,vis,dfsvis,graph,cycle)==false){
                    cycle[v]=false;
                    return false;
                }
            }
            else if(vis[it]== true && dfsvis[it]==true){
                cycle[v]=false;
                return false;
            }
        }
        dfsvis[v]=false;
        return cycle[v];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        vector<bool>dfsvis(n,false);
        vector<bool>cycle(n,true);
        for(int i=0;i<n;i++){//O(Vertices)
           
                if(!vis[i]){
                    dfs(i,vis,dfsvis,graph,cycle);
                
            }
        }
        for(int i=0;i<n;i++){
            if(cycle[i]){ans.push_back(i);}
        }
        //Overall Time Complexity:O(V+E)
        return ans;
        
    }
};
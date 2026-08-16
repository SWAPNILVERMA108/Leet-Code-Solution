// 

class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,vector<int> &mark){
        if(mark[node]==1){
            return false;
        }
        if(mark[node]==2){
            return true;
        }
        mark[node]=1;
        for(int next:graph[node]){
            if(!(dfs(next,graph,mark))){
                return false;
            }
        
        }
        mark[node]=2;
        return true;

    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>mark(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dfs(i,graph,mark)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int noOfCourses = 0;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v] += 1;
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            noOfCourses += 1;
            for(auto it : adj[node]){
                indegree[it] -= 1;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return noOfCourses == numCourses;
    }
};

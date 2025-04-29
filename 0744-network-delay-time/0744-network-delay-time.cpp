class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector<pair<int,int>>> graph(n+1);
        for (const auto& t : times){
            graph[t[0]].push_back({t[1],t[2]});
        }

        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
        pq.push({0,k});
        vector <int> costarr(n+1,INT_MAX);
        costarr[k]=0;

        while(!pq.empty()){
            auto [cost,vert]=pq.top();
            pq.pop();
            
            for (const auto& [vert_1,cost_1]:graph[vert]){
                if (cost+cost_1<costarr[vert_1]){
                    costarr[vert_1]=cost+cost_1;
                    pq.push({costarr[vert_1],vert_1});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (costarr[i] == INT_MAX) return -1;  // unreachable node
            if (maxTime<costarr[i]) maxTime=costarr[i];
        }
        return maxTime;
    }
};
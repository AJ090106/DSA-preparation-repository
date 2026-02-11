class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        vector<pair<int,int>> towers;
        
        for(int i =0; i<n;i++){
            towers.push_back({heights[i],cost[i]});
        }
        sort(towers.begin(),towers.end());
        
        long long totalcost =0;
        for(auto &p : towers){
            totalcost += (long long)p.second;
        }
        
        long long curr =0;
        int target = 0;
        
        for(auto& p : towers){
            curr += (long long)p.second;
            if(curr*2>= totalcost){
                target = p.first;
                break;
            }
        }
        
        long long ans=0;
        for(auto& p : towers){
            ans += (long long)abs(p.first-target)*p.second;
        }
        return (int)ans;
    }
};
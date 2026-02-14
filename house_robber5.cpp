class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
       int n = nums.size();
        vector<long long> dp(n,-1);
        return solve(0,dp,nums,colors);
    }
    long long solve(int ind,vector<long long>&dp,vector<int>& nums, vector<int>& colors){
        int n = nums.size();
        if(ind>=n)return 0;
        
        if(dp[ind]!=-1) return dp[ind];

        long long skip = solve(ind+1,dp,nums,colors);
        long long take;
        if(ind+1<n && colors[ind+1]==colors[ind]){
            take = (long long)nums[ind] + solve(ind +2,dp,nums,colors);
        }
        else{
            take = (long long)nums[ind] + solve(ind +1,dp ,nums,colors);
        }

        return dp[ind] = max(take,skip);
    }
};
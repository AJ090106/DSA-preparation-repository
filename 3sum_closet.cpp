class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int closesum = 1e9/2;
        int ans =0;
        for(int i =0;i<n ;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int currsum = nums[i]+ nums[j]+nums[k];
                if(abs(currsum-target)<abs(closesum-target)){
                    closesum = currsum;
                }
                if(currsum<target){
                    j++;
                }
                else if(currsum>target){
                    k--;
                }
                else{
                    return currsum;
                }
            }
        }
        return closesum;
    }
};
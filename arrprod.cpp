class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixprod(n),suffixprod(n),ans(n);

        prefixprod[0] = 1;
        for(int i =1; i<n ;i++){
            prefixprod[i] = nums[i-1]*prefixprod[i-1];
        }

        suffixprod[n-1] = 1;
        for(int j = n-2 ;j>=0 ; j--){
            suffixprod[j] = nums[j+1]*suffixprod[j+1];
        }

        for(int i =0 ; i<n ;i++){
            ans[i] = prefixprod[i]*suffixprod[i];
        }
        return ans;
    }
};
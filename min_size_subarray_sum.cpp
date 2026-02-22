class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        int l = 0;
        int sum = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];

            while(sum >= target) {
                minlen = min(minlen, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return (minlen == INT_MAX) ? 0 : minlen;
    }
};
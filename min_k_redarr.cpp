class Solution {
public:
    long long totalops(vector<int>& nums, long long k) {
        long long ops = 0;
        for (int x : nums) {
            ops += (x + k - 1) / k;
        }
        return ops;
    }

    int minimumK(vector<int>& nums) {
        int n = nums.size();

        long long low = 1;
        long long high = max(
            (long long)*max_element(nums.begin(), nums.end()),
            (long long)ceil(sqrt(n))
        );

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (totalops(nums, mid) <= 1LL * mid * mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
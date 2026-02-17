class Solution {
public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long currTime = 0;

        for (int length : arr) {
            if (currTime + length <= maxTime) {
                currTime += length;
            } else {
                painters++;
                currTime = length;
            }
        }

        return painters <= k;
    }

    long long minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;  // try smaller max time
            } else {
                low = mid + 1;   // increase time
            }
        }

        return ans;
    }
};
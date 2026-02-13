class Solution {
public:
    int getCount(int n, int d) {
        int low = 1, high = n;
        int firstValid = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int val = mid - digitsum(mid);

            if (val >= d) {
                firstValid = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (firstValid == -1) return 0;
        return n - firstValid + 1;
    }

    int digitsum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};
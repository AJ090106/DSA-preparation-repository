class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, expand(s, i, i));
            ans = max(ans, expand(s, i, i+1));
        }
        return ans;
    }

    int expand(string &s, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else {
                if (isPalindrome(s, left+1, right) ||
                    isPalindrome(s, left, right-1)) {

                    return right - left + 1;
                }
                return -1;
            }
        }
        return -1;
    }

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
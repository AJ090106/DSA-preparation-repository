class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end());
        int l = 0;
        int r = m-1;
        int mini = 1e9;
        while(r<n){
            int diff = a[r]-a[l];
            mini = min(diff,mini);
            l++;
            r++;
        }
        return mini;
    }
};
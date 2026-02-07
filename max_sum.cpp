class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int arrsum =0;
        int currsum = 0;
        
        for(int i =0;i<n ;i++){
            arrsum += arr[i];
            currsum  += i*arr[i];
        }
        
        int res = currsum;
        
        for(int i =1 ;i<n ;i++){
            currsum= currsum+arrsum-(n*arr[n-i]);
            res = max(res,currsum);
        }
        return res;
    }
};
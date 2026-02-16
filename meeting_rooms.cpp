class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int cnt = 1;
        for(int i =1; i<n ;i++){
            if(arr[i][0]>=arr[i-1][1])cnt++;
        }
        return cnt == n;
    }
};
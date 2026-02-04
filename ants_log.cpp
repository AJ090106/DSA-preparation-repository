class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxtime =0;
        for(int x : left ){
            maxtime = max(maxtime,x);
        }
        for(int x : right ){
            maxtime = max(maxtime,n-x);
        }
        return maxtime;
    }
};
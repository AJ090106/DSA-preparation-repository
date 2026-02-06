class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int i =0,j = 0,k=0;
        int bestdiff = INT_MAX;
        int bestsum = INT_MAX;
        vector<int>best(3);
        while(i<a.size()&&j<b.size()&&k<c.size()){
            int maxi = max({a[i],b[j],c[k]});
            int mini = min({a[i],b[j],c[k]});
            int diff = maxi-mini;
            int sum = a[i]+b[j]+c[k];
            if(diff<bestdiff || diff == bestdiff && sum<bestsum){
                bestdiff = diff;
                bestsum = sum;
                best = {a[i],b[j],c[k]};
            }
            
            if(mini == a[i])i++;
            else if(mini == b[j])j++;
            else k++;
        }
                    sort(best.begin(),best.end());
            reverse(best.begin(),best.end());
        return best;
    }
};
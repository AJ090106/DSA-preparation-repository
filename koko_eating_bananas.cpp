class Solution {
  public:
    int calculatehours(vector<int>& arr, int speed){
        int totalH =0;
        for(int bananas : arr){
            totalH += ceil((double)bananas/speed);
        }
        return totalH;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
       int maxi = *max_element(arr.begin(),arr.end());
        int low = 1;
        int high = maxi;
        int ans = maxi;
        
        while(low<= high){
            int mid = (low+high)/2;
            int totaltime = calculatehours(arr,mid);
            
            if(totaltime<=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};
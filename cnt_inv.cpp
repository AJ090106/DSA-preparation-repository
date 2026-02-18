class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        return mergesort(arr,0,arr.size()-1);
    }
    
    long long mergevector(vector<int>&arr,int low,int mid,int high ){
        vector<int> temp;
        int i = low;
        int j = mid+1;
        long long inv =0;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i++]);
            }
            else
        {
            temp.push_back(arr[j++]);
            inv += (mid-i+1);
        }
        }
        
        while(i<=mid)temp.push_back(arr[i++]);
        while(j<=high)temp.push_back(arr[j++]);
        
        for(int k =low; k<=high;k++){
            arr[k] = temp[k-low];
        }
        return inv;
    }
    
    long long mergesort(vector<int>& arr,int low ,int high){
        if(low>=high) return 0;
        int mid = (low+high)/2;
        
        long long inv =0;
        inv += mergesort(arr,low,mid);
        inv += mergesort(arr,mid+1,high);
        inv += mergevector(arr,low,mid,high);
        
        return inv;
    }
};
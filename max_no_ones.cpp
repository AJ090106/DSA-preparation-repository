class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left =0;
        int maxlen = 0;
        int zerocnt =0;
        for(int right =0 ; right < arr.size();right++){
            if(arr[right] == 0)zerocnt++;
            
            while(zerocnt>k){
                if(arr[left] ==0)zerocnt--;
                left++;
                
            }
            maxlen = max(maxlen,right-left+1);
            
        }
        return maxlen;
    }
};
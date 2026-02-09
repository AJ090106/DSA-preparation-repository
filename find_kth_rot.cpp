class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int x = *min_element(arr.begin(),arr.end());
        int idx =-1;
        for(int i =0;i<arr.size();i++){
            if(arr[i]==x){
                idx = i;
            }
        }
        return idx;
    }
};
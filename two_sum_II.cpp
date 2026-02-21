class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int high = n-1;
        int low = 0;
        vector<int>ans;
        while(low<high){
            int mid = (numbers[low]+numbers[high]);
            if(mid == target){
                return {low+1,high+1};
            }
            else if(mid<target){
                low++; 
            }
            else{
                high--;
            }
        }
        return {};
    }
};
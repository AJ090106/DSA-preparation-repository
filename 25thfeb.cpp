//Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.
//Input: arr[] = [1, 2, 3, 4, 1], k = 2
//Output: 3
//Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int,int>mp;
        int sum =0;
        int ans =0;
        for(int i=0;i< n ;i++){
            if(arr[i]<=k)sum-=1;
            else sum+=1;
            
            if(sum>0)ans = i+1;
            else{
                int num = -((abs(sum)+1));
                if(mp.count(num))ans = max(ans , i-mp[num]);
            }
            if(mp.count(sum)==0)mp[sum]=i;
        }
        return ans;
    }
};
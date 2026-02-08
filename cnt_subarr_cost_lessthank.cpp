class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l=0;
     long long cnt =0;
        deque<int>mini,maxi;

        for(int r =0; r<n ;r++){

            while(!maxi.empty() && nums[maxi.back()]<=nums[r]){
                maxi.pop_back();
            }
            while(!mini.empty() && nums[mini.back()]>=nums[r]){
                mini.pop_back();
            }
            mini.push_back(r);
            maxi.push_back(r);
            while (!maxi.empty() && !mini.empty()) {
                long long currCost =
                    (long long)(nums[maxi.front()] - nums[mini.front()]) *
                    (r - l + 1);

                if (currCost <= k) break;

                if(maxi.front()==l)maxi.pop_front();
                if(mini.front()==l)mini.pop_front();
                l++;
        }
            cnt += (long long)(r-l+1);
        }
        return cnt;
    }
        
};
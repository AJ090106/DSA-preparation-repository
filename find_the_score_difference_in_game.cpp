class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        long long p1 = 0, p2 = 0;
        bool isP1Active = true; 

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 != 0)
                isP1Active = !isP1Active;
            if((i + 1) % 6 == 0)
                isP1Active = !isP1Active;
            if(isP1Active)
                p1 += nums[i];
            else
                p2 += nums[i];
        }

        return p1 - p2;
    }
};
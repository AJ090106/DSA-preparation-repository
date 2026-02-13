class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>freq;
        for(int x : nums){
            mp[x]++;
        }
        for(auto& it : mp ){
            freq[it.second]++;
        }

        for(int x : nums){
            if(freq[mp[x]]==1)return x;
        }
        return -1;
    }
};
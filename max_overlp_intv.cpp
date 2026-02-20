class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
    map<int,int> mp;

    for(auto interval : arr)
    {
        mp[interval[0]]++;
        mp[interval[1]+1]--;
    }

    int current = 0;
    int max_overlap = 0;

    for(auto it : mp)
    {
        current += it.second;
        max_overlap = max(max_overlap, current);
    }

    return max_overlap;
    }
};
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int cnt = 0;
        unordered_map<string,int>mp;
        for( string& s : words){
            if(s.length()<k)continue;
            string x = s.substr(0,k);
            mp[x]++;
        }

        for(auto& it : mp){
            if(it.second>=2)cnt++;
        }
        return cnt;
    }
};
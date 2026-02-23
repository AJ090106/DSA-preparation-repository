//Problem : Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
//Medium

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k>n) return false;
        set<string>ans;
        int r= 0;
        int l =0;
        while (r<n){
            if(r-l+1 == k){
                ans.insert(s.substr(l,k));
                l++;
            }
            r++;
        }
 return ans.size()==pow(2,k);

        }
    
};
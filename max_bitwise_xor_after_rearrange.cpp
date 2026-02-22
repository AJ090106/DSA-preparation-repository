class Solution {
public:
    string maximumXor(string s, string t) {
        long long n = t.length();
        long long cnt0 = countbits(t);
        long long cnt1 = n-cnt0;
        string ans = "";
        for(int i =0;i<n ;i++){
            if(s[i]=='1'){
                if(cnt0>0){
                ans += '1';
                cnt0--;
                }
                else {
                    ans += '0';
                    cnt1--;
                }
                
            }
            else{
                if(cnt1>0){
                ans += '1';
                cnt1--;
                }
                else {
                    ans += '0';
                    cnt1--;
                } 
            }
        }
        return ans;
    }
    long long countbits(string x){
        long long cnt0 = 0;
        for(char c : x){
            if(c == '0')cnt0++;
        }
        return cnt0;
    }
};
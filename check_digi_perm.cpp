//Problem : Check digitorial Permutation
//Difficulty : Medium

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<long long> fact(10,1);
        for(int i = 1; i <= 9; i++)
            fact[i] = fact[i-1] * i;

        string s = to_string(n);

        long long sum = 0;
        for(char c : s)
            sum += fact[c - '0'];

        string t = to_string(sum);

        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
// 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
// If the current number is even, you have to divide it by 2.
// If the current number is odd, you have to add 1 to it.
// It is guaranteed that you can always reach one for all test cases.

class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;

        while(s.size() > 1){
            
            if(s.back() == '0'){
                s.pop_back();   
            }
            
            else{
                int i = s.size() - 1;
                
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                
                if(i >= 0){
                    s[i] = '1';
                }
                else{
                    s.insert(s.begin(), '1');  
                }
            }
            
            cnt++;
        }
        
        return cnt;
    }
};
 
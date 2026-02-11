class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string result = "";

    for(string word : words) {
        long long totalWeight = 0;

        for(char ch : word) {
            totalWeight += weights[ch - 'a'];
        }

        int modValue = totalWeight % 26;

        char mappedChar = 'z' - modValue;

        result += mappedChar;
    }

    return result;

    }
};
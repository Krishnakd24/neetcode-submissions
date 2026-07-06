class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        // dp[i] represents the number of ways to decode string of length i
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: one way to decode an empty string
        dp[1] = 1; // One way to decode the first character (if not '0')

        for (int i = 2; i <= n; i++) {
            // Check single digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Check two digits
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
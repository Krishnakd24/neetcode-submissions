class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        // Change size from 26 to 128 to handle all ASCII characters
        vector<int> tf(128, 0);
        vector<int> sf(128, 0);
        
        int ans = INT_MAX;
        int l = 0;
        int ansl = 0;
        int ansr = -1; // Initialize to -1 to detect if a window was found

        for (int t_char : t) tf[t_char]++;

        for (int r = 0; r < s.size(); r++) {
            sf[s[r]]++; // Removed -'A'
            
            if (tf[s[r]] >= sf[s[r]]){
                n--;
            }
            
            if (n == 0) {
                while (l < s.size() && (tf[s[l]] == 0 || sf[s[l]] > tf[s[l]])) {
                    if (sf[s[l]] > tf[s[l]]) sf[s[l]]--;
                    l++;
                }
                
                if (ans > r - l + 1) {
                    ansr = r;
                    ansl = l;
                    ans = r - l + 1;
                }
            }
        }
        return ansr == -1 ? "" : s.substr(ansl, ansr - ansl + 1);
    }
};
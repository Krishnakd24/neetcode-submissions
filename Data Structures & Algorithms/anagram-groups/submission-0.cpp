class Solution {
public:
     vector< vector< string>> groupAnagrams( vector<std::string>& strs) {
         map< array<int, 26>,  vector< string>> anagramMap;
        
        for (const  string& s : strs) {
             array<int, 26> count = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            // Group strings with the identical character frequency signature
            anagramMap[count].push_back(s);
        }
        
        // Collect results
         vector< vector< string>> ans;
        for (auto& pair : anagramMap) {
            ans.push_back( move(pair.second));
        }
        
        return ans;
    }
};
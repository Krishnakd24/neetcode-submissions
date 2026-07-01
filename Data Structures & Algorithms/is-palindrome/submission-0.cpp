class Solution {
public:
    bool isPalindrome(string s) {
        string to_check="";
        for(char c :s){
            if(('A'<=c && c<='Z') || ('a'<=c && c<='z') || ('0'<=c && c<='9')){
                if('A'<=c && c<='Z') to_check+=(char)(c+32);
                else to_check+=c;
            }
        }
        
        int left = 0;
        int right = to_check.length() - 1;
        
        while(left < right) {
            if(to_check[left] != to_check[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};

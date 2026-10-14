class Solution {
public:
    bool isAlphaNumeric(char c){
        if((c >= 'a' && c <='z') || (c >= '0' && c <='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j){
            char forward = tolower(s[i]);
            char backward = tolower(s[j]);
            cout << forward << " " << backward << endl;
            if(isAlphaNumeric(forward) && isAlphaNumeric(backward)){
                if(forward == backward){
                    i++;
                    j--;
                }else{
                    return false;
                }
            }
            if(!isAlphaNumeric(forward)){
                i++;
            }
            if(!isAlphaNumeric(backward)){
                j--;
            }
        }
        return true;
    }
};

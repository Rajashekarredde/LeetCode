class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length() <= 1) return "";        
        if(palindrome.length()%2 == 0){
            int i = 0;
            while(i < palindrome.length() && palindrome[i]=='a'){
                i++;
            }
            if(i!=palindrome.length())
            palindrome[i] = 'a';
            else
                palindrome[i-1]='b';
            return palindrome;
        }else{

            int i = 0;
            while(i < palindrome.length()/2 && palindrome[i]=='a'){
                i++;
            }
            if(i!=palindrome.length()/2){
                palindrome[i] = 'a';
                return palindrome;
            }else{
                int j = palindrome.length()/2 + 1;
                while(j < palindrome.length() && palindrome[j]=='a'){
                    j++;
                }
                if(j!=palindrome.length())
                palindrome[j] = 'a';
                else
                palindrome[j - 1] = 'b';    
                return palindrome;
            }
            
        }
        return "";
        
    }
};
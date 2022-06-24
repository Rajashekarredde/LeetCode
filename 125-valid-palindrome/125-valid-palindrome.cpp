class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left =0; 
        int right = s.length() - 1;
        char leftchar, rightchar;
        
        int temp;
        
        while( left< right )
        {
            leftchar = s[left];
            rightchar = s[right];
            
            if( s[left] < 48 || s[left] > 122 ||
                ( s[left] > 57 && s[left] < 65 ) || 
                ( s[left] > 90 && s[left] < 97 ) )
            {
                left ++;
                continue;
            }
            else if( s[right] < 48 || s[right] > 122 ||
                ( s[right] > 57 && s[right] < 65 ) || 
                ( s[right] > 90 && s[right] < 97 ) )
            {
                right--;
                continue;
            }
            
            if( s[left] >= 65 && s[left] <= 90 )
            {
                temp = leftchar + 32;
                leftchar = temp;
            }
            
            if( s[right] >= 65 && s[right] <= 90 )
            {
                temp = rightchar + 32;
                rightchar = temp;
            }
                 

            if( leftchar == rightchar )
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};
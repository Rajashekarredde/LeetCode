class Solution {
public:
    bool isPalindrome(int x) 
    {
        if( x < 0)
        return false;
        long long int afterRev = 0;
        int beforeRev = x;
        while( x )
        {   
            afterRev =  ( afterRev * 10 )  +  (x % 10) ;
            x = x/10;
        }
        if( afterRev == beforeRev )
        return true;
        else
        return false;
    }
};
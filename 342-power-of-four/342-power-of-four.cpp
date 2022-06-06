class Solution {
public:
    bool isPowerOfFour( long long int n) 
    {
        int count = 0;
        if ( n && !(n & (n-1)) )
        {
            while( n > 1 )
            {
              n = n >> 1;
              count++;
            }
            
             if( ( (count %2) == 0 ) )
        {
            return true;
        }
        else return false;

        }
        return false;
       
    }
};
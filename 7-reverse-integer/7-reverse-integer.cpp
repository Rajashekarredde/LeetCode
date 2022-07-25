class Solution {
public:
    int reverse( long long int x) 
    {
        long long int afterRev = 0;
        long long int beforeRev = 0;
        bool isNeg =(  (x < 0 ) ? true : false ); 
        x = abs(x);
        
        while( x )
        {
            afterRev = ( afterRev * 10 ) + ( x % 10 );
            x = x/10;
        }
        
        x = isNeg ? ( -1 * afterRev ) : afterRev;
        
        if( INT_MIN < afterRev && afterRev < INT_MAX )
            return x;
        
        return 0;
    }
};
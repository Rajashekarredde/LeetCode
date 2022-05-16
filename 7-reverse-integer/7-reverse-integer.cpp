class Solution {
public:
    int reverse( long long int x) 
    {
        long long int afterRev = 0;
        bool isNeg =(  (x < 0 ) ? true : false ); 
        int rem ;
        while(x)
        {
            rem = x%10;
            afterRev = ( afterRev * 10 ) + rem;
            x = x/10;
        }
        if(  INT_MIN < afterRev && afterRev < INT_MAX ) 
        {  
            //afterRev = ( isNeg ? (afterRev * -1 ) : afterRev );
            return afterRev;
        }
        else return 0;
    }
};
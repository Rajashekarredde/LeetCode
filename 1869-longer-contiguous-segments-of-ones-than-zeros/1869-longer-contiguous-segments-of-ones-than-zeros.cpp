class Solution {
public:
    bool checkZeroOnes(string s) {
        
        char prevChar;
        int zeroCount=1; int zeroLen =1;
        int oneCount =1; int oneLen = 1; 
        
        if( s.length() == 1 )
        {
            if( s[0] == '0')
                return false;
            else
                return true;
        }
        
        
        for( int i =0; i<s.length(); ++i)
        {
            if ( i > 0 )
            {
                if( prevChar == '0' &&  s[i] == '0')
                {
                    zeroCount += 1;
                     if( zeroLen < zeroCount )
                      zeroLen = zeroCount;
                }
                else if( prevChar == '1' && s[i] == '1' )
                {
                    oneCount += 1;
                    if( oneLen < oneCount )
                      oneLen = oneCount;
                }
                else
                {
                    zeroCount = 1;
                    oneCount = 1;
                }
                
            }
                        
            prevChar = s[i];
        }
        
        if (oneLen > zeroLen )
            return true;
        else
            return false;
        
    }
};
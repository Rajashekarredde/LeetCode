class Solution {
public:
    int longestPalindrome(string s) 
    {
        int capArr[26] = {0};
        int smallArr[26] = {0};
        int n = s.length();
        int temp;
        for( int i = 0; i<n; ++i )
        {
            if( s[i] >= 65 && s[i] <= 90 )
            {    
                temp = s[i] - 'A';
                capArr[temp]++;
            }
            else
            {
                temp = s[i] - 'a';
                smallArr[temp]++;
            }
        }
        
        int prevMid = 0;
        int count = 0;
        for( int i = 0; i<26; i++ )
        {
            if( capArr[i]  == 0 )
                continue;
            
            if( capArr[i]%2 == 0 )
                count += capArr[i];
            else
            {
                //if( prevMid < capArr[i] )
                {
                    count -= prevMid;
                     if( prevMid != 1)
                    {
                        prevMid =( prevMid/2) * 2;
                        count += prevMid;
                    }
                    prevMid = capArr[i];
                    count += prevMid;
                }
            }
        }
        
        for( int i = 0; i<26; i++ )
        {
              if( smallArr[i]  == 0 )
                continue;
            
            if( smallArr[i]%2 == 0 )
                count += smallArr[i];
            else
            {
                //if( prevMid < smallArr[i]  )
                {
                    count -= prevMid;
                    if( prevMid != 1)
                    {
                        prevMid =( prevMid/2) * 2;
                        count += prevMid;
                    }
                    prevMid = smallArr[i];
                    count += prevMid;
                }
            }
        }
        
        return count;
    }
};
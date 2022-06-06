class Solution {
public:
    bool isPowerOfFour( int n) 
    {
     
          if(n==0 || n==2 || n==3)    return false;
        return ((n==1)||((n%4==0)&&(isPowerOfFour(n/4))));
    }
};
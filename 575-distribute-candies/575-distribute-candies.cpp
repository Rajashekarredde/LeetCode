class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {       
       set<int> uniqueSet; 
       int n = ( candyType.size() / 2 ) ;
        
       for( int i = 0; i<candyType.size(); ++i )
       {    
            uniqueSet.insert( candyType[i] );
       }
        
       int k = n > uniqueSet.size() ? uniqueSet.size() : n ;
        
       return k ;
    }
};
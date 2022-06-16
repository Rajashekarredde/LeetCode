class Solution {
public:
    bool isAnagram(string s, string t) 
    {
          vector< char > store( 256, 0);
        
          for ( int i = 0; i< s.length(); ++i )
          {    
              store[ s[i] ] += 1;    
          }
          
          for( int i = 0 ; i< t.length(); ++i )
          {              
              store[ t[i] ] -= 1;
          }
        
          bool isAnagram = true;
        
          for( int i = 0 ; i< store.size(); ++ i)
          {
              if( store[i] != 0 )
              {
                  isAnagram = false;
                  break;
              }
          }
        
        return isAnagram;
    }
};
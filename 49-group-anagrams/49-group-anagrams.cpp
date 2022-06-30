class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
         map< multiset<char>, vector<string> > store;
         
         for( int i=0; i<strs.size(); ++i )
         {
             multiset<char> charSet( strs[i].begin(), strs[i].end() );
             store[charSet].emplace_back( strs[i] );
         }
        
         vector<vector<string> > ans;
         
         for( auto &item : store )
         {
             ans.emplace_back( item.second );
         }
     return   ans;
    }
};
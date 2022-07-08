class Solution {
public:
    string frequencySort( string s ) 
    {
        unordered_map< char, int> store;
        
        for( int i =0; i<s.length(); ++i )
        {          
            store[s[i]]++;
        }
        
        priority_queue< pair<int, char> > temp;
        for( auto itr : store )
        {
           temp.push({itr.second, itr.first});
        }
        
        s = "";
        
        while( !temp.empty() )
        {
            auto itr = temp.top();
            temp.pop();
            s.append( itr.first, itr.second );
        }
        return s;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
     unordered_map<char, char> letters;
     unordered_map<char, bool> visited;
    
     const int sSize = s.size();
    
        for (int i = 0; i < sSize; ++i)
        if (letters.find(s[i]) == letters.end() && visited[t[i]] == false)
        {
            letters[s[i]] = t[i];
            visited[t[i]] = true;
        }
        else if (letters[s[i]] != t[i])
            return false;
    return true;
        
    }
};
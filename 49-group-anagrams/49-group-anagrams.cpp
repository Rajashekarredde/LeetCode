class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<multiset<char>, vector<string>> charSetToWords;
        for (auto &str : strs) {
            const multiset<char> charSet(str.begin(), str.end());
            charSetToWords[charSet].emplace_back(std::move(str));
        }
        vector<vector<string>> results;
        for (auto &item : charSetToWords) {
            results.emplace_back(std::move(item.second));
        }
        return results;
    }
};
class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
         unordered_map<int,int> mp;
	
    for(int i=0;i<arr.size();i++)
    {
        int ele=arr[i];
        if(mp[ele*2]==0)
        {
            if(ele%2==0 && mp[ele/2]!=0)
                return true;
            else
                mp[ele]++;
        }
        else
            return true;
    }
    return false;  
    }  
};
class Solution 
{
    public:
    string convertToTitle(int columnNumber) 
    {
       string ColumnTitle;   
       while(columnNumber--)
       {          
          ColumnTitle = char('A' + columnNumber % 26) + ColumnTitle;
          columnNumber /= 26;
       }
       return ColumnTitle;
    }
};
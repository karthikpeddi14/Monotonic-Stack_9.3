class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int arr[n];
        for(int i=0 ; i<n ; i++)
        {
            arr[i] =0;
        }
        for(int i=0 ; i<M.size() ; i++)
        {
            for(int j=0 ; j<M[0].size() ; j++)
            {
                if(M[i][j]==1) 
                {
                    arr[j]++;
                    arr[i]--;
                }
                
            }
        }
        
        int ans = -1;
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]==n-1) 
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

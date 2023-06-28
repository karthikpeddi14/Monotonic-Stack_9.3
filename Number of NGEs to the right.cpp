class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<queries ; i++)
        {
            int count = 0;
            for(int j=indices[i]+1 ; j<n ; j++)
            {
                if(arr[indices[i]]<arr[j]) count++;
            }
            ans.push_back(count);
        }
       return ans;
    }

};

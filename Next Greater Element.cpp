class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> v(n,-1);
        stack<long long> st;
        
        for(int i= n-1 ; i>=0 ; i--)
        {
            while(st.size()!=0 && st.top()<=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) v[i] = st.top();
            st.push(arr[i]);
        }
        return v;
    }
};

class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        stack<int> st;
        vector<int> ans(n,-1);
        
        for(int i=2*n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && arr[i%n]>=st.top()) st.pop();
            
            if(i<n)
            {
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int pre_smaller[n];
        int post_smaller[n];
        stack<int> st;
        
        for(int i=0 ; i<n ; i++)
        {
            pre_smaller[i] = 0;
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                pre_smaller[i] += pre_smaller[st.top()]+1;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
    
        for(int i=n-1 ; i>=0 ; i--)
        {
            post_smaller[i] = 0;
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                post_smaller[i] += post_smaller[st.top()]+1;
                st.pop();
            }
            st.push(i);
        }

        // cout << pre_smaller[1] << " " << post_smaller[1] << endl;
        int maxi = 0;
        for(int i=0 ; i<n ; i++)
        {
            int rect = heights[i]*(post_smaller[i]+pre_smaller[i]+1);
            maxi = max(maxi,rect);
        }
        return maxi;
    }
};

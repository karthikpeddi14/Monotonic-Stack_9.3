class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0 ; i<n ; i++)
        {
            if(st.empty() || st.top()*asteroids[i]>0 || (st.top()<0 && asteroids[i]>0)) 
            {
                st.push(asteroids[i]);
                continue;
            }
            
            while(!st.empty() && st.top()>0 && asteroids[i]<0 && st.top()<-1*asteroids[i])
            {
                st.pop();
            }
            
            if(st.empty() || st.top()*asteroids[i]>0 || (st.top()<0 && asteroids[i]>0)) st.push(asteroids[i]);
            else if(st.top() == -1*asteroids[i]) st.pop();
        }
        int n1 = st.size();
        vector<int> ans(st.size());
        for(int i=n1-1 ; i>=0 ; i--)
        {
            ans[i] = st.top();
            st.pop();
        } 
        return ans;
    }
};

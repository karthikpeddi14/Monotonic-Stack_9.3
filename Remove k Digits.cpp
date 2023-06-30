class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n = num.size();
        stack<char> st;
        for(int i=0 ; i<n ; i++)
        {
            
            while(!st.empty() && st.top()>num[i] && k!=0)
            {
                k--;
                st.pop();
            }
            if(num[i]!='0'|| !st.empty()) st.push(num[i]);
        }
        while(!st.empty() && k--)
        {
            st.pop();
        }
        if(st.empty()) return "0";
        string s;
        while(!st.empty())
        {
            num[n-1] = st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        int pre_min[n];
        int post_min[n];
        stack<pair<int,int>> s1;
        stack<pair<int,int>> s2;
        

       for(int i=n-1 ; i>=0 ; i--)
       {
           int count1 = 0;
           while(!s1.empty() && s1.top().first>arr[i])
           {
               count1 = count1 + post_min[s1.top().second] + 1;
               s1.pop();
           }
           post_min[i] = count1;
           s1.push({arr[i],i});
       }

       for(int i=0 ; i<n ; i++)
       {
           int count2 = 0;
           while(!s2.empty() && s2.top().first>=arr[i])
           {
               count2 = count2+ pre_min[s2.top().second] +1;
               s2.pop();
           }
           pre_min[i] = count2;
           s2.push({arr[i],i});
       }

       long long int ans = 0;
       for(int i=0 ; i<n ; i++)
       {
           long long int add = (post_min[i]+1)*(pre_min[i]+1);
           add = add%1000000007;
           add = (add*arr[i])%1000000007;
           ans = ans + add;
           ans = ans%1000000007;
       }
       return ans;
    }
};

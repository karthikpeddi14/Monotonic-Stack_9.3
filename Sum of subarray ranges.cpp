class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        int post_greater[n];
        int pre_greater[n];
        int post_smaller[n];
        int pre_smaller[n];
        stack<int> st1;
        stack<int> st2;
        stack<int> st3;
        stack<int> st4;
        
        for(int i=n-1 ; i>=0 ;i--)
        {
            post_greater[i] =0;
            post_smaller[i] =0;
            while(!st1.empty() && nums[st1.top()]<nums[i])
            {
                post_greater[i] += post_greater[st1.top()]+1;
                st1.pop(); 
            }
            st1.push(i);

            while(!st3.empty() && nums[st3.top()] > nums[i])
            {
                post_smaller[i] += post_smaller[st3.top()] +1;
                st3.pop();
            }
            st3.push(i);
        }

        for(int i=0; i<n ;i++)
        {
            pre_greater[i] =0;
            pre_smaller[i] =0;
            while(!st2.empty() && nums[st2.top()]<=nums[i])
            {
                pre_greater[i] += pre_greater[st2.top()]+1;
                st2.pop(); 
            }
            st2.push(i);

            while(!st4.empty() && nums[st4.top()] >= nums[i])
            {
                pre_smaller[i] += pre_smaller[st4.top()] +1;
                st4.pop();
            }
            st4.push(i);
        }

        long long ans=0;
        for(int i=0 ; i<n ; i++)
        {
            long long add = ((pre_greater[i]+1)*(post_greater[i]+1))%LLONG_MAX;
            long long sub = ((pre_smaller[i]+1)*(post_smaller[i]+1))%LLONG_MAX;
            ans = ans + ((add - sub)*nums[i])%LLONG_MAX;
        }
        return ans;
    }
};

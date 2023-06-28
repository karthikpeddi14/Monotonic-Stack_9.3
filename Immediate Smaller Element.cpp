class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    stack<int> st;
	   // vector<int> v(n,-1);
	    
	    for(int i=n-1 ; i>=0 ; i--)
	    {
	        int temp;
	         temp = arr[i];
	        if(!st.empty() && st.top()<arr[i]) 
	        {
	           
	            arr[i] = st.top();
	        }
	        else arr[i] = -1;
	        st.push(temp);
	    }
	   // return v;
	}

};

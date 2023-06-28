class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        stack<int> st;
        int left = 0;
        int right =n-1;
        int count = 0;
        
        for(int i=1; i<n-1 ; i++)
        {
            if(arr[i] > arr[left]) left = i;
            if(arr[n-1-i] > arr[right]) right = n-1-i;
            
            if(left >= right) return 0;
        }
        
        if(arr[left]<=arr[right])
        {
            for(int i=left+1 ; arr[left]>=arr[i] && left<right ; i++)
            {
                count = count + arr[left]-arr[i];
            }
        }
        else
        {
            for(int i=right-1 ; arr[right]>=arr[i] && left<right ; i++)
            {
                count = count + arr[]
            }
        }
    }
};

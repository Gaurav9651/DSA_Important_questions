// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int min(int a,int b)
    {
        if(a<b)
        {
            return a;
        }
        return b;
    }
    int trappingWater(int arr[], int n){
        // Code here
        int lmax[n],rmax[n],i,sum=0;
        lmax[0]=arr[0];rmax[n-1]=arr[n-1];
        for(i=1;i<n;i++)
        {
            if(arr[i]>lmax[i-1])
            {
                lmax[i]=arr[i];
            }
            else
            {
                lmax[i]=lmax[i-1];
            }
        }
        for(i=n-2;i>=0;i--)
        {
            if(arr[i]>rmax[i+1])
            {
                rmax[i]=arr[i];
            }
            else
            {
                rmax[i]=rmax[i+1];
            }
        }
        for(i=1;i<n-1;i++)
        {
            sum=sum+(min(lmax[i],rmax[i])-arr[i]);
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
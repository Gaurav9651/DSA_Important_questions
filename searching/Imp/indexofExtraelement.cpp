// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // add code here
        int low=0,high=n-1,mid;
        if(a[n-1]!=b[n-2])
            return n-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(a[mid]==b[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
        

        //more promising Solution
    int findExtra(int arr1[],  int arr2[], int n) 
    { 
        // Initialize result 
        int index = n-1;  
      
        // left and right are end  
        // points denoting the current range. 
        int left = 0, right = n - 2; 
        while (left <= right) 
        { 
            int mid = (left + right) / 2; 
      
            // If middle element is same  
            // of both arrays, it means  
            // that extra element is after  
            // mid so we update left to mid+1 
            if (arr2[mid] == arr1[mid]) 
                left = mid + 1; 
      
            // If middle element is different  
            // of the arrays, it means that  
            // the index we are searching for  
            // is either mid, or before mid.  
            // Hence we update right to mid-1. 
            else
            { 
                index = mid; 
                right = mid - 1; 
            } 
        } 
      
        // when right is greater than  
        // left our search is complete. 
        return index; 
    } 


};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends
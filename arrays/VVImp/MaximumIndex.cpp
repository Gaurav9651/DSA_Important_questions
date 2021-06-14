#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,s,n,k) for(i=s;i<n;i=i+k)
#define fom(i,s,n,k) for(i=s;i<n;i=i*k)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
int a[N];
int n, m, k;
//=======================
//*****************************************************Start****************
/*
    Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
    
*/

/*
    Method 1 (Simple but Inefficient) 
        Run two loops. In the outer loop, pick elements one by one from the left.
        In the inner loop, compare the picked element with the elements starting from the right side. 
        Stop the inner loop when you see an element greater than the picked element
        and keep updating the maximum j-i so far.
    
*/
int maxIndexDiff(int arr[], int n)
{
    int maxDiff = -1;
    int i, j;
 
    for (i = 0; i < n; ++i) {
        for (j = n - 1; j > i; --j) {
            if (arr[j] > arr[i] && maxDiff < (j - i))
                maxDiff = j - i;
        }
    }
 
    return maxDiff;
}

/*
    Method2 (LognN:Time Complexity,Space Complexity:N)
        What’s the point of this approach is by making max from end array 
        we are actually getting to know that  there is an element greater than current element 
        in given low and high and if there is greater element, 
        we just have to find the maximum right this greater element is
    Approach :  

        1.Traverse the array from the end and keep a track of the maximum number 
          to the right of the current index including self
        2.Now we have a monotonous decreasing array, 
          and we know we can use binary search to find the index of the rightmost greater element
        3.Now we will just use binary search for each of the elements in the array and 
          store the maximum difference of the indices and that’s it we are done.
*/

int maxIndexDiffrence(vector <long long int > v)
{
    int n=v.size();
    vector<long long int> maxFromEnd(n + 1, INT_MIN);
 
    // create an array maxfromEnd
    for (int i = v.size() - 1; i >= 0; i--) {
        maxFromEnd[i] = max(maxFromEnd[i + 1], v[i]);
    }
 
    int result = 0;
 
    for (int i = 0; i < v.size(); i++) {
        int low = i + 1, high = v.size() - 1, ans = i;
 
        while (low <= high) {
            int mid = (low + high) / 2;
 
            if (v[i] <= maxFromEnd[mid]) {
               
                // We store this as current answer and look
                // for further larger number to the right
                // side
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        // keeping a track of the
        // maximum difference in indices
        result = max(result, ans - i);
    }
    return result;
}


/*
 Method 3 (O(N):Time Complexity ,O(N):Space Complexity)
    In This what we do is We remove the repeation of check How we do this is 
    We make an array of Left min and Right max And then traverse through both arrray
    Simultaneously and if Lmin is less than right max we check that for how 
    right it is less 

    lets say we got to an array and its lmin is 8 we move to right of rmax until we see that 
    rmax is less this means for this lmin the max length is rmax index
    now we move to next element if it is larger than lmin remains same and it will directly move to next element
    if it is smaller than min length then its rmax right most will obviosly 
    greater than or atleast equal to right max of previous elemt if its greater
    it will move it to more right if the index diff becomes more it will update max diffrence
*/
int maxIndexDiff(int arr[], int n)
{
    int maxDiff;
    int i, j;
 
    int* LMin = new int[(sizeof(int) * n)];
    int* RMax = new int[(sizeof(int) * n)];
 
    /* Construct LMin[] such that
    LMin[i] stores the minimum value
    from (arr[0], arr[1], ... arr[i]) */
    LMin[0] = arr[0];
    for (i = 1; i < n; ++i)
        LMin[i] = min(arr[i], LMin[i - 1]);
 
    /* Construct RMax[] such that
    RMax[j] stores the maximum value from
    (arr[j], arr[j+1], ..arr[n-1]) */
    RMax[n - 1] = arr[n - 1];
    for (j = n - 2; j >= 0; --j)
        RMax[j] = max(arr[j], RMax[j + 1]);
 
    /* Traverse both arrays from left to right
    to find optimum j - i. This process is similar to
    merge() of MergeSort */
    i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n) {
        if (LMin[i] < RMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }
 
    return maxDiff;
}
 
/*
    My method find the right max array and for every no find the right most index
    till we can go
*/

int maxIndexDiff(int arr[], int n) 
    { 
        
        // Your code here
        
             int maxDiff;
            int i, j;
            int RMax[n];
         
            /* Construct RMax[] such that
            RMax[j] stores the maximum value from
            (arr[j], arr[j+1], ..arr[n-1]) */
            RMax[n - 1] = arr[n - 1];
            for (j = n - 2; j >= 0; --j)
                RMax[j] = max(arr[j], RMax[j + 1]);

            /* Traverse both arrays from left to right
            to find optimum j - i. This process is similar to
            merge() of MergeSort */
            i = 0, j = 0, maxDiff = -1;
            while (j < n && i < n) {
                if (arr[i] <= RMax[j]) {
                    maxDiff = max(maxDiff, j - i);
                    j = j + 1;
                }
                else
                    i = i + 1;
            }
         
            return maxDiff;
    }
//*****************************************************End******************
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      cout<<solve();
    }

    return 0;
}
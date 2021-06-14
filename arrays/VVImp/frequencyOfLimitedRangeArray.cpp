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


Given an array A[] of N positive integers which can contain integers from 1 to P
where elements can be repeated or can be absent from the array.
Your task is to count the frequency of all elements from 1 to N.

1)  Subtract 1 from every element so that the elements
    become in range from 0 to n-1.

2)  Use every element arr[i] as index and add 'n' to
    element present at arr[i]%n to keep track of count of
    occurrences of arr[i]
    for (int i=0; i < n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;

3)  To print counts, simply print the number of times n
    was added at index corresponding to every element.


*/
int frequencyOfLimitedRangeArrayElements(vector<int>& arr,int N, int P) {
  for(int i=0;i<N;i++)
        {
            arr[i]--;
        }
        int T=max(N,P);
        for(int i=0;i<N;i++)
        {
            if(arr[i]%T<N)
            {
                arr[arr[i]%T]+=T;
            }
            
        }
        for(int i=0;i<N;i++)
        {
            arr[i]=arr[i]/T;
        }
}

int frequencyOfLimitedRangeArrayElements(vector<int>& arr,int N, int P) {
    
        //Decreasing all elements by 1 so that the elements
        //become in range from 0 to n-1.
    	for (int i = 0; i < N ; i++) 
    		arr[i] = arr[i]-1; 
    	sort(arr.begin(), arr.end());
    	int ind = N;
    	for(int i = 0 ; i < N ; i++)
    	{
    	   if(arr[i] >= N)
    	   {
    	       if(ind == N)
    	           ind = i;
    	       arr[i] = 0;
    	   }
    	}
    	//Using every element arr[i] as index.	
        //Updating the array elements using mathematical formula
        //to find the frequencies of all elements from 1 to N.
    	for (int i = 0; i < ind ; i++) 
    	    //Adding n to element present at arr[i]%n to keep
    	    //track of count of occurrences of arr[i].
    		arr[arr[i]%N] = arr[arr[i]%N] + N; 
    
        //Calculating the frequency of each element.
    	for (int i = 0; i < N; i++) 
    	    //Finally dividing the array elements by n to find the frequency.
    		arr[i] = arr[i]/N;
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
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
    Question:
        You are given an array of N+2 integer elements. 
        All elements of the array are in range 1 to N. 
        Also, all elements occur once except two numbers which occur twice. 
        Find the two repeating numbers.
    
    What we are doing here is when we get a no we make a element present at the index=the no 
    So if we reach to same index and it was negative that means that no has occured again
    we print taht no

 */

pair<int,int> twoRepeated(int a[], int n)
    {    
        pair<int , int > res;
        bool first = false;
        
        //iterating over the array elements.
        for(int i=0;i<n+2;i++)
        {
            //making the visited elements negative.
            if(a[abs(a[i])]>0)
                a[abs(a[i])]=-a[abs(a[i])];
            
            //if the number is negative, it was visited previously
            //so this would be the repeated element.
            else
            {
                //storing first and second repeated element accordingly.
                if(first == false)
                {
                    res.first = abs(a[i]);
                    first = true;
                }
                else
                {
                    res.second = abs(a[i]);
                    break;
                }
            }
        }
        //returning the result.
        return res;
    }
//*****************************************************End******************
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      cout<<twoRepeated();
    }

    return 0;
}
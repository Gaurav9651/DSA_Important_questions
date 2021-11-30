//**********************************************************TEMPLATE START******************************************************************
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define inf INT_MAX
#define minf INT_MIN
#define ff first
#define ss second
#define mp make_pair
#define nline "\n"
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define msb(x) (31 - __builtin_clz(n))
#define msbll(x) (63 - __builtin_clzll(n))
#define setbitsll(x) __builtin_popcountll(x)
#define setmo(x) memset(x, -1, sizeof(x))
#define setzero(x) memset(x, 0, sizeof(x))
#define f(i, n) for (i = 0; i < n; i++)
#define fe(i, n) for (i = 1; i <=n; i++)
#define fos(i, s, n, k) for (i = s; i < n; i = i + k)
#define fom(i, s, n, k) for (i = s; i < n; i = i * k)
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());} // for Vector v
#define printPrecision(p, Value) cout << fixed << setprecision(p) << Value
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpi> vvpi;
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif
#pragma warning disable format
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll powm(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
void extendgcd(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } //pass an arry of size1 3
ll mminv(ll a, ll b) { ll arr[3]; extendgcd(a, b, arr); return arr[0]; } //for non prime b
ll mminvprime(ll a, ll b) { return powm(a, b - 2, b); }
ll NcR(ll n, ll r, ll m, ll* fact, ll* ifact) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m; }
vector<ll> sieve(int n) { int* arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1; } return vect; }
ll addm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mulm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll subm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll divm(ll a, ll b, ll m) { a = a % m; b = b % m; return (mulm(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int i, j, k;
const int MOD = 1000000007;
const int MOD1 = 998244353;
#pragma warning restore format
//**********************************************************TEMPLATE ENDS******************************************************************
/*
THINGS TO KEEP IN MIND BEFORE SUBMITTTING
  * Always Check Which MOD it is Asking For
  * Dont Forget To use Long While using Vector ShortHad vl
  * Dont get stuck at One Approach.
  * Unique function return iterator Then We can resize the container
  * Look for Possible Edge Cases
  * int overflows, array bounds, etc.
  * n % mod = (n % mod + mod) % mod; (Handling negatives)
  * string .append() or += is O(1), but s = s + s is O(n) (as it creates a copy first), use wisely
  * use __lg(n) instead of log2(n), int: 31 - __builtin_clz(n), ll: 63 - __builtin_clzll(n), https://codeforces.com/blog/entry/45966
  * (a & b) + (a | b) = a + b
  * https://oeis.org/ Sequence Related Problem
  * DO NOT GET STUCK ON ONE APPROACH
  * DO NOT GET STUCK ON ONE APPROACHP
  * DO NOT GET STUCK ON ONE APPROACH
  * DO NOT GET STUCK ON ONE APPROACH
  * DO NOT GET STUCK ON ONE APPROACH
*/
void solve()
{
}
//*****************************************************End***********************************************************
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("Error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve();
  }
  return 0;
}

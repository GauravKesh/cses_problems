#include <bits/stdc++.h>
using namespace std;

// ===================== TYPE ALIASES =====================
#define int long long
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<ll>
#define vpi vector<pii>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define arrSum(a) accumulate(all(a), 0)

// ===================== LOOPS =====================
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = b - 1; i >= a; --i)
#define each(x, a) for (auto &x : a)

// ===================== FAST I/O =====================
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define endl '\n'

// ===================== DEBUGGING =====================
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif

// Debug helpers
template <typename T>
void _print(T x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <typename T>
void _print(vector<T> v)
{
    cerr << "[";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(set<T> s)
{
    cerr << "{";
    for (auto i : s)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}
template <typename T>
void _print(multiset<T> s)
{
    cerr << "{";
    for (auto i : s)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}
template <typename T>
void _print(map<T, T> m)
{
    cerr << "{";
    for (auto i : m)
    {
        _print(i.F);
        cerr << ":";
        _print(i.S);
        cerr << " ";
    }
    cerr << "}";
}

// ===================== MATH HELPERS =====================
int mod = 1e9 + 7;
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return (a * b) % mod; }
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int a) { return binpow(a, mod - 2); }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

/*
approach :-
7.5 7.5 14
1  =1.  no
1 2 =3 no
1 2 3 =6 yes 3
1 2 3 4 =10 yes 5
1 2 3 4 5 = 15  no
1 2 3 4 5 6  = 21
1 2 3 4 5 6 7 = 28 yes 14
1 2 3 4 5 6 7 8  = 36 18. 8+2+7+1. 3,4,5,6
1 2 3 4 5 6 7 8 9 = 46 23  , 9+8+6 123457 22
1 2 3 4 5 6 7 8 9 10 = 56 28 =>  (7,) (1,2,4,5,7,8) 27 14 (7  ,10,8,3) 11+17 (1,24569) 27

so if sum of n number is odd -> NO
else:
    yes
    then( insert those numbers into set 1 where it satisfies the sum so s1 consist of number unless it doesn't cross half of the sum as we need 2 set of equal sum )

    sum(s1) = sum(s2)

    
*/

// ===================== SOLVE FUNCTION =====================
void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        NO;
        return;
    }

    int nsum = (n*(n+1))/2;
    // rep(i, 0, n) arr.pb(i + 1);

    if (nsum % 2 == 0) {
        int hfs = nsum/ 2;
        vi s1, s2;
        int curr = 0;

        for (int i = n; i >= 1; i--) {
            if (curr + i <= hfs) {
                s1.pb(i);
                curr += i;
            } else {
                s2.pb(i);
            }
        }

        YES;
        cout << s1.size() << endl;
        each(x, s1) cout << x << " ";
        cout << endl;
        cout << s2.size() << endl;
        each(x, s2) cout << x << " ";
        // cout << endl;
    } else {
        NO;
    }
}

// ===================== MAIN =====================
int32_t main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
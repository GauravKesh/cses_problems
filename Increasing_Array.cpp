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
#define vi vector<int>
#define vpi vector<pii>

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

// ===================== SOLVE FUNCTION =====================
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int min_step = 0;
    // int cmax = a[0];
    int prevmax = a[0];
    rep(i, 1, n)
    {
        if (a[i] < prevmax)
        {
            min_step += prevmax - a[i];
        }
        else
        {
            prevmax = a[i];
        }
    }
    cout << min_step << endl;
    debug(a);
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
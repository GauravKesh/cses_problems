#include <bits/stdc++.h>
using namespace std;

// ===================== TYPE ALIASES =====================
// #define int long long
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
const ll MOD = 1e9 + 7;

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

// ---------- FAST EXPONENTIATION ----------
ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// ---------- PRECOMPUTE FACTORIALS ----------
const int N = 1e6; // adjust as per constraints
ll fact[N + 1], invFact[N + 1];

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invFact[N] = power(fact[N], MOD - 2); // Fermat’s little theorem
    for (int i = N - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// ---------- nCr FUNCTION ----------
ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
}

// ---------- nPr FUNCTION ----------
ll nPr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}

/*
   approach:
             2^n
            0 to n-1;
            0->00
            1->01
            2->10
            3->11
            .
            .
            .
            n-1 ->

            Gray code formula:
                gray(i)=i⊕(i>>1)

*/

// ===================== SOLVE FUNCTION =====================

string getBinary(int n,int si){
    string s = "";
    while(n>0){
        s = char('0'+(n%2))+s;
        n/=2;
    }

    while((ll)s.size()<si) s= '0'+s;

    return s;
    
}
void solve()
{
    int n;
    cin >> n;
    int total = 1 << n; // 2^n
    for (int i = 0; i < total; i++) {
        cout << getBinary(i ^ (i >> 1), n) << "\n";
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
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n;
    cin >> n;
    long long summ = n * (n + 1) / 2;
    long long sm = 0;
    for (int i = 1; i <= n-1; i++)
    {
        long long k;
        cin >> k;
        sm+=k;
    }

    cout<<summ-sm<<"\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll f[15];
string s[6];

ll cnk(ll n, ll k)
{
    return f[n] / (f[n - k] * f[k]);
}

int main()
{
    s[0] = "1432";
    s[1] = "54123";
    s[2] = "12453";
    s[3] = "45231";
    s[4] = "6714235";
    s[5] = "31528764";
    cout << "BEFORE: ";
    for (int i = 0; i <= 5; i++) cout << s[i] << ' ';
    cout << endl << "NEXT PERMUTATION: ";
    for (int i = 0; i <= 5; i++) next_permutation(s[i].begin(), s[i].end());
    for (int i = 0; i <= 5; i++) cout << s[i] << ' ';
    f[0] = 1;
    for (ll i = 1; i <= 9; i++) f[i] = f[i - 1] * i;
    ll n = 8;
    cout << endl << "(x-y)^8 = ";
    for (int i = 0; i <= n; i++)
    {
        if (i != n)
        {
            cout << cnk(n, i) << "*x^" << n - i << "*y^" << i;
            if (i % 2) cout << " + ";
            else cout << " - ";
        }
        else cout << cnk(n, i) << "*x^" << n - i << "*y^" << i;
    }
    return 0;
}

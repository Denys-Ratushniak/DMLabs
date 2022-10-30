#include <bits/stdc++.h>

#include <Windows.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair < ll, ll > pairll;
const ll DIM = 17;
const ll INF = 1e18 + 7;
ll n = 8;
ll d[DIM][DIM];
ll k[DIM];
ll used[DIM];
ll start;
char x;
vector < ll > res;

vector < pair < vector < ll >, ll > > komi;

vector < pair < vector < ll >, ll > > all;
ll mn = INF;
void dfs(ll now, ll sz, vector < ll > a, ll w)
{
    if (sz == n)
    {
        k[start]++;
        a.push_back(start);
        w += d[a[a.size() - 1]][a[a.size() - 2]];
        if (k[start] == 1) komi.push_back({a, w});

        if (w < mn)
        {
            mn = w;
            res = a;
        }
        all.push_back({a, w});
        return;
    }
    ll minnow = INF;
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 1) continue;
        if (d[now][i] < minnow) minnow = d[now][i];
    }

    for (ll i = 1; i <= n; i++)
    {
        if (used[i] == 1) continue;
        if (d[now][i] == minnow)
        {
            used[i] = 1;
            a.push_back(i);
            dfs(i, sz + 1, a, w + minnow);
            a.pop_back();
            used[i] = 0;
        }
    }
    return;
}
int main()
{
    SetConsoleOutputCP(1251);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            d[i][j] = INF;
            if (x >= '1' && x <= '9') d[i][j] = x - '0';
        }
    }

    vector < ll > a(1);
    for (start = 1; start <= n; start++)
    {
        a[0] = start;
        used[start] = 1;
        dfs(start, 1, a, 0);
        used[start] = 0;
    }

    cout << "Методом іди у найближчий всього я знайшов " << all.size() << " різних шляхів" << endl;

    cout << "Найменша сумарна вага = " << mn << " Ланцюг: ";
    cout << "V" << res[0];
    for (int i = 1; i <= n; i++) cout << "->V" << res[i];
    cout << endl;
    cout << "Перший ланцюг знайдений методом іди у найближчий починаючи з вершини: " << endl;
    for (auto to: komi)
    {
        cout << "V" << to.first[0] << ": ";

        cout << "V" << to.first[0];
        for (int i = 1; i <= n; i++) cout << "->V" << to.first[i];
        cout << " Вага = " << to.second << endl;
    }

    cout << "Всі ланцюги знайдені методом іди у найближчий: " << endl;

    for (auto to: all)
    {
        cout << "V" << to.first[0];
        for (int i = 1; i <= n; i++) cout << "->V" << to.first[i];
        cout << "   Вага = " << to.second << endl;
    }

    return 0;
}

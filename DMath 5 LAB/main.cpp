#include <bits/stdc++.h>

#include <Windows.h>

using namespace std;
typedef long long ll;
typedef pair < ll, ll > pairll;
const ll DIM = 10007;
const ll INF = 1e18 + 7;
vector < pairll > a[DIM];
priority_queue < pairll, vector < pairll >, greater < pairll > > q;
void add(ll x, ll y, ll val)
{
    a[x].push_back({y, val});
    a[y].push_back({x, val});
}
ll used[DIM], par[DIM], dist[DIM], m, n, v1, v2, val, total, v, d;
int main()
{
    SetConsoleOutputCP(1251);
    /* 30
    49
    0 1 3    1 2 4    2 3 8    3 4 8    4 5 4    6 7 4
    7 8 1    8 9 1    9 10 2   10 11 7  12 13 4  13 14 5
    14 15 2  15 16 7  16 17 7  18 19 8  19 20 3  20 21 1
    21 22 1  22 23 5  24 25 1  25 26 7  26 27 3  27 28 6
    28 29 3  0 6 1    6 12 7   12 18 3  18 24 2  1 7 2
    7 13 1   13 19 7  19 25 3  2 8 3    8 14 7   14 20 3
    20 26 1  3 9 4    9 15 7   15 21 3  21 27 1  4 10 5
    10 16 1  16 22 5  22 28 2  5 11 6   11 17 3  17 23 4   23 29 8
    my graph */
    cout << "WARNING: I use numeration from 0" << endl;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    cout << "Enter edges step by step on the principle - vertix1 vertix2 weight" << endl;
    for (int i = 1; i <= m; i++)
    {
        cin >> v1 >> v2 >> val;
        add(v1, v2, val);
    }
    cout << "Enter pair of vertix to find minimum distance between them ";
    ll S, F;
    cin >> S >> F;
    for (int i = 0; i < n; i++) dist[i] = INF;
    q.push({0, S});
    dist[S] = 0;
    par[S] = -1;
    while (q.size())
    {
        v = q.top().second;
        d = q.top().first;
        q.pop();
        if (used[v]) continue;
        used[v] = 1;
        for (auto to: a[v])
        {
            if (used[to.first] == 0 && dist[to.first] > dist[v] + to.second)
            {
                dist[to.first] = dist[v] + to.second;
                par[to.first] = v;
                q.push({dist[to.first], to.first});
            }
        }
    }

    vector < pairll > D;
    for (int i = 0; i < n; i++) D.push_back({dist[i], i});
    sort(D.begin(), D.end());
    for (int i = 0; i < n; i++)
    {

        v = D[i].second;
        vector < ll > L;
        while (par[v] != -1)
        {
            L.push_back(v);
            v = par[v];
        }
        reverse(L.begin(), L.end());
        cout << "Шлях до V" << D[i].second << ": V" << S;
        for (auto to: L) cout << "->V" << to;
        cout << " Відстань: " << D[i].first << endl;
    }
    //cout << "RESULT: DISTANCE FROM " << S << " TO " << F << " is " << dist[F] << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair < ll, ll > pairll;
const ll DIM = 10007;
vector < pairll > a[DIM];
priority_queue < pair < ll, pairll >, vector < pair < ll, pairll >>, greater < pair < ll, pairll >> > q;

void add(ll x, ll y, ll val)
{
    a[x].push_back({y, val});
    a[y].push_back({x, val});
}

ll used[DIM], m, n, v1, v2, val, total;
int main()
{
    /* 11
    18
    1 2 7    1 3 3    1 4 1
    2 5 2    2 7 1    3 5 7
    3 6 4    4 6 2    4 7 5
    5 8 4    5 9 4    6 8 6
    6 10 2   7 9 3    7 10 3
    8 11 7   9 11 4   10 11 5
    my graph */
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
    m = 0;
    q.push({0, {1, 1}});
    vector < pair < ll, pairll > > edges;
    while (m != n - 1)
    {
        v1 = q.top().second.first;
        v2 = q.top().second.second;
        val = q.top().first;
        q.pop();
        if (used[v1]) continue;
        used[v1] = 1;
        if (v1 != v2)
        {
            m++;
            cout << "ADD TO GRAPH EDGE FROM " << min(v1, v2) << " TO " << max(v1, v2) << " weight " << val << endl;
            edges.push_back({val, {v1, v2}});
            total += val;
            cout << "ALL EDGES: ";
            for (auto to: edges)
            {
                cout << min(to.second.first, to.second.second) << " ";
                cout << max(to.second.first, to.second.second) << " " << to.first << " | ";
            }
            cout << "TOTAL WEIGHT : " << total << endl;
        }
        for (auto to: a[v1])
            if (used[to.first] == 0) q.push({to.second, {to.first, v1}});
    }
    return 0;
}

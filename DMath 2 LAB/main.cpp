#include <bits/stdc++.h>

#include <Windows.h>

using namespace std;
typedef long long ll;

set < char > s, u, dop;

void print(set < char > q)
{
    if (!q.size())
    {
        cout << "{} типу порожня множина\n";
        return;
    }
    cout << '{';
    for (auto to: q)
    {
        cout << to;
        if (to != * q.rbegin()) cout << ",";
    }
    cout << "}\n";
}

char mas[257];

int main()
{
    SetConsoleOutputCP(1251);
    string sin;
    cout << "Правила:\nБудь ласка, вводьте символи по одному через enter\n";
    cout << "Вводьте символи універсуму скільки захочете, якщо хочете зупинити ввід введіть STOP\n";
    while (1)
    {
        getline(cin, sin);

        if (sin == "STOP") break;

        if (sin.size() > 1)
        {
            cout << "Дотримуйтесь правил!\n";
            continue;
        }

        char x = sin[0];

        if (u.find(x) != u.end())
        {
            cout << "Ви вже ввели такий елемент, введіть, будь ласка, інший\n";
            continue;
        }

        u.insert(x);
    }

    cout << "Вводьте символи множини скільки захочете, якщо хочете зупинити ввід введіть STOP\n";
    while (1)
    {
        getline(cin, sin);

        if (sin == "STOP") break;

        if (sin.size() > 1)
        {
            cout << "Дотримуйтесь правил!\n";
            continue;
        }

        char x = sin[0];

        if (s.find(x) != s.end())
        {
            cout << "Ви вже ввели такий елемент, введіть, будь ласка, інший\n";
            continue;
        }

        if (u.find(x) == u.end())
        {
            cout << "Такого елемента немає в універсумі, введіть, будь ласка, інший\n";
            continue;
        }

        s.insert(x);
    }

    int sizeu = u.size();
    int sizes = s.size();
    bitset < 256 > U, S, DOP;

    for (auto to: u)
        if (s.find(to) == s.end()) dop.insert(to);

    int sizedop = dop.size();

    U |= (((ll) 1 << sizeu) - 1);

    auto it = u.begin();

    for (int i = 0; i < sizeu; i++)
    {
        if (s.find( * it) != s.end()) S[i] = 1;
        it++;
    }
    DOP = U ^ S;

    cout << "Це характеристичний вектор універсуму : ";
    for (int i = 0; i < sizeu; i++) cout << U[i];
    cout << "\n";

    cout << "Це характеристичний вектор заданої множини : ";
    for (int i = 0; i < sizeu; i++) cout << S[i];
    cout << "\n";

    cout << "Це характеристичний вектор доповнення до заданої множини : ";
    for (int i = 0; i < sizeu; i++) cout << DOP[i];
    cout << "\n";
    cout << "Множина універсуму: ";
    print(u);

    cout << "Множина заданої множини: ";
    print(s);

    cout << "Множина доповнення до заданої множини: ";
    print(dop);

    cout << "SIZE = " << max(1, sizedop) << "\n";
    cout << "This is булеан:\n";

    char a[sizedop + 1];
    for (int i = 0; i < sizedop; i++)
    {
        a[i] = ( * dop.begin());
        dop.erase(dop.begin());
    }
    for (int i = 0; i < (1 << sizedop); i++)
    {
        set < char > bolean;
        for (int j = 0; j < sizedop; j++)
        {
            if (i & (1 << j)) bolean.insert(a[j]);
        }
        print(bolean);
    }
    return 0;
}

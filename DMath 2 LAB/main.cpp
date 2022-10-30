#include <bits/stdc++.h>

#include <Windows.h>

using namespace std;
typedef long long ll;

set < char > s, u, dop;

void print(set < char > q)
{
    if (!q.size())
    {
        cout << "{} ���� ������� �������\n";
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
    cout << "�������:\n���� �����, ������� ������� �� ������ ����� enter\n";
    cout << "������� ������� ��������� ������ ��������, ���� ������ �������� ��� ������ STOP\n";
    while (1)
    {
        getline(cin, sin);

        if (sin == "STOP") break;

        if (sin.size() > 1)
        {
            cout << "������������ ������!\n";
            continue;
        }

        char x = sin[0];

        if (u.find(x) != u.end())
        {
            cout << "�� ��� ����� ����� �������, ������, ���� �����, �����\n";
            continue;
        }

        u.insert(x);
    }

    cout << "������� ������� ������� ������ ��������, ���� ������ �������� ��� ������ STOP\n";
    while (1)
    {
        getline(cin, sin);

        if (sin == "STOP") break;

        if (sin.size() > 1)
        {
            cout << "������������ ������!\n";
            continue;
        }

        char x = sin[0];

        if (s.find(x) != s.end())
        {
            cout << "�� ��� ����� ����� �������, ������, ���� �����, �����\n";
            continue;
        }

        if (u.find(x) == u.end())
        {
            cout << "������ �������� ���� � ��������, ������, ���� �����, �����\n";
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

    cout << "�� ���������������� ������ ��������� : ";
    for (int i = 0; i < sizeu; i++) cout << U[i];
    cout << "\n";

    cout << "�� ���������������� ������ ������ ������� : ";
    for (int i = 0; i < sizeu; i++) cout << S[i];
    cout << "\n";

    cout << "�� ���������������� ������ ���������� �� ������ ������� : ";
    for (int i = 0; i < sizeu; i++) cout << DOP[i];
    cout << "\n";
    cout << "������� ���������: ";
    print(u);

    cout << "������� ������ �������: ";
    print(s);

    cout << "������� ���������� �� ������ �������: ";
    print(dop);

    cout << "SIZE = " << max(1, sizedop) << "\n";
    cout << "This is ������:\n";

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

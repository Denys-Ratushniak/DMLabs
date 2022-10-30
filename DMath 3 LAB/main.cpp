#include <bits/stdc++.h>

#include <windows.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    set < ld > s1, s2;
    ll f, bad;
    ld x;
    string s;
    cout << "������� ����� ����� �������, ���� �������� �������� ������ STOP" << endl;
    while (cin >> s)
    {
        if (s == "STOP")
        {
            if (s1.size() == 0)
            {
                cout << "������ ���� � ���� ������� �������" << endl;
                continue;
            }
            break;
        }
        f = 0;
        x = 0;
        bad = 0;
        ll k = 0;
        ld dil = 1;
        if (s[0] == '-') f = 1;
        for (int i = f; i < s.size(); i++)
        {
            if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
            {
                bad = 1;
                break;
            }
            if (s[i] == '.') k++;
            if (k == 2)
            {
                bad = 1;
                break;
            }
            if (s[i] != '.' && k == 0) x = x * 10 + s[i] - '0';
            else if (s[i] != '.' && k != 0)
            {
                dil *= 10.0;
                x = x + (s[i] - '0') / dil;
            }
        }
        if (f == 1) x = -x;
        if ((s.size() == 1 && s[0] == '-') || bad == 1 || s[0] == '.')
        {
            cout << "��� ������ �� ��������, ������ �� ���" << endl;
            continue;
        }
        if (s1.find(x) != s1.end())
        {
            cout << "����� ������� ��� � � ������, ������, ���� ����� �����" << endl;
            continue;
        }
        s1.insert(x);
    }
    cout << "������� ����� ����� �������, ���� �������� �������� ������ STOP" << endl;
    while (cin >> s)
    {
        if (s == "STOP")
        {
            if (s2.size() == 0)
            {
                cout << "������ ���� � ���� ������� �������" << endl;
                continue;
            }
            break;
        }
        f = 0;
        x = 0;
        bad = 0;
        ll k = 0;
        ld dil = 1;
        if (s[0] == '-') f = 1;
        for (int i = f; i < s.size(); i++)
        {
            if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
            {
                bad = 1;
                break;
            }
            if (s[i] == '.') k++;

            if (k == 2)
            {
                bad = 1;
                break;
            }

            if (s[i] != '.' && k == 0) x = x * 10 + s[i] - '0';
            else if (s[i] != '.' && k != 0)
            {
                dil *= 10.0;
                x = x + (s[i] - '0') / dil;
            }
        }
        if (f == 1) x = -x;
        if ((s.size() == 1 && s[0] == '-') || bad == 1 || s[0] == '.')
        {
            cout << "��� ������ �� ��������, ������ �� ���" << endl;
            continue;
        }

        if (s2.find(x) != s2.end())
        {
            cout << "����� ������� ��� � � ������, ������, ���� ����� �����" << endl;
            continue;
        }
        s2.insert(x);
    }
    ll isequal = 1;
    for (auto to: s1)
    {
        cout << to << " ";
        if (s2.find(to) == s2.end()) isequal = 0;
    }
    if (s1.size() != s2.size()) isequal = 0;
    cout << endl;
    for (int i = 1; i <= s1.size() * 2; i++) cout << "-";
    cout << endl;
    int i = 0, j, n = s1.size();
    ll a[n + 1][n + 1];
    for (auto to1: s2)
    {
        i++;
        j = 0;
        for (auto to2: s1)
        {
            j++;
            a[i][j] = 0;
            if (to2 < 3 * to1)
            {
                cout << 1 << " ";
                a[i][j] = 1;
            }
            else cout << 0 << " ";
        }
        cout << "| " << to1 << endl;
    }
    if (isequal == 0)
    {
        cout << "������� �� ����������, ���� ��������� ���������� ������� ���������\n";
        return 0;
    }
    ll k1 = 0;
    ll issymetr = 1, isantsymetr = 1, istr = 1, isantr = 1;
    i = 0;
    for (auto to1: s2)
    {
        i++;
        j = 0;
        for (auto to2: s1)
        {
            j++;
            if (to2 < 3 * to1 && i == j) k1++;
            if (to2 < 3 * to1)
            {
                if (a[j][i] == 0) issymetr = 0;
                if (a[j][i] == 1) isantsymetr = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (a[i][j] == 1 && a[j][k] == 1 && a[i][k] == 0) istr = 0;
                if (a[i][j] == 1 && a[j][k] == 1 && a[i][k] == 1) isantr = 0;
            }
        }
    }
    cout << "������ ��������� �:" << endl;
    if (k1 == n) cout << "������������" << endl;
    else if (k1 == 0) cout << "����������������" << endl;
    else cout << "��������������" << endl << "������������������" << endl;

    if (issymetr) cout << "�����������" << endl;
    else if (isantsymetr) cout << "����c����������" << endl;
    else cout << "��c����������" << endl << "������c����������" << endl;

    if (istr) cout << "������������" << endl;
    else if (isantr) cout << "����������������" << endl;
    else cout << "��������������" << endl << "������������������" << endl;
    return 0;
}

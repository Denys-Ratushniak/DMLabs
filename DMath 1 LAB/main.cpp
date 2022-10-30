#include <bits/stdc++.h>

#include <Windows.h>

using namespace std;
string mystr = "(!x~!y)~((z>(x|y))>!z)";

/// 1 - x
/// 2 - y
/// 3 - z
/// 4 - !x
/// 5 - !y
/// 6 - !z
/// 7 - !x~!y
/// 8 - x|y
/// 9 - z>(x|y)
/// 10 - (z>(x|y))>!z
/// 11 - (!x~!y)~((z>(x|y))>!z)

string header[] =
{
    "0",
    "x",
    "y",
    "z",
    "!x",
    "!y",
    "!z",
    "!x~!y",
    "x|y",
    "z>(x|y)",
    "(z>(x|y))>!z",
    "(!x~!y)~((z>(x|y))>!z)"
};
int res[2][2][2][14];

int f(int x, int y, int z)
{
    res[x][y][z][1] = x;
    res[x][y][z][2] = y;
    res[x][y][z][3] = z;
    res[x][y][z][4] = !x;
    res[x][y][z][5] = !y;
    res[x][y][z][6] = !z;
    res[x][y][z][7] = 0;

    if (res[x][y][z][4] == res[x][y][z][5]) res[x][y][z][7] = 1;

    res[x][y][z][8] = (x | y);
    res[x][y][z][9] = res[x][y][z][6] | res[x][y][z][8];
    res[x][y][z][10] = (!res[x][y][z][9]) | res[x][y][z][6];
    res[x][y][z][11] = 0;
    if (res[x][y][z][7] == res[x][y][z][10]) res[x][y][z][11] = 1;

    return res[x][y][z][11];
}
void print()
{
    int all = 92;
    for (int i = 1; i <= all; i++) cout << "-";
    cout << "\n";
    for (int i = 0; i <= 11; i++)
    {
        if (i == 0) cout << "| ";
        else cout << header[i] << " | ";
    }
    cout << "\n";
    for (int i = 1; i <= all; i++) cout << "-";
    cout << "\n";
    int x, y, z;
    for (int j = 0; j <= 7; j++)
    {
        int h = j;
        x = 0, y = 0, z = 0;
        if (h & (1 << 2)) x = 1;
        if (h & (1 << 1)) y = 1;
        if (h & (1 << 0)) z = 1;
        cout << "| " << x << " | " << y << " | " << z << " |";
        for (int i = 4; i <= 11; i++)
        {
            int k = (header[i].size() + 2) / 2;
            for (int q = 1; q <= k; q++) cout << " ";
            cout << res[x][y][z][i];
            for (int q = 1; q <= header[i].size() + 1 - k; q++) cout << " ";
            cout << "|";
        }
        cout << "\n";
        for (int i = 1; i <= all; i++) cout << "-";
        cout << "\n";
    }
}
int main()
{
    // setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    cout << "������ �7\n";
    cout << "� ������������ ��� ���������:\n";
    cout << "& for AND\n";
    cout << "| for OR\n";
    cout << "~ for XNOR\n";
    cout << "> for implication\n";
    cout << "! for NOT\n";
    cout << "���� �� ������ ������� �� ����� ������� �������� ��� ���� ������, ������ 1\n";
    cout << "������, ���� �� ������ ������ �������� ����� ����� � ���������\n�� ������� ��������� ���� ������ ��� ��� ������, ������ 2\n";
    int type;
    cin >> type;
    if (type <= 0 || type >= 3)
    {
        cout << "������������ ���������� ����!\n";
        return 0;;
    }
    if (type == 1)
    {
        int x, y, z;
        for (int i = 0; i <= 7; i++)
        {
            x = 0, y = 0, z = 0;
            if (i & (1 << 2)) x = 1;
            if (i & (1 << 1)) y = 1;
            if (i & (1 << 0)) z = 1;
            f(x, y, z);
        }
        print();
        return 0;
    }
    if (type == 2)
    {
        cout << "������ �������� ������(0 ��� 1) x y z ����� �����\n";
        int x, y, z;
        cin >> x >> y >> z;
        if (x < 0 || x > 1)
        {
            cout << "������ �������� ���!\n";
            return 0;
        }
        if (y < 0 || y > 1)
        {
            cout << "������ �������� ���!\n";
            return 0;
        }
        if (z < 0 || z > 1)
        {
            cout << "������ �������� ���!\n";
            return 0;
        }
        f(x, y, z);
        int all = 92;
        for (int i = 1; i <= all; i++) cout << "-";
        cout << "\n";
        for (int i = 0; i <= 11; i++)
        {
            if (i == 0) cout << "| ";
            else cout << header[i] << " | ";
        }
        cout << "\n";
        for (int i = 1; i <= all; i++) cout << "-";
        cout << "\n";
        cout << "| " << x << " | " << y << " | " << z << " |";
        for (int i = 4; i <= 11; i++)
        {
            int k = (header[i].size() + 2) / 2;
            for (int q = 1; q <= k; q++) cout << " ";
            cout << res[x][y][z][i];
            for (int q = 1; q <= header[i].size() + 1 - k; q++) cout << " ";
            cout << "|";
        }
        cout << "\n";
        for (int i = 1; i <= all; i++) cout << "-";
        cout << "\n";
        return 0;
    }
    return 0;
}

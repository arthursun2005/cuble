// trans rights

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> words;
unordered_map<int, vector<string>> l2, l3;

template <typename T>
T &slct(vector<T> &p)
{
    if (p.empty())
        throw 69;

    return p[rand() % p.size()];
}

pair<string, string> genface(string &a, string &b, string &c, string &d)
{
    vector<pair<string, string>> valid;
    int h = a[2] * 256 + c[2];
    for (auto &p : l2[h])
    {
        int u = b[2] * 256 + d[2] + p[2] * 65536;
        if (not l3[u].empty())
        {
            valid.push_back({p, slct(l3[u])});
        }
    }
    return slct(valid);
}

int main(int argc, const char *argv[])
{
    srand(random_device {} ());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("possible_words.txt", "r", stdin);
    string a;
    while (cin >> a)
    {
        l2[a[0] * 256 + a[4]].push_back(a);
        l3[a[0] * 256 + a[4] + a[2] * 65536].push_back(a);
        words.push_back(a);

        reverse(a.begin(), a.end());

        l2[a[0] * 256 + a[4]].push_back(a);
        l3[a[0] * 256 + a[4] + a[2] * 65536].push_back(a);
        words.push_back(a);
    }
    N = words.size();
    while (true)
    {
        try
        {
            string &a = slct(words);
            string &b = slct(words);
            string &c = slct(words);
            string &d = slct(words);

            string &x1 = slct(l2[a[0] * 256 + b[0]]);
            string &y1 = slct(l2[b[0] * 256 + c[0]]);
            string &z1 = slct(l2[c[0] * 256 + d[0]]);
            string &w1 = slct(l2[d[0] * 256 + a[0]]);

            string &x2 = slct(l2[a[4] * 256 + b[4]]);
            string &y2 = slct(l2[b[4] * 256 + c[4]]);
            string &z2 = slct(l2[c[4] * 256 + d[4]]);
            string &w2 = slct(l2[d[4] * 256 + a[4]]);

            auto A = genface(x1, y1, z1, w1);
            auto B = genface(a, x1, b, x2);
            auto C = genface(b, y1, c, y2);
            auto D = genface(c, z1, d, z2);
            auto E = genface(d, w1, a, w2);
            auto F = genface(x2, y2, z2, w2);

            cout << a << '\n';
            cout << b << '\n';
            cout << c << '\n';
            cout << d << '\n';
            cout << x1 << '\n';
            cout << y1 << '\n';
            cout << z1 << '\n';
            cout << w1 << '\n';
            cout << x2 << '\n';
            cout << y2 << '\n';
            cout << z2 << '\n';
            cout << w2 << '\n';

            cout << A.first << ' ' << A.second << '\n';
            cout << B.first << ' ' << B.second << '\n';
            cout << C.first << ' ' << C.second << '\n';
            cout << D.first << ' ' << D.second << '\n';
            cout << E.first << ' ' << E.second << '\n';
            cout << F.first << ' ' << F.second << '\n';
            return 0;
        } catch(...) {
        }
    }
    return 0;
}


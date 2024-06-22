#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<char,char> m;

    m['-'] = '-';
    m['0'] = '0';
    m['1'] = '1';

    m['A'] = '2';
    m['B'] = '2';
    m['C'] = '2';

    m['D'] = '3';
    m['E'] = '3';
    m['F'] = '3';

    m['G'] = '4';
    m['H'] = '4';
    m['I'] = '4';

    m['J'] = '5';
    m['K'] = '5';
    m['L'] = '5';

    m['M'] = '6';
    m['N'] = '6';
    m['O'] = '6';

    m['P'] = '7';
    m['Q'] = '7';
    m['R'] = '7';
    m['S'] = '7';

    m['T'] = '8';
    m['U'] = '8';
    m['V'] = '8';

    m['W'] = '9';
    m['X'] = '9';
    m['Y'] = '9';
    m['Z'] = '9';
    
    string s;
    while(cin >> s){
        for(int i=0; i<s.size(); i++)
            cout << m[s[i]];
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<char, char> m;
    m['B'] = '1';
    m['P'] = '1';
    m['F'] = '1';
    m['V'] = '1';

    m['C'] = '2';
    m['S'] = '2';
    m['K'] = '2';
    m['G'] = '2';
    m['J'] = '2';
    m['Q'] = '2';
    m['X'] = '2';
    m['Z'] = '2';

    m['D'] = '3';
    m['T'] = '3';

    m['L'] = '4';

    m['M'] = '5';
    m['N'] = '5';

    m['R'] = '6';

    string s;
    cout << setw(9) << "";
    cout << left << setw(25) << "NAME";
    cout << "SOUNDEX CODE\n";
    while(cin >> s){
        cout << setw(9) << "";
        cout << left << setw(25) << s;
        string output;
        output.push_back(s[0]);
        for(int i=1; i<s.size(); i++){
            if(m.find(s[i])==m.end()) continue;
            char c = m[s[i]];
            if(m.find(s[i-1])==m.end()||c!=m[s[i-1]])
                output.push_back(c);
            if(output.size()==4){
                cout << output << '\n';
                break;
            } 
        }
        if(output.size()!=4){
            while(output.size()<4)
                output.push_back('0');
            cout << output << '\n';
        }
    }
    cout << setw(19) << "";
    cout << "END OF OUTPUT\n";
    return 0;
}
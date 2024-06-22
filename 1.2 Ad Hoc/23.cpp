#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, aux;
    cin >> n; 
    while(n--){
        cin >> a;
        cin.ignore();
        char c;
        string s;
        map<char, int> m;
        long long total = 0;
        for(int i=0; i<a; i++){
            cin >> c >> aux;
            cin.ignore();
            m[c] = aux;
        }
        cin >> b;
        cin.ignore();
        for(int i=0; i<b; i++){
            getline(cin, s);
            for(char x: s)
                total += m[x];
        }
        cout << total/100 << '.';
        if(total%100<10) cout << '0';
        cout << total%100 << "$\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cont = 0;
    int a, b, c;
    double d;
    string s;
    while(cin >> a >> b){
        if(!a&&!b) break;
        cin.ignore();
        for(int i=0; i<a; i++) getline(cin, s);
        tuple<string, int, double> best = make_tuple("", 0, 0);
        for(int i=0; i<b; i++) {
            getline(cin, s);
            cin >> d >> c;
            cin.ignore();
            if(c>get<1>(best)||(c==get<1>(best)&&d>get<2>(best))) 
                best = make_tuple(s, c, d);
            for(int j=0; j<c; j++) getline(cin, s);
        }  
        if(cont) cout << '\n';
        cout << "RFP #" << ++cont << '\n';
        cout << get<0>(best) << '\n';
    }
    
    return 0;
}
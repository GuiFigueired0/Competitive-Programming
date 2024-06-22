#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b, c, d;
    while(cin >> a >> b >> c >> d){
        if(!a) break;
        int cont = 0;
        double pos = 0; 
        double fat = d*b/100.0;
        while(1){
            double dist = b - fat*cont;
            //cout << pos << ' ' << dist << '\n';
            if(dist>0) pos += dist;
            if(pos>a){
                cout << "success on day " << cont +1 << '\n';
                break;
            } 
            pos -= c;
            if(pos<0){
                cout << "failure on day " << cont +1 << '\n';
                break;
            }
            cont++;
        }
    }

    
    return 0;
}
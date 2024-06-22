#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(!n) break;
        int aux;
        while(cin >> aux){
            if(!aux) break;
            bool test = true;
            vector<int> v(n);
            v[0] = aux; 
            for(int i=1; i<n; i++) cin >> v[i];
            stack<int> p;
            int maior = 0;
            for(int i=0; i<n; i++){
                int x = v[i];
                for(int j=maior+1; j<=x; j++) p.push(j);
                maior = max(maior, x);
                if(p.top() == x) p.pop(); 
                else {
                    test = false;
                    break;
                }
            }
            if(test) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << '\n';
    }
    return 0;
}

// I'm sending this from another contest that I participated
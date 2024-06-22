#include <vector>
#include <iostream>
using namespace std; 

int func(int x){
    int cont = 1;
    while(x!=1){
        cont++;
        if(x%2 == 0) x/=2;
        else x = 3*x + 1;
    }
    return cont;
}

int main(){
    //vector<int> v(10000);
    //for(int i=0; i<10000; i++) v[i] = func(i+1);
    int a, b; 
    while(cin >> a >> b){
        int c, d;
        if(a>b){
            c = b; 
            d = a;
        } else {
            c = a;
            d = b;
        }
        int maior = 0;
        for(int i=c; i<=d; i++)
            maior = max(maior, func(i)); 
        cout << a << ' ' << b << ' ' << maior << '\n';
    }
}
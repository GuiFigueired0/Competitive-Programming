#include <bits/stdc++.h>
using namespace std;

int calculaCenarios(int cheia, int sobra, int devolucao){
    int n = cheia+sobra;
    if(devolucao>n) return -1;
    if(!cheia) return 0;
    int total = cheia;
    sobra = n%3;
    int melhorCaso = 0; 
    if(sobra){
        int falta = 3-sobra;
        melhorCaso = max(melhorCaso, calculaCenarios((n+falta)/3, 0, devolucao+falta)); 
        melhorCaso = max(melhorCaso, calculaCenarios(n/3, sobra, devolucao)); 
    } else {
        melhorCaso = calculaCenarios(n/3, sobra, devolucao);
    }
    return total + melhorCaso;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(cin >> n)
        cout << calculaCenarios(n, 0, 0) << '\n';
    
    return 0;
}
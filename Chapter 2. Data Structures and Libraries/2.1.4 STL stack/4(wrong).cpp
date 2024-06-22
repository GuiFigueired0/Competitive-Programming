#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    while(n--){
        string output = "";
        stack<int> p;
        int cont = 0;
        while(getline(cin, s)){
            if (s.empty()) break;
            char c = s.front();
            if (c == '(') cont = 0;
            else if (c>='0'&& c<='9') {
                output += c;
                cont++; 
                if (cont%2 == 0) {
                    cont = 0;
                    output += p.top();
                    p.pop();
                }
            } 
            else if (c == ')') {
                output += p.top();
                p.pop();
            }
            else p.push(c);
        }
        while(!p.empty()){
            output += p.top();
            p.pop();
        }
        cout << output << '\n';
        if(n) cout << '\n';
    }
    return 0;
}
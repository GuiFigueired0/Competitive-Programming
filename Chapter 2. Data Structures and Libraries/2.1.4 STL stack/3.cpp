#include <string>
#include <map>
#include <iostream>
#include <stack>
using namespace std;

map<char, char> oposto;

bool verificaParenteses(const string &s, char x, int &pos){
    while(1) {
        ++pos; 
        if(pos==s.size()) return false;
        char c = s[pos];
        if(c=='('||c=='['){
            if(!verificaParenteses(s, c, pos))
                return false;
        } else {
            if(c == oposto[x]) return true;
            else return false;
        } 
    }
}

bool verificaParenteses(const string &s){
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c=='('||c=='['){
            if(!verificaParenteses(s, c, i))
                return false;
        } else return false;
    }
    return true;
}

// Objetivo desse envio: tirar o erro

int main(){
    oposto['('] = ')';
    oposto['['] = ']';

    int n;
    cin >> n;
    cin.ignore();
    string s;
    while(n--){
        getline(cin, s);
        if(verificaParenteses(s)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;   
}
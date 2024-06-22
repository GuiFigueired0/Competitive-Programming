#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    int x;
    while(cin >> x){
        bitset<sizeof(x) * 8> bits(x);
        string s = bits.to_string();
        for(int i=0; i<8; i++)
            swap(s[i], s[i+24]);
        for(int i=8; i<16; i++)
            swap(s[i], s[i+8]);
        std::bitset<sizeof(int) * 8> output(s);
        cout << x << " converts to " << static_cast<int>(output.to_ulong()) << '\n';

    }
    return 0;
}

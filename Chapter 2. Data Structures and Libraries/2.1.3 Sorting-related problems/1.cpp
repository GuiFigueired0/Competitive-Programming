#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int contaBobbleSort(vector<int> &v){
	int cont = 0;
	int n = v.size();
	for(int i=0; i<n; i++){
		bool test = true;
		for(int j=0; j<n-1; j++){
			if (v[j]>v[j+1]){
				cont++;
				test = false;
				swap(v[j], v[j+1]);
			}
		}
		if (test) break;
	}
	return cont;
}

int main() {
	int n;
    cin >> n;
    while(n--){
        int a, aux;
        cin >> a;
        vector<int> v(a);
        for(int i=0; i<a; i++) cin >> v[i];
        cout << "Optimal train swapping takes " << contaBobbleSort(v) << " swaps.\n";
    }
	return 0;   
}
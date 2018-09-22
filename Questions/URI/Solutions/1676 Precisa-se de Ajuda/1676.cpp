#include<bits/stdc++.h>
#define MAXN 35000

using namespace std;
typedef vector<int> vi;

//crivo modificado, utilizei funções do vector

vi fila;

void crivoMod(int n){
	fila.push_back(2);
	for(int i=3; i<n; i+=2)
		fila.push_back(i);
	
	for(int i=1; i<fila.size(); i++)
		for(int j=i+fila[i]; j<fila.size(); j+=fila[i]){
			fila.erase(fila.begin()+j);
			j--;
		}
}

int main(){
	int n;
	crivoMod(MAXN);
	while(scanf("%d", &n) && n)
		cout << fila[n-1] << endl;
	
	
	return 0;
}

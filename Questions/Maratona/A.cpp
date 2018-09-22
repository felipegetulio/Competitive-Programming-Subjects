#include<bits/stdc++.h>
#define MAXN 104
#define inf 1000000000

using namespace std;

int custoIngre[MAXN];

int main(){
	int t, d, l, b, q, ingre, qntIngre, maior, custoBoloAtual;
	cin >> t;
	while(t--){
		maior = -inf;
		cin >> d >> l >> b;
		for(int i=0; i<l; i++)
			cin >> custoIngre[i];
		for(int i=1; i<=b; i++){
			cin >> q;
			custoBoloAtual = 0;
			while(q--){
				cin >> ingre >> qntIngre;
				custoBoloAtual += custoIngre[ingre]*qntIngre;
			}
			maior = max(maior, d/custoBoloAtual);
		}
		cout << maior << endl;
	
	}
	
	

	return 0;
}

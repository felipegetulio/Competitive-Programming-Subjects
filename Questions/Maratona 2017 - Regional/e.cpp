using namespace std;
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100004

string notas[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int inter[] = {2, 2, 1, 2, 2, 2, 1};

int escalas[12];
int freq[12];

void init(){
	int escala;

	for(int i=0; i<12; i++){
		escala = 0;
		for(int j=0, nota=i; j<7; nota = (nota + inter[j++])%12)
			escala |= (1 << nota);
		escalas[i] = escala;
	}
}

int main(){
	int n, tom;
	int musica = 0;

	init();
	scanf("%d", &n);

	while(n--){
		scanf("%d", &tom);
		tom = (tom-1)%12;
		musica |= (1 << tom);
	}

	for(int i=0; i<12; i++){
		if((musica & escalas[i]) == musica){
			cout << notas[i] << endl;
			return 0;
		}
	}

	printf("desafinado\n");


	return 0;
}

#include<cstdio>
#define MAXN 30

using namespace std;

char word[MAXN];

int main(){
	int n, m, qnt;
	scanf("%d", &n);
	while(n--){
		qnt = 0;
		scanf("%d %s", &m, word);
		for(int i=0; i<m; i++)
			qnt += (word[i] != ('A'+i));
		if(qnt == 2) printf("There are the chance.\n");
		else printf("There aren't the chance.\n");
	}


	return 0; 
}

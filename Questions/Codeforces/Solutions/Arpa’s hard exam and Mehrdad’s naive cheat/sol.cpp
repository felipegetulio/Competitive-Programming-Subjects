#include<cstdio>

using namespace std;

int resp[] = {1, 6, 8, 4, 2};
//fiz com associação de vetor
//pode ser resolvida com exponenciação rápida

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n", resp[n%4 + (n!=0)]);
	return 0;
}

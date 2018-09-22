#include<cstdio>
#define MAXN 30

using namespace std;

char word[MAXN];

int main(){
	int n, t = 1;
	while(scanf("%d", &n), n != -1)
		printf("Experiment %d: %d full cycle(s)\n", t++, n/2);
	
	return 0; 
}

#include<cstdio>
#define MAXN 1000

using namespace std;

int xorAteN(int n){
	int ans = n%4;
	switch(ans){
		case 0: return n;
		case 1: return 1;
		case 2: return n+1;
		case 3: return 0;
	}
}

int main(){
	int n, num, ans;
	while(scanf("%d", &n) != EOF){
		ans = xorAteN(n--);
		while(n--){
			scanf("%d", &num);
			ans ^= num;
		}
		printf("%d\n", ans);
	}
	
	return 0; 
}

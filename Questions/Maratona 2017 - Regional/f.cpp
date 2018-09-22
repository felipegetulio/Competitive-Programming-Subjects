using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1004

int freq[MAXN];

int main(){
	int n, k, nota, maiorNota, ans = 0;

	scanf("%d %d", &n, &k);
	scanf("%d", &maiorNota);
	freq[maiorNota]++;

	for(int i=1; i<n; i++){
		scanf("%d", &nota);
		freq[nota]++;
		maiorNota = max(maiorNota, nota);
	}

	for(int i=maiorNota; i>0 && ans<k; i--)
		ans += freq[i];

	printf("%d\n", ans);



	return 0;
}
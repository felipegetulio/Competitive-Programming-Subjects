using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define mmc(a, b) ((a)*((b)/__gcd((a), (b))))



int main(){
	int n, l, ans;
	ll mmcAtual = 1, m, c, maiorMmc = 0;

	scanf("%d%d", &n, &l);

	while(n--){
		scanf("%lld", &c);
		mmcAtual = mmc(mmcAtual, c);
	}

	for(ll i=1; i<=l; i++){
		m = mmc(mmcAtual, i);
		if(m >= mmcAtual && m<=l)
			if(m > maiorMmc){
				maiorMmc = m;
				ans = i;
			}
	}

	printf("%d\n", ans);



	return 0;
}
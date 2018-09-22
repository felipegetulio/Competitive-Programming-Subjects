#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	long long s, n, m, c1, c2, c3;
	long long ans;
	while(scanf("%lld%lld%lld", &s, &n, &m), n!=0 || m!=0 || s!=0){
		scanf("%lld%lld%lld", &c1, &c2, &c3);
		ans = s*c1*abs(c2-c3)/((n+1)*(m+1));
		printf("%lld\n", ans);
	}
	
	
	return 0; 
}

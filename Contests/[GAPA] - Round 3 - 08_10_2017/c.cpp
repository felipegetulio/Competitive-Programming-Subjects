using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define MAXMAT 2
#define identity(a) for(int i=0; i<MAXMAT; i++) for(int j=0; j<MAXMAT; j++) a.mat[i][j] = (i == j)

struct Matrix{
    ll mat[MAXMAT][MAXMAT];
};

Matrix matMult(Matrix a, Matrix b, int mod){
	Matrix ans;
	for(int i=0; i<MAXMAT; i++)
		for(int j=0; j<MAXMAT; j++){
			for(int k = ans.mat[i][j] = 0;  k<MAXMAT; k++)
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            ans.mat[i][j] %= mod;
		}
	return ans;
}

Matrix matPow(Matrix base, ll e, int mod){
	Matrix ans;
    identity(ans);
	while(e){
		if(e&1) ans = matMult(ans, base, mod);
		base = matMult(base, base, mod);
		e>>=1;
	}
	return ans;
}


void init(Matrix &base){
	base.mat[0][0] = 1; base.mat[0][1] = 1;
	base.mat[1][0] = 1; base.mat[1][1] = 0;
}

int main(){
    Matrix base, ans;
    ll n;
    int m;

    while(scanf("%lld %d", &n, &m) != EOF){
        init(base);
        ans = matPow(base, n, 1<<m);
        printf("%lld\n", ans.mat[0][1]);
    }

    return 0;
}

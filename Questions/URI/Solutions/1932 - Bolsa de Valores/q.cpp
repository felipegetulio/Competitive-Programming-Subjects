using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 200004

int cot[MAXN];
int memo[MAXN][2];
int n, c;

int lucro(int ind, int temAcao){
    if(ind == n) return 0;
    if(memo[ind][temAcao] != -1) return memo[ind][temAcao];

    if(temAcao) return memo[ind][temAcao] = max(lucro(ind+1, temAcao), lucro(ind+1, 0) + cot[ind]);
    else return memo[ind][temAcao] = max(lucro(ind+1, temAcao), lucro(ind+1, 1) - cot[ind] - c);
}


void init(int n){
    for(int i=0; i<=n; i++)
        memo[i][0] = memo[i][1] = -1;
}


int main(){_
    scanf("%d%d", &n, &c);
    init(n);
    for(int i=0; i<n; i++)
        scanf("%d", cot+i);
    printf("%d\n", lucro(0, 0));


    return 0;
}

#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 4
#define zerar() for(int i=1; i<MAXN; i++) for(int j=1; j<MAXN; j++) mat[i][j] = 0

using namespace std;

int mat[MAXN][MAXN];
char m[1<<8];

int main(){_
    string a, b;
    int n, cont, menor;
    m['c'] = 1; m['q'] = 2; m['t'] = 3;
    m['u'] = 1; m['d'] = 2;

    while(cin >> n, n){
        zerar();
        cont = 0;
        while(n--){
            cin >> a >> b;
            mat[a[0]][b[0]]++;
        }

        for(int i=1; i<MAXN; i++){
            menor = mat[i][1];
            for(int j=1; j<MAXN; j++){
                cont += mat[i][j]/3;
                menor = min(menor, mat[i][j]);
            }
            cont += menor;
            menor = mat[1][i];
            for(int j=1; j<MAXN; j++){
                menor = min(menor, mat[j][i]);
            }
            cont += menor;
        }
    }

    return 0;
}


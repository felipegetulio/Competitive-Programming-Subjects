using namespace std;
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100004
#define left(u) (u<<1)
#define right(u) ((u<<1)+1)

int v[MAXN], st[4*MAXN];

//Segment Tree Padrão com Update


void buildSegTree(int u, int l, int r){
    if(l == r)
        st[u] = l;
    else{
        buildSegTree(left(u), l, (l+r)/2);
        buildSegTree(right(u), (l+r)/2+1, r);
        int esq = st[left(u)], dir = st[right(u)];
        st[u] = v[esq] < v[dir]? esq:dir;
    }
}

int query(int u, int l, int r, int i, int j){
    if(j<l || r<i) return -1;
    if(i<=l && r<=j) return st[u];

    int esq = query(left(u), l, (l+r)/2, i, j);
    int dir = query(right(u), (l+r)/2+1, r, i, j);

    if(esq == -1) return dir;
    if(dir == -1) return esq;
    return v[esq] < v[dir]? esq:dir;
}

void update(int u, int l, int r, int ind, int valor){
    if(l == r && ind == l)
        v[ind] = valor;
    else{
        if(ind > (l+r)/2)
            update(right(u), (l+r)/2+1, r, ind, valor);
        else
            update(left(u), l, (l+r)/2, ind, valor);
        int esq = st[left(u)], dir = st[right(u)];
        st[u] = v[esq] < v[dir]? esq:dir;
    }
}

int main(){
    int n, m, ri, rj, ind, valor;
    char op;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i=0; i<n; i++)
            scanf("%d ", v+i);

        buildSegTree(1, 0, n-1);
        while(m--){
            scanf("%c", &op);
            if(op == 'Q'){
                scanf("%d%d ", &ri, &rj);
                ind = query(1, 0, n-1, ri, rj);
                printf("%d\n", v[ind]);
            }
            else{
                scanf("%d%d ", &ind, &valor);
                update(1, 0, n-1, ind, valor);
            }
        }
    }

    return 0;
}

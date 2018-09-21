using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100004

int v[MAXN];
int st[4*MAXN], lazy[MAXN];

void buildLazy(int u, int l, int r){
    lazy[u] = 0;
    if(l == r)
        st[u] = l;
    else{
        buildLazy(left(u), l, (l+r)/2);
        buildLazy(right(u), (l+r)/2+1, r);
        int esq = st[left(u)], dir = st[right(u)];
        st[u] = v[esq] < v[dir]? esq:dir;
    }
}

void tryPropagate(int u, int l, int r){
    if(lazy[u]){                  //se não tá atualizado
        if(l != r){               //se não é folha
            lazy[left(u)] += lazy[u];
            lazy[right(u)] += lazy[u];

    }
}

int query(int u, int l, int r, int i, int j){
    tryPropagate(u, l, r);
    if(l>j || r<i) return -1;
    if(i<=l && r<=j) return st[u];

    int esq = query(left(u), l, (l+r)/2, i, j);
    int dir = query(right(u), (l+r)/2+1, r, i, j);

    if(esq == -1) return dir;
    if(dir == -1) return esq;

    return v[esq] < v[dir]? esq:dir; //para o menor entre (i, j)
}


int main(){


    return 0;
}

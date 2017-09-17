# include <cstdio>
# include <vector>
# include <cstring>
# define NR 305
# define MOD 666013
using namespace std;
vector <int> v[NR], vt[NR], V[NR];
int i,j,n,m,x,y,CompTareConexa,a,b,c,VV,K,k,S;
int drum[NR][NR], ap[NR], st[NR], CTC[NR], noduri[NR], radacina[NR];
long long DP[NR][NR], nou[NR], Solutie[NR];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
    st[++VV]=k;
}
void DFSt (int k)
{
    ap[k]=1; CTC[k]=CompTareConexa; ++noduri[CompTareConexa];
    for (int i=0; i<vt[k].size(); ++i)
        if (! ap[vt[k][i]]) DFSt (vt[k][i]);
}

void uneste (int x, int y) //x e radacina
{
    memset (nou, 0, sizeof(nou));

    for (int i=0; i<=K; ++i)
        for (int j=1; j<=K; ++j)
        if (i+j<=K) nou[i+j]=nou[i+j] + DP[x][i]*DP[y][j];

    for (int i=1; i<=K; ++i)
        DP[x][i]=(DP[x][i] + nou[i])%MOD;
}

void Dinamica (int k)
{
    //DP[i][j] - numarul de moduri de a alege j elemente unite de radacina indirect din nodul i
    DP[k][noduri[k]]=1;
    for (int i=0; i<V[k].size(); ++i) {
        Dinamica (V[k][i]);
        //trebuie sa unesc noua solutie cu precedentele

        uneste (k, V[k][i]);
    }

}
int main ()
{
    freopen ("dep.in", "r", stdin);
    freopen ("dep.out", "w", stdout);

    scanf ("%d%d%d", &n, &m, &K);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        vt[y].push_back(x);
    }

    // incepem sa compactam componentele tare conexe
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);
    memset (ap, 0, sizeof(ap));

    for (i=n; i>=1; --i)
        if (! ap[st[i]]) {
            ++CompTareConexa;
            DFSt (st[i]);
        }

    //fac noul graf compactat
    for (i=1; i<=n; ++i)
        for (j=0; j<v[i].size(); ++j)
            if (CTC[i]!=CTC[v[i][j]]) drum[CTC[i]][CTC[v[i][j]]]=1;

    //facem toate conexiunile indirecte
    for (k=1; k<=CompTareConexa; ++k)
        for (i=1; i<=CompTareConexa; ++i)
            for (j=1; j<=CompTareConexa; ++j)
                if (i!=j && drum[i][k] && drum[k][j]) drum[i][j]=1;

    //scapam de muchie in plus
    for (a=1; a<=CompTareConexa; ++a)
        for (b=1; b<=CompTareConexa; ++b)
            for (c=1; c<=CompTareConexa; ++c)
                if (drum[a][b] && drum[a][c]) {
                    if (drum[b][c]) drum[a][c]=0;
                    else if (drum[c][b]) drum[a][b]=0;
                }

    //acum avem mai multi arbori orientati
    // -> trebuie sa facem graful transpus, dupa care sa aplicam dinamica

    for (i=1; i<=CompTareConexa; ++i) {
        S=0;
        for (j=1; j<=CompTareConexa; ++j)
            if (drum[i][j]) {++S; V[j].push_back(i);}
        if (S==0) radacina[i]=1;
    }
//////////////////////////////////////////////////////////////////////////
    //incepem dinamica
    Solutie[0]=1;
    for (i=1; i<=CompTareConexa; ++i)
        if (radacina[i])
        {
            Dinamica (i);

            //unim si solutiile dintre arbori diferiti
            memset (nou, 0, sizeof(nou));

            for (int o=0; o<=K; ++o)
                for (int j=1; j<=K; ++j)
                if (o+j<=K) nou[o+j]=nou[o+j] + Solutie[o]*DP[i][j];

            for (int o=1; o<=K; ++o)
                Solutie[o]=(Solutie[o] + nou[o])%MOD;
        }
    printf ("%d\n", Solutie[K]);


    return 0;
}

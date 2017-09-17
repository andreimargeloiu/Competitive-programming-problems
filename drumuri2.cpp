# include <cstdio>
# include <vector>
# include <algorithm>
# include <cstring>
# define NR 60505
using namespace std;
vector <int> v[NR], vt[NR], noduri[NR], tare[NR];
int i,j,n,m,tconexe,VV,x,y,o,nod,maxx,nrsol;
int comp[NR],ant[NR],in[NR],dist[NR],sol[NR],st[NR],ap[NR];
struct elem
{
    int nr, val;
}E;

void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
    ant[++VV]=k;
}
void DFSt (int k)
{
    ap[k]=0; comp[k]=tconexe;
    noduri[tconexe].push_back(k);
    for (int i=0; i<vt[k].size(); ++i)
        if (ap[vt[k][i]]==1) DFSt (vt[k][i]);
}
void DF (int k)
{
    ap[k]=1;
    for (int i=0; i<tare[k].size(); ++i)
    {
        if (! ap[tare[k][i]]) DF (tare[k][i]);
        dist[k]=max(dist[k], 1+dist[tare[k][i]]);
    }
}

void procesare ()
{
    int i,stiva=0,var=0;
    //incep sa fac trierile
    VV=0;
    for (i=1; i<=tconexe; ++i)
        if (in[i]==0) st[++VV]=i;
    while (VV)
    {
        if (VV==1) //e solutie
        {
            for (i=0; i<noduri[st[1]].size(); ++i)
                sol[++nrsol]=noduri[st[1]][i];
        }

        maxx=0; var=0;
        for (i=1; i<=VV; ++i)
            if (dist[st[i]]>maxx) maxx=dist[st[i]];

        for (i=1; i<=VV; ++i)
        {
            if (dist[st[i]]==maxx)//daca are distanta maxima
            {
                for (j=0; j<tare[st[i]].size(); ++j)
                {
                    --in[tare[st[i]][j]];
                    if (! in[tare[st[i]][j]]) st[++VV]=tare[st[i]][j];
                }
            }
            else//daca nu are distanta maxima il lasam in stiva
                st[++var]=st[i];
        }
        VV=var;
    }
}

int main ()
{
    freopen ("drumuri2.in", "r", stdin);
    freopen ("drumuri2.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);
    //fac pe transpus
    for (i=n; i>=1; --i)
        if (ap[ant[i]]==1) //inca nu l-am parcurs pe G transpus
        {
            ++tconexe;
            DFSt(ant[i]);
        }
    //for (i=1; i<=n; ++i) printf ("%d ", comp[i]);
    //printf ("\n");

    //facem graful componentelor conexe
    //vectorul ap este cu 0
    for (i=1; i<=tconexe; ++i)//luam fiecare componenta conexa
    {
        for (j=0; j<noduri[i].size(); ++j)//pentru fiecare nod din componenta tare conexa
        {
            nod=noduri[i][j];
            for (o=0; o<v[nod].size(); ++o)//verific vecinii
                if (ap[comp[v[nod][o]]]!=i)//daca e intr-o componenta tare conexa nevizitate
                {
                    ap[comp[v[nod][o]]]=i; ++in[comp[v[nod][o]]];
                    tare[i].push_back(comp[v[nod][o]]);
                }
        }
    }
    memset(ap, 0, sizeof(ap));
    for (i=1; i<=tconexe; ++i)//facem distanta maxima
        if (!ap[i]) DF (i);

    procesare ();

    //afisarea
    sort (sol+1, sol+nrsol+1);
    printf ("%d\n", nrsol);
    for (i=1; i<=nrsol; ++i)
        printf ("%d ", sol[i]);

    return 0;

}

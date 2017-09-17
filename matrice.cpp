# include <cstdio>
# include <vector>
# include <algorithm>
# define inf 999999999
# define NR 305
using namespace std;
vector <int> v[NR*NR];
struct elem
{
    int nod1,nod2,nr,i;
}Q[20005];
bool cmp (elem x, elem y)
{
    if (x.nr<=y.nr) return 0;
               else return 1;
}
bool cmp2 (elem x, elem y)
{
    if (x.i>=y.i) return 0;
            else  return 1;
}

int i,j,n,m,x,y,nrq,x2,y2,ci,PLUS,noduri;
int H[NR*NR], R[NR*NR], a[NR][NR], VAL[NR*NR], N[NR*NR];

bool cmp3 (int x, int y)
{
    if (VAL[x]<=VAL[y]) return 0;
                  else  return 1;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int nod (int x, int y)
{
    return (x-1)*n + y;
}
void muchii ()
{
    int i,j,k,lv,cv,nr;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            nr=nod (i, j);
            N[nr]=nr; VAL[nr]=a[i][j];

            for (k=0; k<4; ++k)
            {
                lv=i+dx[k]; cv=j+dy[k];
                if (a[lv][cv]) v[nr].push_back(nod(lv, cv));
            }
        }
}
void curata()
{
    for (int i=1; i<=noduri; ++i)
        R[i]=i, H[i]=1;
}
int radacina (int k)
{
    while (R[k]!=k) k=R[k];
    return k;
}
void avansare (int stop)
{
    int Rx, Ry, urm;
    while (VAL[N[ci+1]]>=stop)
    {
        int k=N[ci+1];
        for (int i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i];
            if (VAL[urm]>=stop)
            {
                Rx=radacina (urm);
                Ry=radacina (k);
                if (Rx!=Ry)
                {
                    if (H[Rx]>H[Ry]) H[Rx]+=H[Ry], R[Ry]=Rx;
                                else H[Ry]+=H[Rx], R[Rx]=Ry;
                }
            }
        }
        ++ci;
    }
}
int main ()
{
    freopen ("matrice.in", "r", stdin);
    freopen ("matrice.out", "w", stdout);
    scanf ("%d%d", &n, &nrq);
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            scanf ("%d", &a[i][j]);

    for (i=1; i<=nrq; ++i)
    {
        scanf ("%d%d%d%d", &x, &y, &x2, &y2);
        Q[i].nod1=nod(x, y); Q[i].nod2=nod(x2, y2);
        Q[i].i=i;
    }

    noduri=n*n;

    muchii ();
    sort (N+1, N+noduri+1, cmp3); //descrescator


    for (i=20; i>=0; --i)
    {
        curata (); PLUS=(1<<i);
        sort (Q+1, Q+nrq+1, cmp);

        ci=0;
        for (j=1; j<=nrq; ++j)
        {
            avansare (Q[j].nr+PLUS);
            if (radacina(Q[j].nod1)==radacina(Q[j].nod2))
            {
                Q[j].nr+=PLUS;
            }
        }
    }

    sort (Q+1, Q+nrq+1, cmp2);
    for (i=1; i<=nrq; ++i)
        printf ("%d\n", Q[i].nr);

    return 0;
}

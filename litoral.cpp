# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
# define NR 1005
# define inf 999999999
using namespace std;
struct muchie
{
    int y, cost;
}E;
vector <muchie> v[NR];
queue <int> q;
struct elem
{
    int timp, cost;
}a[NR], b[NR];
struct elem2
{
    int tip, a, b, cost;
}S[NR];
bool cmp (elem x, elem y)
{
    if (x.timp>=y.timp) return 0;
                   else return 1;
}

int i,j,n,m,x,y,oa,ob,ma,mb,nta,ntb,h,ns,tip,ha,hb,cost,R,TA,TB;
int C[NR];

void citire ()
{
    int i;
    scanf ("%d%d", &oa, &ma); TA=oa*60+ma;
    scanf ("%d%d", &ob, &mb); TB=ob*60+mb;
    scanf ("%d%d", &nta, &ntb);
    for (i=1; i<=nta; ++i)
    {
        scanf ("%d%d%d", &h, &m, &a[i].cost);
        a[i].timp=h*60+m;
    }
    for (i=1; i<=ntb; ++i)
    {
        scanf ("%d%d%d", &h, &m, &b[i].cost);
        b[i].timp=h*60+m;
    }
    sort (a+1, a+nta+1, cmp);
    sort (b+1, b+ntb+1, cmp);

    scanf ("%d", &ns);
    for (i=1; i<=ns; ++i)
    {
        scanf ("%d%d%d%d%d%d", &tip, &ha, &ma, &hb, &mb, &cost);
        S[i].tip=tip; S[i].a=ha*60+ma; S[i].b=hb*60+mb; S[i].cost=cost;
    }
}
void muchie (int k, int y, int cost)
{
    E.y=y; E.cost=cost;
    v[k].push_back(E);
}
int taxaA (int ci, int cs)
{
    int taxa=0;
    for (int i=1; i<=nta; ++i)
        if (ci<=a[i].timp && a[i].timp<=cs) taxa+=a[i].cost;

    return taxa;
}
int taxaB (int ci, int cs)
{
    int taxa=0;
    for (int i=1; i<=ntb; ++i)
        if (ci<=b[i].timp && b[i].timp<=cs) taxa+=b[i].cost;

    return taxa;
}
void procesare ()
{
    int i,j;
    // malul A
    for (i=1; i<=ns; ++i)
        if (S[i].tip==0 && S[i].a>=TA) //daca pleaca de pe A
            muchie (0, i, taxaA (TA, S[i].a));

    for (i=1; i<=ns; ++i)
        for (j=1; j<=ns; ++j)
            if (S[i].tip==1 && S[j].tip==0 && i!=j && S[i].a<=S[j].a)
                muchie (i, j, taxaA (S[i].a, S[j].a));

    // malul B
    for (i=1; i<=ns; ++i)
        if (S[i].tip==0 && S[i].b<=TB) //daca ajunge de pe B
            muchie (ns+i, R, taxaB (S[i].b, TB));

    for (i=1; i<=ns; ++i)
        for (j=1; j<=ns; ++j)
            if (S[i].tip==0 && S[j].tip==1 && i!=j && S[i].b<=S[j].b)
                muchie (ns+i, ns+j, taxaB (S[i].b, S[j].b));

    //salupele
    for (i=1; i<=ns; ++i)
        if (S[i].tip==0) muchie (i, ns+i, S[i].cost);
                    else muchie (ns+i, i, S[i].cost);
}
void BF ()
{
    int i,k;
    for (i=1; i<=2*ns+1; ++i)
        C[i]=inf;

    q.push(0);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            int urm=v[k][i].y, cost=v[k][i].cost;
            if (C[urm]>C[k] + cost)
            {
                C[urm]=C[k] + cost;
                q.push(urm);
            }
        }
    }
}
int main ()
{
    freopen ("litoral.in", "r", stdin);
    freopen ("litoral.out", "w", stdout);

    citire ();
    R=2*ns+1;
    procesare ();
    BF ();

    printf ("%d\n", C[R]);

    return 0;
}

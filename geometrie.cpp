# include <fstream>
# include <algorithm>
# include <iomanip>
# define NMAX 100005
using namespace std;
ifstream f("geometrie.in");
ofstream g("geometrie.out");
int n,m,k,lg,i,j,ok;
double a[NMAX];
double aria;

struct punct
{
    int x,y;
}v[NMAX], st[NMAX], v1[NMAX];

struct query
{
    int x,y,ind;
    double sol;
}q[NMAX];

int cmp(query x, query y)
{
    if (x.x >= y.x) return 0;
               else return 1;
}

int cmp1(query x, query y)
{
    if (x.ind >= y.ind) return 0;
                   else return 1;
}

int cmp4 (punct x, punct y)
{
    if (x.x >= y.x) return 0;
               else return 1;
}

double calcarie()
{
    double sol = 0;
    st[0]=st[k];

     for(int i=0; i<k; ++i)
        sol += (st[i].x*st[i+1].y - st[i+1].x*st[i].y);

    return (sol/2.0);
}

void copiaza()
{
    for(int i = 1; i <= k; ++i)
        v1[i]=st[i];
    lg = k;
}

int determinant(punct a,punct b,punct c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmp2(punct p,punct r)
{
    return determinant(st[1],p,r) < 0;
}

void infasuratoare()
{
    copiaza();
    k = 2; st[1]=v1[1]; st[2]=v1[2];
    for(int i = 3; i <= lg; ++i)
    {
        while( k >= 2 && determinant(st[k-1],st[k],v1[i])<=0) --k;
        st[++k]=v1[i];
    }
}



int main()
{
    f>>n>>m;

    for(int i = 1; i <= n; ++i)
        f>>v[i].x>>v[i].y;

    sort(v+1, v+n+1, cmp4);

    i = 1;
    while(i <= n)
    {
        j = i; ok=1;
        while(v[i].x == v[j].x && j <= n)
        {
            ++k;
            st[k]=v[j];
            if (v[j].y < st[1].y) swap(st[k],st[1]);
            ++j;
        }
        if(ok == 1) a[i]=aria;
        else
        {
            sort(st+1, st+k+1, cmp2);
            infasuratoare();
            aria = calcarie();
            a[i]=aria;
        }
        i = j;
    }

    for(int i = 1; i <= m; ++i)
    {
        f>>q[i].x>>q[i].y;
        q[i].ind = i;
    }

    sort(q+1, q+m+1, cmp);

    i = 1; j = 1;
    while(i <= n && j <= m)
    {
        ok = 0;
        while(v[i].x <= q[j].y) {++i; ok=1;}
        if (ok == 1) --i;
        q[j].sol=a[i];
        ++j;
    }

    sort(q+1, q+m+1, cmp1);
    for(int i = 1; i <= m; ++i)
        g<<fixed<<setprecision(1)<<q[i].sol<<"\n";

    return 0;
}

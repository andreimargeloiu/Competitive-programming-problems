# include <cstdio>
# include <bitset>
# include <queue>
# define N_Max 1000005
using namespace std;
bitset <1000005> p;
int i,j,n,m,K,nrdiv;
int a[100005],fact[100],viz[1000005];
long long A,B;
struct elem
{
    int nr, nru, prod;
}E;
queue <elem> q;
void ciur ()
{
    int i,j;
    a[1]=2; K=1;
    for (i=3; i<=N_Max; i=i+2)
    {
        if (! p[i])
        {
            a[++K]=i;
            for (j=3; i*j<=N_Max; j=j+2)
                p[i*j]=1;
        }
    }
}
void divizori (long long k)
{
    int i=1; nrdiv=0;
    while (k>1)
    {
        if (i==K)
        {
            fact[++nrdiv]=k;
            break;
        }
        if (k%a[i]==0)
        {
            fact[++nrdiv]=a[i];
            while (k%a[i]==0) k=k/a[i];
        }
        ++i;
    }
}
void calculeaza (int o)
{
    int i,j,nr,nru,nrnext,nrunext;
    long long R=0,prod,prodnext;
    E.nr=0; E.nru=0; E.prod=1;
    q.push(E);
    while (! q.empty())
    {
        E=q.front (); q.pop();
        nr=E.nr; nru=E.nru; prod=E.prod;
        for (i=1; i<=nrdiv; ++i)
        {
            if ( !(nr&(1<<(i-1))))
            {
                nrnext=nr+(1<<(i-1)); nrunext=nru+1; prodnext=prod*fact[i];
                if (viz[nrnext]==o) continue;
                E.nr=nrnext; E.nru=nrunext; E.prod=prodnext;
                viz[nrnext]=o;
                q.push(E);
                if (nrunext%2==1) R+=A/prodnext;
                   else R-=A/prodnext;
            }
        }
    }
    printf ("%lld\n", A-R);
}
int main ()
{
    freopen ("pinex.in", "r", stdin);
    freopen ("pinex.out", "w", stdout);
    ciur ();
    scanf ("%d", &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%lld%lld", &A, &B);
        divizori (B);
        calculeaza (i);
    }
    return 0;
}

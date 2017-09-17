# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 100005
# define mod 1999999973
using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
int i,j,n,m,S,ci,cs,mij,a,b,tip,c,ok,x;
int AIB[NR];
void update (int poz, int val)
{
    for (int i=poz; i<=n; i+=LB(i))
        AIB[i]+=val;
}
int suma (int poz)
{
    int S=0;
    for (int i=poz; i>=1; i-=LB(i))
        S+=AIB[i];
    return S;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        update (i, x);
    }
    for (i=1; i<=m; ++i)
    {
        f>>tip;
        if (tip==0) //update
        {
            f>>a>>b;
            update (a, b);
        }
        else if (tip==1) //suma
        {
            f>>a>>b;
            g<<suma(b)-suma(a-1)<<"\n";
        }
        else
        {
            f>>a;
            ci=1; cs=n; ok=0;
            while (ci<=cs)
            {
                mij=(ci+cs)/2;
                S=suma(mij);
                if (S==a) {g<<mij<<"\n"; ok=1; break;}
                else if (S<a) ci=mij+1;
                         else cs=mij-1;
            }
            if (! ok) g<<"-1\n";
        }
    }

    return 0;
}

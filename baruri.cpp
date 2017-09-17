# include <fstream>
# include <algorithm>
# define LB(p) ((-p)&p)
using namespace std;
ifstream f("baruri.in");
ofstream g("baruri.out");
int i,j,n,m,t,S,d,X,tip,B,B1,B2;
int AIB[100005], a[100005];
void actualizeaza (int poz, int val)
{
    a[poz]+=val;
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
    f>>t; ++t;
    while (--t)
    {
        f>>n;
        for (i=1; i<=n; ++i) AIB[i]=0, a[i]=0;
        for (i=1; i<=n; ++i)
            { f>>X; actualizeaza (i, X); }

        f>>m;
        for (i=1; i<=m; ++i)
        {
            f>>tip;
            if (tip==0)
            {
                f>>B>>d;
                S=suma(min(n,B+d))-a[B];
                S-=suma(max(0,B-d-1));

                g<<S<<"\n";
            }
            else if (tip==1)
            {
                f>>X>>B;
                actualizeaza (B, X);
            }
            else if (tip==2)
            {
                f>>X>>B;
                actualizeaza(B, -X);
            }
            else if (tip==3)
            {
                f>>X>>B1>>B2;
                actualizeaza (B1, -X);
                actualizeaza (B2, X);
            }
        }
    }


    return 0;
}

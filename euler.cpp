# include <fstream>
# define NR 550000
using namespace std;
ifstream f("euler.in");
ofstream g("euler.out");
int i,j,n,m,x,R,VV;
int T[NR], st[NR];
int main ()
{
    f>>n;
    f>>x; R=x; st[++VV]=R;//radacina
    while (f>>x)
    {
        if (x==st[VV])
        {
            g<<"NU\n";
            return 0;
        }

        if (x==st[VV-1]) --VV;
        else {
                T[x]=st[VV];
                st[++VV]=x;
             }
    }
    if (x==R && VV==1)
    {
       g<<"DA\n";
       for (i=1; i<=n; ++i)
           g<<T[i]<<" ";
       g<<"\n";
    }
    else g<<"NU\n";

    return 0;
}

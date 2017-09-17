# include <fstream>
# include <algorithm>
# define NR 4005
using namespace std;
ifstream f("cuburi3.in");
ofstream g("cuburi3.out");
int i,j,n,m,x,y,VV,ci,cs,F,mij,S,maxx,I;
int ant[NR],sol[NR],suma[NR];
struct elem
{
    int l, g, i;
}E,a[NR];
bool cmp (elem x, elem y)
{
    if (x.l<y.l) return 0;
        else if (x.l==y.l && x.g<=y.g) return 0;
            else return 1;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i].l>>a[i].g; a[i].i=i;
    }

    sort (a+1, a+n+1, cmp);
    for (i=1; i<=n; ++i)
    {
        suma[i]=a[i].l;
        for (j=i-1; j>=1; --j)
        {
            if (a[j].g>=a[i].g && suma[j]+a[i].l>suma[i])
                ant[i]=j, suma[i]=suma[j]+a[i].l;
        }
    }

    for (i=1; i<=n; ++i)
        if (suma[i]>maxx) maxx=suma[i], I=i;

    //afisarea
    S=suma[I];
    while (ant[I]!=0)
    {
        sol[++VV]=I;
        I=ant[I];
    }
    sol[++VV]=I;

    g<<VV<<" "<<S<<"\n";
    for (i=VV; i>=1; --i)
    {
        g<<a[sol[i]].i<<"\n";
    }

    return 0;
}

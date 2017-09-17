# include <fstream>
# define LB(p) ((-p) & p)
using namespace std;
ifstream f("datorii.in");
ofstream g("datorii.out");
int i,j,n,m,x,tip,zi,S,ci,cs;
int AIB[15005];
void update (int poz, int val)
{
    for (int i=poz; i<=n; i+=LB(i))
        AIB[i]+=val;
}
int suma (int poz)
{
    int sum=0;
    for (int i=poz; i>0; i-=LB(i))
        sum+=AIB[i];
    return sum;
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
        if (tip==0) // se achita
        {
            f>>zi>>S;
            update(zi, -S);
        }
        else if (tip==1)
        {
            f>>ci>>cs;
            g<<suma(cs)-suma(ci-1)<<"\n";
        }
    }

    return 0;
}

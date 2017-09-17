# include <fstream>
# define LB(p) ((-p) & p)
using namespace std;
ifstream f("strategie.in");
ofstream g("strategie.out");
int i,j,n,m,r;
int a[100],AIB[100];
long long nr, VV;
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
    f>>n;
    for (i=1; i<=n; ++i)
        {f>>a[i]; update(i, 1);}

    for (i=1; i<=n; ++i)
    {
        r=suma(a[i]-1);
        if (r) //daca sunt elemente care trebuiau sa fie in fata lui
        {
            nr=1; //factorialul
            for (j=1; j<=n-i; ++j)
                nr=1LL*nr*j;
            VV+=(1LL*r*nr);
        }
        update (a[i], -1);
    }
    g<<VV+1<<"\n";
    return 0;
}

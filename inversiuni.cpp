# include <fstream>
# include <algorithm>
# define N 1000005
# define LB(p) ((-p)& p)
using namespace std;
ifstream f("inversiuni.in");
ofstream g("inversiuni.out");
int AIB[N],n,i,a[N];
long long VV;
void suma(int poz)
{
    long long S=0;
    for (int i=poz; i>0; i-=LB(i))
        S+=AIB[i];
    VV+=S;
}
void adauga (int poz, int val)
{
    for (int i=poz; i<=n; i+=LB(i))
        AIB[i]+=val;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (i=n; i>=1; --i)
    {
        suma(a[i]-1);
        adauga(a[i], 1);
    }
    g<<VV<<"\n";
    return 0;
}


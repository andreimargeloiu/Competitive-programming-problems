# include <fstream>
# include <algorithm>
# define LB(p) ((-p)&p)
using namespace std;
ifstream f("costperm.in");
ofstream g("costperm.out");
int i,j,n,x;
long long AIB[100005], sol;
long long suma (int poz)
{
    long long S=0;
    for (int i=poz; i>=1; i-=LB(i))
        S+=AIB[i];
    return S;
}
void update (int poz)
{
    for (int i=poz; i<=n; i+=LB(i))
        ++AIB[i];
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        sol=sol+1LL*x*(suma(n)-suma(x-1));
        update (x);
    }
    g<<sol<<"\n";

    return 0;
}

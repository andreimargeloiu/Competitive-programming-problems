# include <fstream>
using namespace std;
ifstream f("suma.in");
ofstream g("suma.out");
int n,p,i,S,S2;
int v[5];
int main ()
{
    f>>n>>p;
    v[1]=n; v[2]=n+1; v[3]=2*n+1;
    for (i=1; i<=3; ++i)
        if (v[i]%2==0) {v[i]/=2; break;}
    for (i=1; i<=3; ++i)
        if (v[i]%3==0) {v[i]/=3; break;}
    S=(((v[1]%p)*(v[2]%p))%p)*(v[3]%p);
    S%=p;

    v[1]=n; v[2]=n+1;
    if (v[1]%2==0) v[1]=v[1]/2;
        else v[2]=v[2]/2;
    S2=(v[1]%p)*(v[2]%p);
    S2%=p;

    S=(p+S-S2)%p;
    g<<S<<"\n";
    return 0;
}

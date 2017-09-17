# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("proc.in");
ofstream g("proc.out");
int i,j,n,m,mij,ci,cs,unu,doi,p,sol;
bool verificare (int G)
{
    int U=unu, D=doi,timp,pot;
    for (int i=1; i<=p; ++i)
    {
        timp=0;
        if (D)
        {
            pot=G/i/2;
            timp=2*i*min(D, pot);
            D-=min(D, pot);
        }
        if (U)
        {
            pot=(G-timp)/i;
            U-=min(U, pot);
        }
    }
    if (U || D) return 0;
           else return 1;
}
int main ()
{
    f>>n>>unu>>p;
    doi=n-unu;

    ci=0; cs=unu+2*doi;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verificare (mij)) sol=mij, cs=mij-1;
                        else  ci=mij+1;
    }
    g<<sol<<"\n";

    return 0;
}

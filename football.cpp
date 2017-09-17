# include <fstream>
using namespace std;
ifstream f("football.in");
ofstream g("football.out");
int i,j,n,m,o,t,S,sol[50];
void procesare ()
{
    int i;
    sol[1]=1; sol[2]=1; sol[3]=1; sol[6]=1;
    for (i=1; i<=50; ++i)
    {
        sol[i]+=sol[i-1];
        if (i>=2) sol[i]+=sol[i-2];
        if (i>=3) sol[i]+=sol[i-3];
        if (i>=6) sol[i]+=sol[i-6];
    }
}
int main ()
{
    f>>t;
    procesare ();
    for (o=1; o<=t; ++o)
    {
        f>>S;
        g<<"Case "<<o<<":"<<" "<<sol[S]<<"\n";
    }
    return 0;
}

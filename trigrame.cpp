# include <fstream>
# include <cstring>
# define mil 1000005
using namespace std;
ifstream f("trigrame.in");
ofstream g("trigrame.out");
int i,j,n,m,L,maxx,N,nr1,nr2,nr3,K,l,q;
int ap[200], VV[70][70][70];
char ch;
void verif (int nr1, int nr2, int nr3)
{
    ++VV[nr1][nr2][nr3];
    if (VV[nr1][nr2][nr3]==1) ++N;
    if (VV[nr1][nr2][nr3]>maxx) maxx=VV[nr1][nr2][nr3],K=1;
        else if (VV[nr1][nr2][nr3]==maxx) ++K;
}
int main ()
{
    for (i=1; i<=3; ++i)
    {
        f>>ch;
        if (! ap[ch]) ap[ch]=++q;
        if (i==1) nr1=ap[ch];
            else if (i==2) nr2=ap[ch];
                else nr3=ap[ch];
    }
    verif(nr1,nr2,nr3);

    while (f>>ch)
    {
        if (! ap[ch]) ap[ch]=++q;
        nr1=nr2; nr2=nr3; nr3=ap[ch];
        verif(nr1,nr2,nr3);
    }
    g<<N<<" "<<maxx<<" "<<K<<"\n";

    return 0;
}

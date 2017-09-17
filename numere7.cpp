# include <fstream>
# include <algorithm>
# include <cstring>
using namespace std;
ifstream f("numere7.in");
ofstream g("numere7.out");
int i,j,n,mx,y,VV,nrsol,NR,nrc;
int ap[15], sol[25];
unsigned long long fact[25], X, F, nr;
long long factorial ()
{
    long long S=fact[nrc-1];
    for (int j=1; j<=9; ++j)
        S/=fact[ap[j]];
    return S;
}
char s[25];
int main ()
{
    f>>X; f.get(); f.getline (s+1, 25); VV=strlen(s+1);
    for (i=1; i<=VV; ++i)
        ++ap[s[i]-'0'];

    fact[0]=1; nrc=VV;
    for (i=1; i<=24; ++i)
        fact[i]=fact[i-1]*i;

    for (i=1; i<=VV; ++i)
    {
        for (j=1; j<=9; ++j)
            if (ap[j])
            {
                --ap[j];
                F=factorial ();
                ++ap[j];

                if (X<=F) //daca aceasta este cifra cautata
                {
                    --ap[j]; --nrc;
                    sol[++nrsol]=j;
                    break;
                }
                else {
                         X-=F;
                     }
            }
    }
    if (X==1)
    {
        for (i=1; i<=VV; ++i)
            g<<sol[i];
        g<<"\n";
    }
    else g<<"-1\n";

    return 0;
}

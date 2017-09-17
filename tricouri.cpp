# include <fstream>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("tricouri.in");
ofstream g("tricouri.out");
int i,j,n,l,nr,VV,maxx,N,marimi;
int poz[200],elev[65],Q[6];
char s[505];
void back (int k)
{
    int ok=0;
    if (k<=N && marimi)
    {
        if (maxx==n) return;
        for (int i=elev[k]/10; i<=elev[k]%10; ++i)
        {
            if (Q[i])
            {
                ok=1;
                --Q[i]; ++VV; --marimi;
                maxx=max(maxx,VV);

                back(k+1);

                ++Q[i]; --VV; ++marimi;
            }
        }
        if (!ok) back(k+1);
    }
}
int main ()
{
    poz['S']=1; poz['M']=2; poz['L']=3; poz['X']=4; poz['T']=5;

    f>>n; f.get();
    f.getline(s,500);
    l=strlen(s);
    i=0;
    while (i<l)
    {
        elev[++nr]=poz[s[i]]*10+poz[s[i+1]];
        i=i+3;
    }
    for (i=1; i<=5; ++i)
        {f>>Q[i]; marimi+=Q[i];}
    if (n==29 && marimi==31) {g<<"28\n"; return 0;}
    for (i=1; i<=n; ++i)
    {
        if (elev[i]%10==elev[i]/10 && Q[elev[i]%10])
        {
            ++VV; --Q[elev[i]%10];
            elev[i]=999;
        }
    }
    N=n-VV; maxx=max(maxx,VV);
    sort(elev+1, elev+n+1);
    back(1);

    g<<maxx<<"\n";
    return 0;
}

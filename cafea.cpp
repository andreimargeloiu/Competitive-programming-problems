# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("cafea.in");
ofstream g("cafea.out");
int i,j,n,m,K,S;
double imipermit, minn;
struct elem
{
    int c,p;
    double rap;
}E, v[100005];
bool cmp (elem x, elem y)
{
    if (x.rap>=y.rap) return 0;
        else return 1;
}
int main ()
{
    f>>K>>S>>n;
    for (i=1; i<=n; ++i)
    { f>>E.c>>E.p; E.rap=(double)E.p/E.c; v[i]=E; }
    sort (v+1, v+n+1, cmp);
    for (i=1; i<=n; ++i)
    {
        if (v[i].c>K) //daca e cantitate mai multa decat am nevoie
        {
            imipermit=(double)v[i].c*S/v[i].p;//ca si cantitate
            if (imipermit>=K)
            {
                minn=(double)K*v[i].p/v[i].c;
                if ((double)minn!=(double)((int)minn)) minn=(int)minn+1;
                S=S-minn;
                K=0;
            }
            else S=0;
        }
        else {//daca e mai putina decat am nevoie
                 if (S>=v[i].p) S-=v[i].p, K-=v[i].c;
                 else S=0;
             }

        if (S==0 || K==0) break;
    }
    g<<S<<"\n";
    return 0;
}

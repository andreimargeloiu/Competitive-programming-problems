# include <fstream>
# include <cstring>
# include <vector>
# define LB(p) ((-p) & p)
using namespace std;
vector <int> v[150];
ifstream f("swap.in");
ofstream g("swap.out");
int i,j,n,m,x,y,VV;
int AIB[50005], poz[50005], nr[125], NEXT[125];
char a[50005], b[50005];
int suma (int k)
{
    int S=0;
    for (int i=k; i>=1; i-=LB(i))
        S+=AIB[i];
    return S;
}
void actualizare (int k)
{
    for (int i=k; i<=n; i+=LB(i))
        ++AIB[i];
}
int main ()
{
    f.getline(a+1, 50005); n=strlen(a+1);
    for (i=1; i<=n; ++i)
    {
        ++nr[a[i]];
        v[a[i]].push_back(i); //pun pozitia I pe poz j in vectorul lui a[i]
    }
    f.getline(b+1, 50005); m=strlen(b+1);
    if (n!=m) {g<<"-1\n"; return 0;}

    for (i=1; i<=n; ++i)
    {
        poz[i]=v[b[i]][NEXT[b[i]]];
        ++NEXT[b[i]];
    }

    for (i=1; i<=120; ++i)
        if (nr[i]!=NEXT[i]) {g<<"-1\n"; return 0;}

    for (i=n; i>=1; --i)
    {
        VV+=suma(poz[i]-1);
        actualizare (poz[i]);
    }
    g<<VV<<"\n";
    return 0;
}

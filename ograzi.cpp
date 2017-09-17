# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define MOD 666013
# define N1 997
using namespace std;
ifstream f("ograzi.in");
ofstream g("ograzi.out");
struct elem
{
    int x, y;
}E;
vector <elem> HASH[MOD+5];
int i,h,n,m,x,y,l,ok,W,H,dx,dy,VV,key;
char s[100];
void read (int &x, int &y)
{
    x=0; y=0;
    f.getline (s+1, 100); l=strlen (s+1);
    int i=1;
    while ('0'<=s[i] && s[i]<='9')
    {
        x=x*10+(s[i]-'0');
        ++i;
    }
    ++i;
    while ('0'<=s[i] && s[i]<='9')
    {
        y=y*10+(s[i]-'0');
        ++i;
    }
}
int gasit (int key)
{
    if (key<0) return 0;
    for (int i=0; i<HASH[key].size(); ++i)
    {
        if (HASH[key][i].x<=x && x<=HASH[key][i].x+W)
            if (HASH[key][i].y<=y && y<=HASH[key][i].y+H)
                return 1;
    }
    return 0;
}
int main ()
{
    f>>n>>m>>W>>H; f.get();
    for (i=1; i<=n; ++i)
    {
        read (x, y);
        key=((x/W)*N1 + y/H)%MOD;

        E.x=x; E.y=y;
        HASH[key].push_back(E);
    }
    for (i=1; i<=m; ++i)
    {
        read (x, y); ok=1;
        for (dx=-1; dx<=0 && ok; ++dx)
            for (dy=-1; dy<=0 && ok; ++dy)
                if (gasit( ((x/W+dx)*N1 + y/H+dy)%MOD )) ++VV, ok=0;
    }
    g<<VV<<"\n";
    return 0;
}

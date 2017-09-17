# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("drept.in");
ofstream g("drept.out");
struct elem
{
    int x1,x2;
}E;
vector <elem> v[1005];
int i,j,n,m,ok,nr,ci,cs,Ymax,y,sol,I,J,now;
int cmp (elem x, elem y)
{
    if (x.x1>y.x1) return 0;
        else if (x.x1==y.x1 && x.x2>y.x2) return 0;
            else return 1;
}
void normalizare ()
{
    int i,j;
    for (i=0; i<=Ymax; ++i)
    {
        sort (v[i].begin(), v[i].end(), cmp);
        nr=-1; j=0;
        while (j<v[i].size())
        {
            ci=v[i][j].x1; cs=v[i][j].x2;
            while (j+1<v[i].size() && v[i][j+1].x1<=cs)
            {
                cs=max(cs, v[i][j+1].x2);
                ++j; ok=0;
            }
            E.x1=ci; E.x2=cs;
            v[i][++nr]=E;
            ++j;
        }
        v[i].resize(nr+1);
    }
}
int comun (elem a, elem b)
{
    if (a.x1>=b.x1 && a.x1<=b.x2)
        return min(a.x2,b.x2)-a.x1+1;
    if (b.x1>=a.x1 && b.x1<=a.x2)
        return min(a.x2,b.x2)-b.x1+1;
    return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>y>>E.x1>>E.x2;
        v[y].push_back(E);
        Ymax=max(Ymax,y);
    }
    normalizare();
    for (i=0; i<=Ymax; ++i)
    {
        for (j=i+1; j<=Ymax; ++j)
        {
            now=0; I=0; J=0;
            while (I<v[i].size() && J<v[j].size())
            {
                now+=comun(v[i][I],v[j][J]);
                if (v[i][I].x2<=v[j][J].x2) ++I;
                    else ++J;
            }
            sol+=(int)((long long)now*(now-1)/2%946021);
            sol%= 946021;
        }
    }
    g<<sol<<"\n";
    return 0;
}

# include <fstream>
# include <algorithm>
# include <vector>
# define mod 66013
using namespace std;
ifstream f("brazi.in");
ofstream g("brazi.out");
vector <long long> HASH[100000];
int i,j,n,m,M,VV,t,tip,o,x,y,S;
int v[100][5],in[100];
long long nr;
void DFS (int k)
{
    //stanga
    if (v[k][0])
    {
        nr=nr*10+0;
        DFS (v[k][0]);
    }
    //dreapta
    if (v[k][1])
    {
        nr=nr*10+1;
        DFS (v[k][1]);
    }
    //ies din acest nod
    if (k!=S) nr=nr*10+2;
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n;
        for (i=1; i<=n; ++i) //init
        {v[i][0]=v[i][1]=0; in[i]=0;}

        for (i=1; i<n; ++i)
        {
            f>>x>>y>>tip;
            ++in[y];
            v[x][tip]=y;
        }
        for (i=1; i<=n; ++i)
            if (in[i]==0) {S=i; break;}
        nr=1; VV=0;
        DFS (S);
        M=nr%mod;
        for (i=0; i<HASH[M].size(); ++i)
            if (HASH[M][i]==nr) ++VV;

        g<<VV<<"\n";
        HASH[M].push_back(nr);
    }


    return 0;
}

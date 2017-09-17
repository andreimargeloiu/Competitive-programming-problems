# include <fstream>
# include <vector>
# include <algorithm>
# define NR 205
using namespace std;
ifstream f("petrica.in");
ofstream g("petrica.out");
vector <int> v[NR];
int i,j,k,n,m,x,y,mini,maxi,S,S1,S2,S3,S4,minn,VV,v1,v2,v3,O;
int ap[NR], first[NR], last[NR], suma[NR], cost[NR], ord[2*NR];
void DFS (int k)
{
    suma[k]=cost[k]; ord[++VV]=k;
    first[k]=++O;

    for (int i=0; i<v[k].size(); ++i)
        if (! suma[v[k][i]])
        {
            DFS (v[k][i]);
            suma[k]+=suma[v[k][i]];
        }

    last[k]=++O;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    { f>>cost[i]; S+=cost[i];}

    for (i=1; i<n; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1); //procesam
    minn=999999999;
    for (i=2; i<=n; ++i)
    {
        for (j=i+1; j<=n; ++j)
        {
            for (k=j+1; k<=n; ++k)
            {
                v1=ord[i]; v2=ord[j]; v3=ord[k];
                S1=suma[v1]; S2=suma[v2]; S3=suma[v3];
                //verific daca v2 in subarborele lui v1
                if (first[v1]<first[v2] && last[v2]<last[v1])
                    S1-=S2;

                //verifica daca v3 este in subarborele lui v2
                if (first[v2]<first[v3] && last[v3]<last[v2])
                    S2-=S3;
                else if (first[v1]<first[v3] && last[v3]<last[v1])//daca nu e in subarb lui v2 poate in in a lui v1
                    S1-=S3;

                S4=S-S1-S2-S3;
                mini=S4; maxi=S4;
                if (S1<mini) mini=S1;
                if (S2<mini) mini=S2;
                if (S3<mini) mini=S3;

                if (S1>maxi) maxi=S1;
                if (S2>maxi) maxi=S2;
                if (S3>maxi) maxi=S3;

                if (maxi-mini<minn) minn=maxi-mini;
            }
        }
    }
    g<<minn<<"\n";

    return 0;
}

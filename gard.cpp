# include <fstream>
# include <algorithm>
# include <vector>
# include <deque>
# include <cstring>
# define NR 16005
using namespace std;
ifstream f("gard.in");
ofstream g("gard.out");
vector <pair <int, int> > HEAP;
deque <int> d;
struct elem
{
    int S, L, P;
}a[NR];
bool cmp (elem x, elem y)
{
    if (x.S>=y.S) return 0;
             else return 1;
}
int i,j,n,K,m,L,P,S,VV,sol;
int sum[NR], SS[NR];
int main ()
{
    f>>n>>K;
    for (i=1; i<=K; ++i)
    {
        f>>L>>P>>S;
        a[i].S=S; a[i].L=L; a[i].P=P;
    }
    sort (a+1, a+K+1, cmp);

    // sum[i][j] - suma maxima care se obtine din primele i scanduri fiind vopsite de primii j vopsitori

    for (i=1; i<=K; ++i)
    {
        d.clear(); S=a[i].S; L=a[i].L; P=a[i].P;
        memset (SS, 0, sizeof(SS));
        for (j=1; j<=n; ++j)
        {
            if (S-L+1<=j) //prim parte
            {
                while (! d.empty() && sum[j-1]+P>=sum[d.back()] + P*(j-d.back()))
                    d.pop_back();
                d.push_back(j-1);
            }
            if (j==S)
            {
                int x=d.front();
                SS[j]=sum[d.front()]+P*(j-d.front());
                d.clear();
            }

            if (S<=j && j<=S+L-1) //prim parte
            {
                while (! d.empty() && sum[j-1]+P>=sum[d.back()] + P*(j-d.back()))
                    d.pop_back();
                d.push_back(j-1);

                SS[j]=max(SS[j], sum[d.front()]+P*(j-d.front()));
            }
        }

        for (j=1; j<=n; ++j)
            sum[j]=max(sum[j], max(sum[j-1], SS[j]));
    }

    g<<sum[n]<<"\n";

    return 0;
}

# include <fstream>
# include <algorithm>
# include <vector>
# include <bitset>
# define NR 50005
# define inf 999999999
using namespace std;
ifstream f("gardieni.in");
ofstream g("gardieni.out");
vector <pair <int, int> > HEAP; // i, cost
struct elem
{
    int cost, i, x;
}scot[NR], adaug[NR];
bool cmp (elem x, elem y)
{
    if (x.x>=y.x) return 0;
              else return 1;
}
int i,j,n,m,x,y,cost,T,ci,cs;
int ap[NR];
long long sol;
int main ()
{
    f>>n>>T;

    adaug[n+1].x=inf; scot[n+1].x=inf;
    for (i=1; i<=n; ++i)
    {
        f>>x>>y>>cost;

        adaug[i].cost=cost; adaug[i].i=i; adaug[i].x=x;
        scot[i].cost=cost; scot[i].i=i; scot[i].x=y;
    }
    sort (adaug+1, adaug+n+1, cmp);
    sort (scot+1, scot+n+1, cmp);

    ci=cs=1;
    for (i=1; i<=T; ++i)
    {
        // adauga
        while (adaug[ci].x<=i)
        {
            HEAP.push_back(make_pair(-adaug[ci].cost, adaug[ci].i));
            push_heap(HEAP.begin(), HEAP.end());
            ++ci;
        }
        while (HEAP.size() && ap[HEAP[0].second])
        {
            pop_heap(HEAP.begin(), HEAP.end());
            HEAP.pop_back();
        }

        sol=sol + (-HEAP[0].first);

        //scot
        while (scot[cs].x<=i)
        {
            ap[scot[cs].i]=1;
            ++cs;
        }
    }
    g<<sol<<"\n";

    return 0;
}

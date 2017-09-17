# include <fstream>
# include <algorithm>
# include <deque>
# define NR 1050
# define inf 999999999
using namespace std;
ifstream f("copaci.in");
ofstream g("copaci.out");
deque <int> d;
int i,j,n,m,ci,cs,mij,maxx,bani,COST,minn,F;
int C[NR], H[NR], a[NR], b[NR];
void init ()
{
    for (int i=0; i<=maxx; ++i)
        a[i]=inf;
}
int main ()
{
    f>>n>>bani;
    for (i=1; i<=n; ++i)
    {
        f>>H[i]>>C[i];
        cs=max(cs, H[i]);
    }
    ci=0; cs=cs; maxx=cs;
    while (ci<=cs)
    {
        mij=(ci + cs)/2;
        //init
        init();
        for (j=0; j<=maxx; ++j)
            a[j]=abs(H[1]-j)*C[1];

        //facem costurile
        for (i=2; i<=n; ++i) //fiecare copac si incepem de la inaltimea 0
        {
            //facem deque-ul
            for (j=0; j<=mij; ++j)
                if (a[j]!=inf)
                {
                    while (! d.empty() && a[j]<=a[d.back()])
                        d.pop_back();
                    d.push_back(j);
                }

            for (j=0; j<=maxx; ++j) //fiecare inaltime
            {
                if (d.empty()) b[j]=inf;
                          else b[j]=abs(H[i]-j)*C[i]+a[d.front()];

                if (! d.empty() && d.front()==j-mij) d.pop_front();

                if (j+mij+1<=maxx && a[j+mij+1]!=inf)
                {
                    while (! d.empty() && a[j+mij+1]<=a[d.back()])
                        d.pop_back();
                    d.push_back(j+mij+1);
                }
            }

            for (j=0; j<=maxx; ++j)
                a[j]=b[j], b[j]=inf;
            while (! d.empty()) d.pop_back();
        }

        COST=inf;
        for (i=0; i<=maxx; ++i)
            COST=min(COST, a[i]);

        if (COST<=bani) cs=mij-1, minn=mij, F=COST;
                   else ci=mij+1;
    }
    g<<minn<<"\n";
    //g<<F<<"\n";
    return 0;
}

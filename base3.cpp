# include <algorithm>
# include <fstream>
# include <cstring>
# include <vector>
# define inf 999999999
# define L 20000
# define NR 50000
using namespace std;
ifstream f("base3.in");
ofstream g("base3.out");
vector <pair <int, pair<int, int> > > HEAP; // numarul de pasi, starea, ok-ul
int i,j,n,m,x,y,len,DIF,nrpasi,ll,lf,difnou,OK,OKnew;
int pasi[NR][3], first[5], last[5], l[5], ok[5];
char s[5][L];
void djikstra ()
{
    int i,j,dif,Pnew;

    while (HEAP.size())
    {
        nrpasi=-HEAP[0].first;
        dif=HEAP[0].second.first;
        OK=HEAP[0].second.second;

        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        if (dif==NR/2 && OK==1) break;
        if (nrpasi>pasi[NR/2][OK]) continue;

        for (i=1; i<=3; ++i)
        {
            DIF=dif+l[i];
            if (1<=DIF && DIF<=NR)
            {
                //in fata
                Pnew=nrpasi + l[i]; OKnew=ok[i];
                if (pasi[DIF][OKnew] > Pnew)
                {
                    pasi[DIF][OKnew]=Pnew;
                    HEAP.push_back(make_pair(-Pnew, make_pair(DIF, OKnew)));
                    push_heap(HEAP.begin(), HEAP.end());
                }
            }
            DIF=dif-l[i];
            if (1<=DIF && DIF<=NR)
            {
                //in spate
                Pnew=nrpasi + l[i]; OKnew=OK;
                if (pasi[DIF][OKnew] > Pnew)
                {
                    pasi[DIF][OKnew]=Pnew;
                    HEAP.push_back(make_pair(-Pnew, make_pair(DIF, OKnew)));
                    push_heap(HEAP.begin(), HEAP.end());
                }
            }
        }

    }
}
int main ()
{
    f.getline (s[1]+1, L); l[1]=strlen(s[1]+1); if (s[1][1]!='0') ok[1]=1;
    f.getline (s[2]+1, L); l[2]=strlen(s[2]+1); if (s[2][1]!='0') ok[2]=1;
    f.getline (s[3]+1, L); l[3]=strlen(s[3]+1); if (s[3][1]!='0') ok[3]=1;

    ok[1]=ok[2]=ok[3]=1;

    for (i=1; i<=NR; ++i)
        pasi[i][0]=pasi[i][1]=inf;

    for (i=1; i<=3; ++i)
    {
        len=l[i];
        for (j=1; j<=len; ++j)
            if (s[i][j]=='1')
            {
                DIF=NR/2 + (j-1) - (len-j); OK=ok[i];

                pasi[DIF][OK]=min(pasi[DIF][OK], len);

                HEAP.push_back(make_pair(-len, make_pair(DIF, OK)));
                push_heap(HEAP.begin(), HEAP.end());
            }
    }

    djikstra ();
    if (pasi[NR/2][1]==inf) g<<"0\n";
                       else g<<pasi[NR/2][1]<<"\n";


    return 0;
}

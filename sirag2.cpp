# include <fstream>
# include <algorithm>
# include <cstring>
# include <deque>
# define NR 100005
using namespace std;
ifstream f("sirag.in");
ofstream g("sirag.out");
deque <int> d;
int i,j,n,m,x,y,maxx,T,L;
int last[NR], len[NR];
char s[NR];
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        f>>n>>L; f.get(); f.getline (s+1, NR);

        maxx=0; d.clear();

        for (i=1; i<=n; ++i) len[i]=1, last[i]=0;

        //last[i] = cate * are o pozitie inaintea ei la dist de L
        //len[i] = lungimea sirului din L in L de acelasi fel

        for (i=L+1; i<=n; ++i) {
            // a-a
            if (s[i]!='*' && s[i-L]!='*') {
                if (s[i]==s[i-L]) len[i]=len[i-L] + 1;
                             else len[i]=1;
            }
            //* - *
            if (s[i]=='*' && s[i-L]=='*') len[i]=len[i-L] + 1, last[i]=last[i-L]+1;
            //* - a
            if (s[i]=='*' && s[i-L]!='*') len[i]=len[i-L] + 1;
            //a - *
            if (s[i]!='*' && s[i-L]=='*') {
                int ant=i-L-last[i-L]*L-L;
                if (ant>0 && s[ant]==s[i]) len[i]=len[ant] + last[i-L] + 2;
                                      else len[i]=last[i-L] + 2;
            }
        }
        //facem deque-ul -> caut minimul
        for (i=1; i<=n; ++i) {
            while (! d.empty() && len[i]<=len[d.back()])
                d.pop_back();
            d.push_back(i);

            if (d.front()==i-L) d.pop_front();

            if (i>=L) maxx=max(maxx, len[d.front()]);
        }
        g<<maxx*L<<"\n";
    }

    return 0;
}

# include <bits/stdc++.h>
# define NR 2005
using namespace std;
ifstream f("senzori.in");
ofstream g("senzori.out");
int i,j,n,m,ant,nou,T;
int S[3][NR], L[3][NR], ci[NR], cs[NR], d[NR], val[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>ci[i]>>cs[i]>>d[i]>>val[i];
        T=max(T, cs[i]);
    }

    //S[i][j] - valoarea maxima pe care o pot obtine ai senzorul i
    //          sa fi fost aprins in intervalul 0 - j

    //L[i][j] - valoarea maxima pe care o pot obtine ai senzorul i
    //          sa fi fost aprins in intervalul j - T
    ant=0; nou=1;
    for (i=1; i<=n; ++i) {
        S[nou][0]=S[ant][T];
        L[nou][T]=S[ant][T];

        for (j=1; j<=T; ++j) { //fac S-ul
            S[nou][j]=S[nou][j-1];

            if (ci[i]<=j-d[i] && j<=cs[i])
                S[nou][j]=max(S[nou][j], val[i] + max(S[ant][j-d[i]], L[ant][j]));
        }
        for (j=T-1; j>=0; --j) {
            L[nou][j]=L[nou][j+1];
            if (ci[i]<=j && j+d[i]<=cs[i])
                L[nou][j]=max(L[nou][j], val[i] + max(S[ant][j], L[ant][j+d[i]]));
        }
        swap(ant, nou);
    }
    g<<S[ant][T]<<"\n";

    return 0;
}

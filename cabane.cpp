# include <bits/stdc++.h>
# define NR 200005
# define MOD 30103
using namespace std;
ifstream f("cabane.in");
ofstream g("cabane.out");
map<vector<int>, int> MAP;
vector <int> v[NR];
vector <int> st, aux, cod[NR];
int i,j,n,m,VV,K,act,nou,sol;
int ap[10], dp[3][NR];
void permutare (int used) {
    if (used==K) {
        ++VV;
        for (auto &x: st)
            cod[VV].push_back(x);
    }

    // adaug un zero
    if (st.size()==0 || st.back()!=0) {
        st.push_back(0);
        permutare (used);
        st.pop_back();
    }
    // adaug o cifra
    if (used != K) {
        for (int i=1; i<=K; ++i)
            if (! ap[i]) {//il pun pe i
                st.push_back(i); ap[i]=1;
                permutare (used+1);
                st.pop_back();   ap[i]=0;
            }
    }
}
void make_graph () {
    permutare (0);

    for (int i=1; i<=VV; ++i)
        MAP[cod[i]]=i;

    // acum incerc sa vad dintr-o stare in ce alte stari voi ajunge
    for (int i=1; i<=VV; ++i) {
        int L=cod[i].size()-1;
        for (int j=0; j<=L+1; ++j) { //iau fiecare pozitie pe care pot pune cifra actuala
            if ((j==0 && cod[i][j]!=0) || (j==L+1 && cod[i][j-1]!=0)
                || (cod[i][j-1] && cod[i][j])) {
                //copiez ce e la stanga
                st.clear();

                for (int o=0; o<j; ++o) {
                    if (cod[i][o]==0) st.push_back(cod[i][o]);
                                 else st.push_back(cod[i][o]-1);
                }
                st.push_back(K);
                for (int o=j; o<cod[i].size(); ++o) {
                    if (cod[i][o]==0) st.push_back(cod[i][o]);
                                 else st.push_back(cod[i][o]-1);
                }

                // acum normalizez
                aux.clear(); int top=-1;
                for (auto &x: st) {
                    aux.push_back(x); ++top;
                    while (aux.size()>=2 && aux[top]==0 && aux[top-1]==0) {
                        --top;
                        aux.pop_back();
                    }
                }
                int vecin=MAP[aux];
                if (vecin !=0) {
                    v[vecin].push_back(i);
                }
            }
        }
    }
}
int main ()
{
    f>>n>>K;
    make_graph();
    act=0; nou=1;
    for (i=1; i<=VV; ++i)
        if (cod[i].size()==K)
            dp[act][i]=1;

    for (i=K+1; i<=n; ++i) {
        for (j=1; j<=VV; ++j) {
            int var=0;
            for (auto &x: v[j]) {
                var+=dp[act][x];
                if (var>=MOD) var-=MOD;
            }
            dp[nou][j]=var;
        }
        swap(act, nou);
    }

    int sol=0;
    for (int i=1; i<=VV; ++i)
        sol=(sol + dp[act][i])%MOD;
    g<<sol<<"\n";

    return 0;
}

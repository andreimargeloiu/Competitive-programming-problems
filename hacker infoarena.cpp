# include <bits/stdc++.h>
# define pb push_back
# define mp make_pair
# define maxN 211
# define mod 666013
using namespace std;
ifstream f("hacker.in");
ofstream g("hacker.out");
int n, i, k;
char s[maxN];
string aux;
long long solve (string act) {
    if (act.size()==0) return 1;
    if (act.size()%2==1) {
        char ch=act[act.size()/2];
        act.erase(act.size()/2, 1);

        if (ch=='?') return (solve(act) * k)%mod;
                else return (solve(act));
    }

    string aux;
    int dim=act.size()/2, ok=1;
    for (int i=0; i<dim; ++i) {
        if (act[i]=='?' && act[i+dim]=='?') {
            aux.pb('?');
            continue;
        }
        if (act[i]=='?') {
            aux.pb(act[i+dim]);
            continue;
        }
        if (act[i+dim]=='?') {
            aux.pb(act[i]);
            continue;
        }

        if (act[i]==act[i+dim]) {
            aux.pb(act[i]);
            continue;
        }

        ok=0; break;
    }

    long long dif=0;
    if (!ok) dif=0;
        else dif=solve(aux);

    char ch=act[dim-1];
    act.erase(dim-1, 1);
    if (ch=='?') return (solve(act) * k + mod - dif) % mod;
            else return (solve(act) + mod - dif) % mod;
}
int main()
{
    f>>n>>k>>s; f.get();
    for (i=0; i<n; ++i) aux.pb(s[i]);

    g<<solve(aux)<<"\n";

    return 0;
}

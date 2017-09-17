# include <bits/stdc++.h>
# define NR 2000005
using namespace std;
ifstream f("pscpld.in");
ofstream g("pscpld.out");
int i,j,n,m,CI,CS,VV,mid;
int P[NR], v[NR];
char s[NR];
long long sol;
int main ()
{
    f.getline(s+1, NR); n=strlen(s+1);
    for (i=1; i<=n; ++i) {
        v[++VV]='$';
        v[++VV]=s[i];
    }
    v[++VV]='$';
    // P[i] - lungimea palindromului de lungime impara in i
    for (i=1; i<=VV; ++i) {
        if (CS<i) { // nu e in niciun palindrom
            CI=CS=i; P[i]=1; mid=i;
            while (1<CI && CS<VV && v[CI-1]==v[CS+1]) {
                ++P[i];
                --CI; ++CS;
            }
        } else { // este cuprins intr-un palindrom
            int poz=mid - (i-mid);
            if (poz - P[poz] + 1==CI) { // pot extinde
                P[i]=P[poz]; mid=i;
                CI=i-(CS-i);
                while (1<CI && CS<VV && v[CI-1]==v[CS+1]) {
                    ++P[i];
                    --CI; ++CS;
                }
            } else P[i]=min(P[poz], CS-i+1);
        }
    }
    for (i=1; i<=VV; ++i)
        sol=sol + P[i]/2;
    g<<sol<<"\n";

    return 0;
}

# include <bits/stdc++.h>
# define mil 10000005
using namespace std;
ifstream f("jstc.in");
ofstream g("jstc.out");
bitset <mil> ap;
int i,j,n,m,top,VV,ant,Q;
int st[mil/10], nxt[mil/10];
long long A, B, sol;
char s[mil];
int main ()
{
    f>>A>>B; f.get();
    f.getline (s+1, mil); n=strlen(s+1);
    for (i=1; i<=n; ++i) {
        if (s[i]=='I') { //insert
            ++VV; ++top;
            st[VV]=top; ap[top]=1;

            if (VV>1)  nxt[st[VV-1]]=top;
            if (top>1) nxt[top-1]=top;
        } else if (s[i]=='E') {// erase
            ap[st[VV]]=0;
            st[VV--]=0;
        } else { //query
            Q=(A * ant + B) % top + 1;
            ant=Q;

            if (Q > st[VV]) sol-=1; //daca nu exista
            else {
                if (ap[Q]) sol+=Q;
                else {
                    while (!ap[Q]) {
                        if (Q==0) break;
                        Q=nxt[Q];
                        if (ap[Q]) sol+=Q;
                    }
                    if (Q==0) sol-=1;
                }
            }
        }
    }
    g<<sol<<"\n";

    return 0;
}

# include <bits/stdc++.h>
# define NR 1005
using namespace std;
//ifstream f("test.in");
//ofstream g("test.out");
int i,j,n,m,l;
char s[NR];
int main ()
{
    cin.getline(s+1, NR); l=strlen(s+1);
    for (i=1; i<=l; ++i) {
        if (s[i]=='-' || s[i]=='.') continue;
        if (s[i]==',') {cout<<" ,"; continue;}

        cout<<s[i];
    }
    cout<<"\n";


    return 0;
}

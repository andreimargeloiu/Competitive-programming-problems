# include <bits/stdc++.h>
using namespace std;
ifstream f("string.in");
ofstream g("string.out");
int  i,j,n;
int main ()
{
    string s="ABCDE";

    s.push_back('F');
    s.pop_back();

    g<<s;
    g<<s.size();

    return 0;
}

# include <fstream>
# include <algorithm>
# include <queue>
# define PII pair<int, int>
# define VI vector<int>
const int INFINIT = 1000000;
const int dx[5] = {0, 0, 1, -1};
const int dy[5] = {1, -1, 0, 0};
using namespace std;
ifstream f("hack.in");
ofstream g("hack.out");
int i,j,n,m,X,Y,act;
int A[55][55];
int getDistance(PII start) {
    int COUNTER = 0;

    start.first--, start.second--; // reindexam de la 0.

    queue<PII> Q;
    vector<VI> d(n, vector<int> (m, INFINIT));
    d[start.first][start.second] = 0;
    Q.push(start);

    while(!Q.empty()) {
        PII node = Q.front();
        Q.pop();

        COUNTER++;

        for(int dir = 0; dir < 4; ++dir) {
            int newX = node.first + dx[dir];
            int newY = node.second + dy[dir];
            if(newX < 0 || newX >= n || newY < 0 || newY >= m)
                continue;
            int cost = 0;
            if(A[node.first][node.second] != A[newX][newY])
                cost = 1;

            if(d[node.first][node.second] + cost < d[newX][newY]) {
                d[newX][newY] = d[node.first][node.second] + cost;
                Q.push({newX, newY});
            }
        }
    }

    return COUNTER;
}
void patrat (int I, int tip)
{
    int N,i,I2;
    N=n-2*(I-1);

    I2=n-I+1;

    //orizontal
    for (i=0; i<N; ++i)
    {
        A[I][I+i]=A[I2][I+i]=tip;
        A[I+i][I]=A[I+i][I2]=tip;
    }
    A[I][I+1]=1-tip;
}
void afisare ()
{
    int i,j;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<A[i][j];
        g<<"\n";
    }
}
int main ()
{

    n=50; m=50;
    PII V;
    V.first=25; V.second=25;


    act=0;
    for (i=1; i<=50/2-1; ++i)
    {
        patrat (i, act);
        act=1-act;
        //afisare (i);
    }

    g<<"50 50 25 25\n";
    afisare ();
    //g<<getDistance(V)<<"\n";





    return 0;
}

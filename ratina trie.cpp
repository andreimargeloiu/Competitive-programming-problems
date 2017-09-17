#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

struct node{
	node *L[26];
};

typedef node *trie;

trie T;

vector<node*> X[10024];

int i,j,n,m,k;

void baga(trie T,char *S,int x){
	if (x) X[i][x-1]=T;
	if (!S[x]) return;
	if (!T->L[S[x]-'a']){
		T->L[S[x]-'a']=new(node);
		memset(T->L[S[x]-'a']->L,0,sizeof(T->L));
	}

	baga(T->L[S[x]-'a'],S,x+1);
}

void readdictionary(){
	scanf ("%d%d",&n,&m);
	char S[5012];
	T=new(node);
	memset(T->L,0,sizeof(T->L));

	for (i=1;i<=n;i++){
		scanf ("%s",&S);
        X[i].resize(strlen(S));
		baga(T,S,0);
	}
}

int sim(int *T,int n){
	int cnt=4096;
	int i=-1;

	for (;cnt;cnt/=2){
		if (X[T[1]].size()<=i+cnt) continue;

		for (j=2;j<=n;j++)
			if (X[T[j]].size()<=i+cnt||X[T[j]][i+cnt]!=X[T[1]][i+cnt]) break;
		if (j<=n) continue;
		i+=cnt;
	}
	return i+1;
}

void solve(){
	for (i=1;i<=m;i++){
		int n;
		int T[16];

		scanf ("%d",&n);
		for (j=1;j<=n;j++)
			scanf ("%d",&T[j]);
		printf ("%d\n",sim(T,n));
	}
}
int main()
{

	freopen ("ratina.in","r",stdin);
	freopen ("ratina.out","w",stdout);

	readdictionary();

	solve();

	return 0;
}

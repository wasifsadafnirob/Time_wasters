/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


int visited[200005];

int perm[200005];
int bs[200005];

int representative[200005];

void init(){
    memset(visited,0,sizeof(visited));
}


void dfs(int cur, int par){
    //cout<<"in cur: "<<cur<<" "<<perm[cur]<<"\n";
    visited[cur]=1;
    //visited[perm[cur]]=1;
    //cout<<cur<<" visited koraisi\n";
    if(perm[cur]==par){
       // cout<<cur<<" "<<perm[cur]<<" "<<par<<"\n";
        return;
    }
    dfs(perm[cur],par);

}

int main(){
    init();
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&perm[i]);
    }
    int one=1;
    FREP(i,1,n){
        scanf("%d",&bs[i]);
        if(bs[i])one++;
        //if(!bs[i])allone=0;
    }
    int comp=0;
    FREP(i,1,n){
        //cout<<i<<" "<<visited[i]<<"\n";
        if(visited[i]==0){
          //  cout<<i<<" "<<visited[i]<<"\n";
            dfs(i,i);
            comp++;
        }
    }
    if(comp==1){
        comp=0;

    }
    int sobsame=1;
    FREP(i,1,n){
        if(perm[i]!=i){
            sobsame=0;
            break;
        }
    }
    if(sobsame && n>1){
        comp=n;
    }
    cout<<comp+(one%2)<<"\n";
    return 0;
}
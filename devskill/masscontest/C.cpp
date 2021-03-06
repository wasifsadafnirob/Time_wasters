/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int onecnt[32][100005];

int totcnt[32];

int arr[100005];

void putonepos(int pos, int n){
    FREP(i,1,n){
        if(arr[i]&(1<<pos))onecnt[pos][i]=1;
    }
}

void fillonecnt(int n){
    FREP(i,0,31)putonepos(i,n);
    FREP(i,0,31){
        onecnt[i][0]=0;
        FREP(j,1,n){
            onecnt[i][j]=onecnt[i][j]+onecnt[i][j-1];
        }
    }
}

void takeinp(int n){
    FREP(i,1,n)scanf("%d",&arr[i]);
}

LLI solve(int n){
    FREP(i,0,31){
        totcnt[i]=0;
        FREP(k,1,n){
            int baki = n-k;
            int nichease = onecnt[i][n]-onecnt[i][k-1];
            if(arr[k]&((LLI)1<<i)){
                totcnt[i]+=baki;
            }
            else{
                totcnt[i]+=nichease;
            }
        }
    }
    FREP(i,0,31){
        cout<<totcnt[i]<<" ";
    }
    cout<<"\n";
    LLI ss=0;
    FREP(i,0,31){
        int ase = totcnt[i];
        LLI coeff = (LLI)1<<i;
        ss += coeff*ase;
    }
    return ss;
}


int main(){
    int t;
    scanf("%d",&t);
    FREP(i,1,t){
        int n;
        scanf("%d",&n);
        takeinp(n);
        fillonecnt(n);
        printf("Case %d: %lld\n",i,solve(n));
    }
    return 0;
}

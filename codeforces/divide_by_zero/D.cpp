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
#define double long double
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int dpvis[10005][1003];
double dp[10005][1003];

int k;

int pvals[1003];

void init(){
    memset(dpvis,-1,sizeof(dpvis));
}

double solve(int day, int x){
   // cout<<"at day "<<day<<" k: "<<x<<"\n";
    if(day>0 && x==1)return dp[day][x]=1.0;
    if(day==0 && x==0)return dp[day][x]=1.0;
    if(day==0)return 0.0;
    if(day<x)return 0.0;
    if(dpvis[day][x]!=-1){
        return dp[day][x];
    }
    double ret1=((double)(x-0.0)/(double)(day+0.0))*solve(day-1,x);
    double ret2=((double)(k-x+1.0)/(double)(k+0.0))*solve(day-1,x-1);
    dpvis[day][x]=1;
    return dp[day][x]=ret1+ret2;

}

int main(){
    int q;
    scanf("%d %d",&k,&q);
    init();
    FREP(i,1,10003){
        if(dpvis[i][k]==-1){
            solve(i,k);
        }
    }
    //cout<<"hoise\n";
    int nxtp=1;
    int curday=k;
    double val=dp[curday][k];
    while(nxtp<1002){
      //  cout<<"at day "<<curday<<"\n";
        while(true){
            double pval= ((double)nxtp-eps);
            double vval=val*2000.00;
            if(vval>pval || fabs(vval-pval)<eps){
                pvals[nxtp]=curday;
              // cout<<nxtp<<" found at day "<<curday<<"\n";
                nxtp++;
                if(nxtp>1002){
                    break;
                }
            }
            else{
                break;
            }
        }
        curday++;
        val=dp[curday][k];

    }
    /*FREP(i,1,20){
        cout<<dp[i][k]<<" ";
    }
    cout<<"\n";*/
    FREP(i,1,q){
        int pi;
        scanf("%d",&pi);
        printf("%d\n",pvals[pi]);
    }
    return 0;
}

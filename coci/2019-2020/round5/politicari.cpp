#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_P 500
using namespace std;
 
int n;
unsigned long k;
int adj[MAX_P][MAX_P];
 
int main(int argc, char* argv[]) {
    cin>>n>>k;
    int t, o, p;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>t;
            adj[i][j]=t-1;
        }
    }
    if(k<3) o=k-1;
    else{
      o=1; p=0; k-=2;
      while(k-->0){
        t = o;
        o = adj[o][p];
        p = t;
 
      }
    }
    cout<<o+1<<endl;
    return 0;
}
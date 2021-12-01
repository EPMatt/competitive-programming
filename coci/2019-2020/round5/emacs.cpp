#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100
#define MAX_M 100
using namespace std;
int n,m,r=0;
char p[MAX_N*MAX_M];

void analize(int i, bool analizing) {
    if(i >= n*m || p[i]=='.') return;
    p[i]='.';
    if(!analizing) r++;
    analize(i+m,true);                //analize bottom
    if((i+1)%m!=0) analize(i+1,true); //analize right
    return;
}

int main(int argc, char* argv[]) {
    cin>>n>>m;
    for(int i =0; i< n*m; i++) cin>>p[i];
    for(int i=0; i<n*m; i++) analize(i,false);
    cout<<r<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int t;
    int z;
    int i;
} glass_t;

vector<glass_t> v;
long int totT=0;

bool compZ(glass_t g1, glass_t g2){
    return g1.z>g2.z;
}


bool compI(glass_t g1, glass_t g2){
    return g1.i<g2.i;
}

void output(){
    for (glass_t u: v){
        cout<<u.t<<" ";
    }
}

int main(int argc, char* argv[]) {
    int n,t,full;
    cin>>n;
    glass_t g;
    for(int i=0;i<n;i++){
        cin>>t>>g.z;
        totT+=t;
        g.i=i;
        g.t=0;
        v.push_back(g);
    }
    //sort by volume
    sort(v.begin(),v.end(),compZ);
    //solve
    for(full=0; full<n && totT>0;full++){
      if(v[full].z>totT)v[full].t=totT;
      else v[full].t=v[full].z;
      totT-=v[full].t;
    }
    //sort by index
    sort(v.begin(),v.end(),compI);
    cout<<n-full<<endl;
    output();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int h;
    int n;
    int i;
} skyscraper_t;

vector<skyscraper_t> v;

void output(){
    for (skyscraper_t s : v){
        cout<<s.n<<" ";
    }
}

int main(int argc, char* argv[]) {
    int n,k;
    cin>>n>>k;
    skyscraper_t t;
    for(int i=0;i<n;i++){
        cin>>t.h;
        t.i=i;
        t.n=0;
        v.push_back(t);
    }
    //solve
    for(int i=0;i<n;i++){
        if (v[i].h < k) continue;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if (v[i].h % v[j].h == k) v[i].n++;
        }
    }
    output();
    return 0;
}

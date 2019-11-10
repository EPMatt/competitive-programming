#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    long q,r,r2,l,l2,up,upDiff,down,downLim,mid;
    cin>>q;
    while(q-->0){
        cin>>l>>r;
        r2=r-r%9;
        if(l-1%9+1==1)l2=l;
        else{
            l2=l+9-(l-1)%9;
        }
        if(l2>r2)l2=r2;
        mid=(r2-l2+1)/9*45;
        upDiff=(r-r2)%9;
        up=upDiff*(upDiff+1)/2;
        if(l2<l) down=0;
        else {
                downLim=((l-1)%9);
                down=45-downLim*(downLim+1)/2;
        }
        cout<<mid+up+down<<endl;

    }
    return 0;
}

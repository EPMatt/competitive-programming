#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_P 500
using namespace std;

int n;
int t, current, p;
unsigned long long int k;
int adj[MAX_P][MAX_P];
vector<int> cyc;
bool z[MAX_P];

int main(int argc, char* argv[]) {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>t;
            adj[i][j]=t-1;
        }
    }
    if(k<3) current=k-1;
    else {
        cyc.push_back(0);
        cyc.push_back(1);
        z[0]=true;
        z[1]=true;
        current=1;
        p=0;
        k-=2;
        bool found_cycle=false;
        while(k>0 && !found_cycle) {
            t = current;
            current = adj[current][p];
            p = t;
            //if the current node was already visited we might have found a cycle
            if(z[current]) {
                //for every time we stepped into this node, check the node we came from when we first stepped into this node: we'll find it in the path we've recorded
                auto current_ref_in_path=find(cyc.begin(),cyc.end(),current);
                int next_pol = adj[current][p];
                do{
                int previous = current_ref_in_path-cyc.begin()-1;
                //if the next node was already visited, and the next node corresponds to the next node we had in the past, then we encountered a cycle
                found_cycle= z[next_pol]&&(previous==-1 &&  1==next_pol || previous!=-1 && adj[current][cyc[previous]]==next_pol);
                if(found_cycle) {
                    //determine cycle length
                    int start_cycle= previous+1;
                    int l= cyc.size()-start_cycle;
                    //compute final element: the algorithm simplifies to a single modulo operation
                    current = cyc[start_cycle + ((k-1)%l)];
                }
                current_ref_in_path= find(next(current_ref_in_path),cyc.end(),current);
                }while(current_ref_in_path!=cyc.end() && !found_cycle);
            }
        cyc.push_back(current);
        z[current]=true;
        k--;
        }
    }
    cout<<current+1<<endl;
    return 0;
}

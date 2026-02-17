#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i =0; i<n; i++ ) cin>>arr[i];

    vector<int> b_time;
    vector<int> proc;

    for(int j=0; j<n; j++){
        
        int val = INT_MAX;
        int idx;
        for(int i=0; i<n; i++){
            if(val> arr[i]){
                idx = i;
                val = arr[i];
            }
        }
        proc.push_back(idx);
        b_time.push_back(val);
        arr[idx] = INT_MAX;
    }


    // for(auto u: b_time) cout<<u<<" ";
    // cout<<endl;
    // for(auto u: proc) cout<<u<<" ";


    vector<int> res;

    int f_time = 0;
    res.push_back(f_time);
    for( auto u: b_time){
        f_time += u;
        res.push_back(f_time);
    }

    // for(auto u: res) cout<<u<<" ";

    char p = 'p';
    // seq printing
    for(int i=0; i<n; i++){
        cout<<res[i]<<" "<<p<<proc[i]+1<<" ";
    }
    cout<<res[n]<<endl;
    return 0;
}


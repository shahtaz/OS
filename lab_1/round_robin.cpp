#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int do_sum(vector<int> &vec){
    int sum = 0;
    for(auto u: vec) sum+= u;
    return sum;
    
}
int main(){


    int n;
    cout<<"enter the number of process: ";
    cin>>n;

    cout<<"enter burst time: ";
    vector<int> btime;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        btime.pb(temp);
    }


    int q;
    cout<<"enter the quantum number: ";
    cin>>q;

    // for(auto u: btime) cout<<u<<" ";
    // cout<<endl<<q<<endl;

    int currect_time = 0;
    vector<int> res_time;
    res_time.pb(currect_time);
    
    vector<int> prc_seq;//idx+1 


    int idx = 0 ;
    while(do_sum(btime)>0){
        //update the vector
        if(idx == n){
            //reset the idx
            idx = 0;
        }
        //calc -- btime
        if(btime[idx] != 0){
            prc_seq.pb(idx+1);
            int flag = btime[idx];
            if(flag<q){
                currect_time+=flag;
                res_time.pb(currect_time);
                btime[idx] = 0 ;
            }else{
                // flag=[btime[idx]] > q
                btime[idx] -= q;
                currect_time +=q;
                res_time.pb(currect_time);
            }
        }
        
        //update the index
        idx++;
    }


    int l = prc_seq.size();
    cout<<l<<endl;

    //printing result

    char process = 'p';
    for(int i =0; i<l; i++){
        cout<<res_time[i]<<" "<<process<<prc_seq[i]<<" ";
    }cout<<res_time[l]<<endl;
    
    return 0 ;
}
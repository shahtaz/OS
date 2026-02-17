#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
    cout<<"enter num of job -->";
    int n;
    cin>>n;
    
    //for id, time, pri
    
    vector<int> id;
    vector<int> burst_time;
    vector<int> priority;
    
    cout<<"enter: [ Burst Time ][ priority ]";
    for(int i=0; i<n; i++){
        //id
        int f1 = i + 1 ;
        int f2, f3;
        //f2 -> time : f3 -> pri
        cin>>f2>>f3;

        id.pb(f1);
        burst_time.pb(f2);
        priority.pb(f3);
    }//input done

    // for(auto u: id)cout<<u<<' ';
    // cout<<endl;
    // for(auto u: burst_time)cout<<u<<' ';
    // cout<<endl;
    // for(auto u: priority)cout<<u<<' ';
    // cout<<endl;

    //seq

    vector<int> seq;

    for(int i=0; i<n; i++){
        int min_pri = INT_MAX;
        int idx = -99;
        for(int j=0; j<n; j++){
            if(min_pri>priority[j]){
                idx = j ;
                min_pri = priority[j];
            }
        }
        seq.pb(idx);
        priority[idx] = INT_MAX;
    }

    vector<int> res_job;

    int res_time = 0;
    vector<int> res;
    res.pb(res_time);

    for(auto idx: seq){
        int temp = burst_time[idx];
        res_time+=temp;
        res.pb(res_time);
    }

    //for(auto g : res) cout<<g<<" ";
    char process = 'p';
    for(int i=0; i<n; i++){
        cout<<res[i]<<' '<<process<<(id[seq[i]])<<" ";
    }cout<<res[n]<<endl;
}
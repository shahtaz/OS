#include<bits/stdc++.h>
using namespace std;

#define pb push_back


void SSTF_solve(vector<int> &arr, int head);
int get_min_index(vector<int> &arr, int temp_head);
int cal_cyli(vector<int> &res);
int main(){

    //input take
    // inputs --> lower bound, higher bound, num of points, points[n], head

    int upper, lower;
    cout<<"enter [ lower ] [upper]"<<endl;
    cin>> upper>>lower;

    int n;
    cout<<"[num of points]"<<endl;
    cin>>n;

    vector<int> points;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        points.pb(temp);
    }

    int head;
    cout<<"[ head ]"<<endl;
    cin>>head;

    SSTF_solve(points, head);

    return 0;
}

void SSTF_solve(vector<int> &arr, int head){

    //final result will be stored in a vector res
    vector<int> res;
    res.pb(head);

    for(int i=0; i<arr.size(); i++){
        int temp_head = res[res.size()-1];
        // cout<<"temp head -> "<<temp_head<<endl;

        
        int idx = get_min_index(arr, temp_head);
        res.pb(arr[idx]);
        arr[idx] = -1;
    }

    //printing result
        cout<<"queue = "<<endl;
        for(auto u:res) cout<<" "<<u;
        cout<<endl;
        int cylinders = cal_cyli(res);
        cout<<"cylinders = "<<cylinders<<endl;


}



int get_min_index(vector<int> &arr, int temp_head){

    vector<int> diff;

    for(auto u: arr){
        if(u== -1)diff.pb(-1);
        else diff.pb(abs(temp_head-u));
    }

    int indx  = -1 ;

    for(int i=0; i<diff.size(); i++){
        if(arr[i] != -1){
            if(diff[indx]>diff[i]){
                indx = i;
            }
        }
    }

    // for(auto u: diff) cout<<" "<<u;
    // cout<<endl;

    //arr[idx] has the lowest value
    return indx;
}

int cal_cyli(vector<int> &res){
    int f_res = 0;
    for(int i=0; i<res.size()-1; i++){
        f_res+=(abs(res[i]-res[i+1]));
    }
    return f_res;
}
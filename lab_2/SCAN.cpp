#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void cal_scan(vector<int> &arr, int head);
int cal_cyli(vector<int> &res);
int main(){

        // input 1 : lower and upper bound
    // inout 2 : number of points
    // input 3 : enter points
    // input 4 : head value

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

    //input done

    cal_scan(points, head);

    return 0;
}



void cal_scan(vector<int> &arr, int head){
    vector<int> vec_left;
    vector<int> vec_right;

    for(auto u: arr){
        if(u<=head) vec_left.pb(u);
        else vec_right.pb(u);
    }
    vec_left.pb(0);

    //sort the left vec in desc order
    sort(vec_left.begin(), vec_left.end(), greater<int>());
    //sort the right vec in asc order
    sort(vec_right.begin(), vec_right.end());

    vector<int> final;
    final.pb(head);

    for(auto u: vec_left) final.pb(u);
    for(auto u: vec_right)  final.pb(u);
    

    //printing result
    cout<<"queue = ";
    for(auto u: final) cout<<" "<<u;
    cout<<endl;

    int res_f = cal_cyli(final);
    cout<<"cylinders = "<<res_f<<endl;
}

int cal_cyli(vector<int> &res){
    int f_res = 0;
    for(int i=0; i<res.size()-1; i++){
        f_res+=(abs(res[i]-res[i+1]));
    }
    return f_res;
}
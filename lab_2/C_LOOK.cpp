#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void cal_c_look(vector<int> &arr, int head);
int cal_cyli(vector<int> &res);

int main(){

    // input 1 : lower and upper bound
    // inout 2 : number of points
    // input 3 : enter points
    // input 4 : head value

    int upper, lower;
    cout<<"enter [ lower ] [upper]"<<endl;
    cin>> lower>>upper;

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


    cal_c_look(points, head);

    return 0;
}

void cal_c_look(vector<int> &arr, int head){
    //need first and second vector

    vector<int> first;
    vector<int> second;

    for(auto u: arr){
       if(u >= head) first.pb(u);
       else second.pb(u); 
    }

    //sort the both array asc
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    //final result vec

    vector<int> final;
    final.pb(head);
    for(auto u: first) final.pb(u);
    for(auto u: second) final.pb(u);


    //printing final result
    cout<<"queue = ";
    for(auto u: final) cout<<" "<<u;
    cout<<endl;
    cout<<"cylinder = "<<cal_cyli(final)<<endl;
}

int cal_cyli(vector<int> &res){
    int f_res = 0;
    for(int i=0; i<res.size()-1; i++){
        f_res+=(abs(res[i]-res[i+1]));
    }
    return f_res;
}
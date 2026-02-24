#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void cal_C_scan(vector<int> &arr, int head, int upper, int lower);
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

    // cout<<"upper"<<upper;
    // cout<<"lower"<<lower;


    cal_C_scan(points, head, upper, lower);

    return 0;
}

int cal_cyli(vector<int> &res){
    int f_res = 0;
    for(int i=0; i<res.size()-1; i++){
        f_res+=(abs(res[i]-res[i+1]));
    }
    return f_res;
}

void cal_C_scan(vector<int> &arr, int head, int upper, int lower){
    vector<int> first;
    vector<int> second;




    //devide the main array into two part
    for(auto u: arr){
        if(u >= head) first.pb(u);
        else second.pb(u);
    }

    first.pb(upper);
    second.pb(lower);


    //sort the both array asc
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    // cout<<"first = ";
    // for(auto u: first) cout<<" "<<u;

    // cout<<"second = ";
    // for(auto u: second) cout<<" "<<u;

    //creating the path vector
    vector<int> final;
    final.pb(head);
    for(auto u: first) final.pb(u);
    for(auto u: second) final.pb(u);


    // printing the result
    cout<<"queue = ";
    for(auto u: final) cout<<" "<<u;
    cout<<endl;
    cout<<"cylinder = "<<cal_cyli(final)<<endl;
}
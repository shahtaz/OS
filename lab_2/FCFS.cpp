#include<bits/stdc++.h>

using namespace std;

#define pb push_back

//functions

//for printing the path
void cal_path(vector<int> &arr, int head);

//calculate cylinders
void cal_cyl(vector<int> &points, int head);

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

    //for(auto u: points) cout<<u<<" ";

    //for calculate and display the queue path
    cal_path(points, head);

    //calculating the cylinders
    cal_cyl(points, head);
    
    return 0;
}

void cal_path(vector<int> &arr, int head){
    vector<int> res;
    res.pb(head);
    for(auto u: arr) res.pb(u);

    cout<<"FCFS Queue =";
    for(auto u: arr)cout<<" "<<u;
    cout<<endl;
}

void cal_cyl(vector<int> &arr, int head){
    vector<int> res;
    res.pb(head);
    for(auto u: arr) res.pb(u);

    int f_res = 0;

    int l = res.size();
    for(int i=0; i<l-1; i++){
        int flag = abs(res[i]-res[i+1]);
        f_res+=flag;
    }
    cout<<"total head movement = "<<f_res<<" cylinders"<<endl;
}
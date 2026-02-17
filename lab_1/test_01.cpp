#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cout<<"enter the  num of process : ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++ ) cin>>arr[i];

    char proc = 'p';

    vector<int> res;
    int time = 0 ;
    res.push_back(time);

    for(auto u: arr) res.push_back(time+=u);

    int count = 1 ;

    for(auto u: res){
        cout<<u<<" ";
        
        if(count == n+1) break;
        cout<<proc<<count<<" ";
        count++;
    }
}
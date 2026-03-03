#include<bits/stdc++.h>

using namespace std;
#define pb push_back

void print_frame(int arr[], int n);
void print_hit(int n);

bool check_hit(int arr[], int n, int key );

int get_lru_idx(vector<int>& page, int arr[], int n, int start);

int main(){
  string f_name = "input.txt";

  ifstream file(f_name);
  if(!file){
    cout<<"error [open file]"<<endl;
    return 1;
  }

  vector<int> page;
  int temp;

  while(file>>temp){
    page.pb(temp);
  }

  file.close();


  int n =3 ;
  int frame[n];
  for(int i=0; i<n; i++ ) frame[i] = INT_MIN;
  
  int fault = 0;

  for(int i=0; i<page.size(); i++){
    if(i<n){    
        frame[i] = page[i];
        fault++;
        print_frame(frame, n);
    }
    else if(check_hit(frame, n, page[i])){
        print_hit(n);
    }else{
        // get index
        int idx = get_lru_idx(page, frame, n, i); ;
        // add to frame
        frame[idx] = page[i];
        //print frame
        print_frame(frame, n);
        //fault count
        fault++;
    }
  }

  cout<<"page fault = "<<fault<<endl;
  

  return 0;


}

void print_frame(int arr[], int n){
    for(int i=0; i<n; i++ ){
        if(arr[i] == INT_MIN){
            cout<<"-";
        }else{
            cout<<arr[i];
        }cout<<" ";
    }cout<<endl;
}

void print_hit(int n){
    for(int i=0; i<n; i++ ) cout<<"- ";
    cout<<endl;
}

bool check_hit(int arr[], int n, int key ){
    for(int i=0; i<n; i++){
        if(arr[i] == key) return true;
    }

    return false;
}

int get_lru_idx(vector<int>& page, int arr[], int n, int start){
    int dis[n];

    for(int i=0; i<n; i++){
        int temp = arr[i];
        for(int j = start -1 ; j>=0; j--){
            if(page[j]==temp){
                dis[i] = start  - j ;
                break;
            }
        }
    }

    //have the distance vector
    //get the largest value 
    int res_idx = -1;
    int comp_val = INT_MIN;
    for(int i=0; i<n; i++){
        if(dis[i]>comp_val){
            comp_val = dis[i];
            res_idx = i;
        }
    }


    return res_idx;
}






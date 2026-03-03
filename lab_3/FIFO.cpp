#include<bits/stdc++.h>

using namespace std;

#define pb push_back


//functions
void print_frame(int arr[], int n);
void print_hit(int n);
bool check_hit(int arr[], int n, int key);

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
  //reference input done

  int n = 3 ;
  int frame[n];
  for(int i=0; i<n; i++) frame[i] = INT_MIN;
  int idx = 0;

  int page_fault = 0 ;

  //now iterate through the page seq
  for(auto u: page){
    if(check_hit(frame, n, u)==true){
      print_hit(n);
    }else{
      //if not hit update the frame queue
      frame[idx] = u;
      idx++;

      //reset the idx;
      if(idx == n) idx = 0;

      print_frame(frame, n);
      page_fault++;
    }
  }

  cout<<"page fault -> "<<page_fault<<endl;

  return 0;
}


void print_frame(int arr[], int n){
  
  for(int i =0; i<n; i++){
    if(arr[i] == INT_MIN){
      cout<<"-";
    }else{
      cout<<arr[i];
    }

    cout<<" ";
  }

  cout<<endl;
}

void print_hit(int n){
  for(int i=0; i<n; i++){
    cout<<"- ";
  }cout<<endl;
}

bool check_hit(int arr[], int n, int key){
  for(int i=0; i<n; i++){
    if(arr[i]==key) return true;
  }
  return false;
}



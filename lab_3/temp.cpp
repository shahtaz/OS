#include<bits/stdc++.h>

using namespace std;
#define pb push_back


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
  

  return 0;
}

#include<bits/stdc++.h>

using namespace std;


//function
void print_frame(int arr[], int n);
void print_hit(int n);
bool check_hit(int arr[], int n, int key);
int get_max_idx(vector<int>& page, int frame[], int n, int start);


int main(){

    //read the sequence
    ifstream file("input.txt");
    if(!file){
        cout<<"error [ input file ]"<<endl;

        return 1;
    }

    vector<int> page;
    int temp;
    while(file >> temp){
        page.push_back(temp);
    }
    file.close();

    //init the frame arr
    int n = 3;
    int frame[n];
    for(int i=0; i<n; i++) frame[i] = INT_MIN;

    int res_count = 0;

    //iteration 
    for(int i=0; i<page.size(); i++){
        if(i<n){
            frame[i] = page[i];
            res_count++;
            print_frame(frame, n);
        }
        else if(check_hit(frame, n, page[i]) == true ){
            print_hit(n);
        }else{
            //calculte the max dis
            int max_idx = get_max_idx(page, frame, n , i);
            //swap 
            frame[max_idx] = page[i];
            // print the frame
           print_frame(frame, n);
           res_count++;
        }
    }

    cout<<"page fault = "<<res_count<<endl;

    return 0;
}

void print_frame(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==INT_MIN){
            cout<<"-";
        }else{
            cout<<arr[i];
        }cout<<" ";
    }cout<<endl;
}

bool check_hit(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key) return true;
    }

    return false;
}

void print_hit(int n){
    for(int i=0; i<n; i++) cout<<"- ";
    cout<<endl;
}

int get_max_idx(vector<int>& page, int frame[], int n, int start){

    //init the dis arr and assign with int_min
    int dis[n];

    for(int i=0; i<n; i++){
        int terget = frame[i];
        for(int j=start+1; j<page.size(); j++){
            if(page[j]==terget){
                dis[i] = j - start;
                break;
            }
        }
    }

    int max_idx = -1;
    int max_idx_val = INT_MIN;

    for(int i=0; i<n; i++){
        if(dis[i] > max_idx_val){
            max_idx_val = dis[i];
            max_idx=i;
        }
    }
    return max_idx;
}
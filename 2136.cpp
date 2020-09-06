#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 100001
typedef vector<pair<long long, long long> > ant;
bool compare(pair<long long , long long > a, pair<long long, long long >b){
    return abs(a.second) < abs(b.second);
}
int main (){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    long long n,l;
    cin >> n >> l;
    ant arr;
    long long temp, ans =0,index,comp,id,x;
    for(long long i =1;i<=n;i++){
        cin >> index;
        arr.push_back(make_pair(i,index));
        if( index < 0){
            temp = -index;
        }else{
            temp = l - index;
        }
        if(ans < temp){
            ans = temp;
            comp = index;
            x = i;
        }
    }
    // cout << endl << "comp: " << comp << " id: " << x<<endl;
    sort(arr.begin(),arr.end(),compare);
    // for(long long i = 0; i < n;i++){
    //     cout << arr[i].second << " ";
    // }
    // cout <<endl;
    int count=0, vector_id ;
    if(comp >0){
        vector_id = n+1;
        for(long long i =0;i<n;i++){
            if(comp == arr[i].second){
                vector_id = i;
            }
            if( vector_id < i){
                if(arr[i].second <0){
                    count++;
                }
            }
        }
    }else{
        vector_id = -1;
        for(long long i = n-1 ;i >= 0;i--){
            if(comp == arr[i].second){
                vector_id = i;
            }
            if( vector_id > i){
                if(arr[i].second >0){
                    count--;
                }
            }
        }
    }
    // cout << "count: " << count <<" vecotr_id: " << vector_id << endl;
    cout << arr[vector_id+count].first <<" "<< ans;
    return 0;
}
/*
10
1000000000
12312313  
-13421234
345252345
-98234523
76735353   
-12312313
-9874234  
23412485 
96786871
12312311
*/
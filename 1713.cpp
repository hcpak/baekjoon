#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<pair<long long,long long>,long long> a,pair<pair<long long,long long>,long long> b){
    if(a.first.second == b.first.second){
        return a.second > b.second;
    }else{
        return a.first.second > b.first.second;
    }
}
bool final_compare(pair<pair<long long,long long>,long long> a,pair<pair<long long,long long>,long long> b){
    return a.first.first < b.first.first;
}
main(){
    vector<pair<pair<long long,long long>,long long> > v;
    n,m,a;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> a;
        bool flag = false;
        if(v.size() != 0){
            sort(v.begin(),v.end(),compare);
            for(i=0;i<v.size();i++){
                if(v[i].first.first == a){
                    flag = true;
                    v[i].first.second += 1;
                }
            }
        }
        if(!flag && v.size() < n){
            v.push_back(make_pair(make_pair(a,1),i));   
        }else if(!flag && v.size() >= n){
            v.pop_back();
            v.push_back(make_pair(make_pair(a,1),i)); 
        }
    }
    sort(v.begin(),v.end(),final_compare);
    for(i =0;i < v.size();i++){
        if(i != 0)
            cout <<" ";
        cout << v[i].first.first;
    }
    return 0;
}
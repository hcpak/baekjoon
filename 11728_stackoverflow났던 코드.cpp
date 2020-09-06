#include <iostream>
#include <algorithm>
#define NUM 100001
using namespace std;
void merge(long long* res, int start, int mid, int end){
    int j = start, k = mid;
    for(int i = start; i<end;i++){
        if(j == mid){
            res[i] = res[k++];
        }else if( k == end+1){
            res[i] = res[j++];
        }else{
            if(res[j] <res[k]){
                res[i] = res[j++];
            } else{
                res[i] = res[k++];
            }
        }
    }
}
void mergesort(long long* res, int start, int end){
    int mid = (start+end)/2;
    mergesort(res, start, mid);
    mergesort(res, mid, start);
    merge(res, start, mid, end);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    int size = N + M;
    long long res[size+1];
    for(int i = 1; i<= size;i++){
        cin >> res[i];
    }
    mergesort(res,1,size);
    for(int i = 1; i<= size;i++){
        cout << res[i];
        if(i != size){
            cout << " ";
        }
    }
    return 0;
}
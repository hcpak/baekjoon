#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 100001
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    // cout.tie(NULL);
    int N, M;
    int A[MAX];
    cin >> N;
    for(int i =0;i<N;i++){
        cin >> A[i];
    }
    cin >> M;
    sort(A, A+N);
    int wanted;
    for(int i = 0; i<M;i++){
        cin >> wanted;
        int start = -1, end = N+1;
        while(start +1 <end){
            int mid = (start + end)/2;
            if(A[mid] < wanted)
                start = mid;
            else
                end = mid;
        }
        if(A[end] == wanted){
            cout << "1";
        }else{
            cout << "0";
        }
        if(i!=M-1){
            cout<<"\n";
        }
    }
    return 0;
}
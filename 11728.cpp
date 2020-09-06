#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    long long A[N+1],B[M+1],C[N+M+1];
    for(int i = 1; i<=N;i++){
        cin >> A[i];
    }
    for(int i =1; i<=M;i++){
        cin >> B[i];
    }
    int idx1 = 1, idx2= 1;
    for(int i = 1; i <= N +M;i++ ){
        if(idx1 > N)
            C[i] = B[idx2++];
        else if (idx2 > M)
            C[i] = A[idx1++];
        else{
            if(A[idx1] <B[idx2])
                C[i] = A[idx1++];
            else
                C[i] = B[idx2++];
        }
    }
    for( int i =1 ; i<= N+M;i++)
        cout << C[i] << ' ';
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 10000001
using namespace std;
vector<int> arr;
int m, n;
int lower_bound(int target){
    int start = -1, end = n;
    while(start+1 != end){
        int mid = (start +end) /2;
        if(target >arr[mid]){
            start = mid;
        }else{
            end = mid;
        }
    }
    return end;
}
int upper_bound(int target){
    int start = -1, end = n;
    while(start+1 != end){
        int mid = (start +end) /2;
        if(target >=arr[mid]){
            start = mid;
        }else{
            end = mid;
        }
    }
    return end;
}
int main(){
    scanf("%d", &n);
    int temp;
    for(int i =0; i< n;i++){
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    scanf("%d", &m);
    for(int i =0; i<m;i++){
        scanf("%d", &temp);
        int lower = lower_bound(temp),upper = upper_bound(temp);
        printf("%d ",upper-lower);
    }
    printf("\n");
    return 0;
}

#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
intmain(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    intd,n;
    cin >> d >> n;
    intoven[d],depth[d], dough[n];
    for(inti=1;i<=d;i++){
        cin >> oven[i];
        if( i != 1){
            depth[i] = min(depth[i-1],oven[i]);
        }else{
            depth[i] = oven[i];
        }
    }
    for(inti=1;i<=n;i++){
        cin >> dough[i];
    }
    intcount = 1;
    for(inti = d; i>0;i--){
        if(depth[i] >= dough[count]){
            count++;
            if(count == n+1){
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}

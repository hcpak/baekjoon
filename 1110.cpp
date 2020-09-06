#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    int buf = N,a,b,count=0;
    do{
        count++;
        a=buf/10;
        b= buf%10;
        buf = b*10 + (a+b)%10;
    }while(buf !=N);
    cout << count;
	return 0;
}
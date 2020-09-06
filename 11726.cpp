#include <iostream>
using namespace std;
int main (){
	int n;
	cin >> n;
	int Answer[n+1];
	Answer[1]=1;
	Answer[2]=2;
	for(int i = 3; i<=n;i++){
		Answer[i] = (Answer[i-1] +Answer[i-2])%10007; 
	}
	cout << Answer[n]<<endl;
	return 0;
}

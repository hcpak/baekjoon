#include <iostream>
using namespace std;
int main (){
	int n,a;
	int Answer[12];
	Answer[1]=1;
	Answer[2]=2;
	Answer[3]=4;
	for(int i = 4; i<=11;i++){
		Answer[i] = Answer[i-1] + Answer[i-2]+ Answer[i-3]; 
	}
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		cout << Answer[a]<<endl;
	}
	return 0;
}

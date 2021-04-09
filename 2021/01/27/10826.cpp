#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string fib[10001];
void sum(int i){
    string a = fib[i-1], b = fib[i-2];
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string result = "";
    int num,carry =0;
    while (a.length() < b.length()) {
		a += '0';
	}
	while (a.length() > b.length()) {
		b += '0';
	}
    for (int i = 0; i < a.length(); ++i) {
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}
    reverse(result.begin(), result.end());
    fib[i] = result;
}
int main(){
    fib[0] = "0";
    fib[1] = "1";
    int N;
    scanf("%d",&N);
    for(int i=2; i<=N;i++){
        sum(i);
    }
    printf("%s\n",fib[N].c_str());
    return 0;
}
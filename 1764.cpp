#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    set<string> st;
    set<string> answer;
    string str;
    int count =0;
    set<string>::iterator iter;
    for(int i = 0;i<N;i++){
        cin >> str;
        st.insert(str);
    }
    for(int i = 0; i<M;i++){
        cin >> str;
        iter = st.find(str);
        if(iter != st.end())
            answer.insert(*iter);
    }
    cout << answer.size()<<endl;
    for(iter = answer.begin(); iter != answer.end();iter++){
        cout << *iter<<endl;
    }
    return 0;
}
// #include <iostream>
// #include <string>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main(){
//     int N, M;
//     cin >> N >> M;
//     string st[N+M];
//     string ans[N+M];
//     string str;
//     int count =0;
//     for(int i = 0;i<N+M;i++){
//         cin >> st[i];
//     }
//     for(int i = 0; i< N; i++){
//         for(int j = N;j<N+M;j++){
//             if(!st[i].compare(st[j]) && st[i] != "" && st[j] != ""){
//                 ans[count++] = st[i];
//                 st[i] = "";
//                 st[j] = "";
//             }
//         }
//     }
//     cout << count << endl;
//     for(int i=0;i<count;i++){
//         for(int j = 0; j<count; j++){
//             if(ans[i]<ans[j]){
//                 str = ans[i];
//                 ans[i] = ans[j];
//                 ans[j] = str;
//             }
//         }
//     }
//     for(int i =0;i<count;i++){
//         cout << ans[i] << endl;
//     }
//     return 0;
// }
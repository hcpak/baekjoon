// #include <iostream>
// #include <string>
// #define MAX 80
// using namespace std;
// int main(){
//     string str, buf_str;
//     size_t br,hr,blank;
//     string br_line = "\n",
//     hr_line="--------------------------------------------------------------------------------\n";
//     while(cin>>buf_str){
//         if(!buf_str.compare("<hr>")){
//             // cout << str.length()<<endl;
//             if(str.length() == 0){
//                 cout <<hr_line;
//             }else{
//                 cout <<str <<"\n"<<hr_line;
//             }
//             str.clear();
//         }else if(!buf_str.compare("<br>")){
//             cout << str <<br_line;
//             str.clear();
//         }else if(!buf_str.compare("")){
//         }
//         else{
//             // cout << "str.length: " <<str.length() <<" buf_str.length: "<<buf_str.length()<<endl;
//             if(str.length()+buf_str.length()>MAX){
//                 cout << str <<endl;
//                 str.clear();
//             }
//             str.append(buf_str);
//             str.append(" ");
//         }
//     }
//     cout << str;
//     return 0;
// }

#include <iostream>
#include <cstring>
#define MAX 80
using namespace std;
int main(){
    char buf_str[81] ={}, str[81]={};
    while(cin>>buf_str){
        // cout << buf_str<<endl;
        if(!strcmp(buf_str,"<hr>")){
            // cout << strlen(str)<<endl;
            if(strlen(str) == 0){
                cout <<"--------------------------------------------------------------------------------\n";
            }else{
                cout <<str <<"\n" <<"--------------------------------------------------------------------------------\n";
            }
            str[0] ='\0';
        }else if(!strcmp(buf_str,"<br>")){
            cout << str << "\n";
            str[0] ='\0';
        }else{
            if(strlen(str) != 0){
                strcat(str," ");
            }
            if(strlen(buf_str)+strlen(str) > MAX){
                cout << str <<endl;
                str[0] ='\0';
            }
            strcat(str,buf_str);
        }
    }
    cout << str;
    return 0;
}
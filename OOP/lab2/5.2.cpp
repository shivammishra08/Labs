#include <iostream>
#include <cstring>
using namespace std;
void print(char c='*', int n=80){
    for(int i=0; i<n; i++)
        cout << c << ' ';
}
int main(){
    for(int i=0; i<3; i++){
        cout << "\nEnter a charecter : ";
        string s; getline(cin, s);
        if(s.empty()) print('*');
        else{
            cout << "Enter a number : ";
            string t; getline(cin, t);
            if(t.empty()) print(s[0]);
            else{
                int x = stoi(t);
                print(s[0], x);
            }
        }
        cout << "\n";
    }
    return 0;
}
// CHaR aRR VERSION--

#include<iostream>
using namespace std;

int main(){
    int st=0, end=0;
    while(st<end){
        swap(str[st],str[end]);
        st++;
        end--;
    }

}

// string version->
int main(){
   string str= "yoy yoy yoy"
    while(st<end){
       reverse(str.begin(),str.end());
       cout<< str << endl; // iterators
       return 0;
    }

}
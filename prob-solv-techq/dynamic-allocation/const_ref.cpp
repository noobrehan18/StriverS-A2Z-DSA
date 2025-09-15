#include<iostream>
using namespace std;

int main(){
    //constant  int;
   const int i=10;
   int const i2=10;
   //i=20; // error: assignment of read-only variable 'i'

   // constant reference from non-constant variable
   int j=12;
   const int & k1=j; // valid
   const int & k=j;
   k++;  // error: increment of read-only reference 'k'
   j++;   // valid
   cout<<k<<" "<<j<<endl;

   // constant reference from constant variable
   int const j2=20;
   int const & k2=j2; // valid
   j2++; // error: increment of read-only variable 'j2'
   k2++; // error: increment of read-only reference 'k2'

    
   // reference from constant int 
   int const j3=30;
   int & k3=j3; // error: binding reference of type 'int&'



}
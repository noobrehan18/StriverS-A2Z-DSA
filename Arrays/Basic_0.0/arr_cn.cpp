#include<iostream>
using namespace std;

void printArray(int input[]) {
    // print the array..
    for(int i = 0; i < 100; i++) {
        cout << input[i] << endl;
    }  
}

int main() {
    // taking input from the user...

    int n;
    cin>>n;

    int input[100];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    printArray(input);
    // print the array..
    /*for(int i = 0; i < n; i++) {
        cout << input[i] << endl;
    }  
    // find the largest element in the array..
    int max = input[0];
    for(int i = 1; i < n; i++) {
        if(input[i] > max) {
            max = input[i];
        }
    }
    cout << "Largest element is: " << max << endl;*/
}


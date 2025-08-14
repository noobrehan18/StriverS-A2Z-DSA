/*Given an array of length N, you need to find and print the sum of all elements of the array.
Input Format:
Line 1: An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^6
Sample Input :
3
989
Sample Output :
26
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; 

    string num;
    cin >> num; 

    int sum = 0;
    for (char digit : num) {
        sum += digit - '0'; 
    }

    cout << sum << endl;
    return 0;
}


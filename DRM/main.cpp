#include <iostream>
#include <string>
using namespace std;

//A = 65
//Z = 90

string message, first, second;

int trim(int x){
    int value = x;
    //Wrap
    while (x > 90) {
        x = x - 26;
    }
    return x;
}

int main(){

    cin >> message;

    first = message.substr(0, message.length() / 2);
    second = message.substr(message.length() / 2, message.length());

    int length = first.length();
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < length; i++){
        sum1 += (int) first[i] - 65;
    }
    for (int i = 0; i < length; i++){
        sum2 += (int) second[i] - 65;
    }
    for (int i = 0; i < length; i++){
        first[i] = (int)trim((int)(first[i] + sum1));
    }
    for (int i = 0; i < length; i++){
        second[i] = (int)trim((int)(second[i] + sum2));
    }

    //Now we want to merge
    for (int i = 0; i < length; i++){
        first[i] = (int)trim((int)(first[i] + (second[i]) - 65));
    }

    cout << first << endl;
}
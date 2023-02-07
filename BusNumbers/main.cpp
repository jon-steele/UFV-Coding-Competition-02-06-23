#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    

    int n, tempValue = 0;
    int minValue = 99999;
    bool currentChecker = false;
    int busNum[1001];

    cin >> n;

    // Taking in bus numbers
    for (int i = 0; i < n; i++){
        cin >> busNum[i];
    }

    // Sorting bus numbers
    sort(busNum, busNum + n);

    // Checking for shortest representation of list 
    for (int i = 0; i < n; i++){
        tempValue = busNum[i];

        if (busNum[i + 1] == (tempValue + 1)){
            minValue = min(minValue, tempValue);
            currentChecker = true;
        }

        else if (currentChecker == true){
            if (tempValue - minValue == 1){
                cout << minValue << " " << tempValue << " ";
            }

            else {
                cout << minValue << "-" << tempValue << " ";
            }

            currentChecker = false;
            minValue = 999999;
        }

        else {
            cout << tempValue << " ";
        }
    }
}
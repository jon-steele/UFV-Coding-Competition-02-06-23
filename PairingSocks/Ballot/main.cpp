#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, b, counter, citySum;
vector<int> cities;

int check(int ballotValue){
    counter = 0;
    for (int i = 0; i < n; i++){
        if (ballotValue >= cities[i]){
            counter++;
        }

        else {
            counter += (floor(cities[i] / ballotValue) + 1);
        }
    }

    if (counter > b){
        return 1;
    }

    else if (counter < b || ((ballotValue * b) > citySum)){
        return -1;
    }

    else {
        return 0;
    }
}

int main(){

    while(true){
        int cityValue, ballotBox, value = 0;
        citySum = 0;

        cin >> n >> b;

        if (n == -1 && b == -1){
            break;
        }

        for (int i = 0; i < n; i++){
            cin >> cityValue;
            cities.push_back(cityValue);
            citySum += cityValue;
        }   

        ballotBox = round(ballotBox / 2);
        value = 1;

        while (value != 0){
            value = check(ballotBox);

            if (value == 1){
                ballotBox += round(ballotBox / 2);
            }

            else if (value == -1){
                ballotBox -= round(ballotBox / 2);
            }

            else {
                break;
            }
        }

        cout << ballotBox << endl;
    }
}
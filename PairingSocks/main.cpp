#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pile;
vector<int> aux;


int main(){

    cin >> n;
    int sock;

    for (int i = 0; i < 2 * n; i ++){
        cin >> sock;
        pile.push_back(sock);
    }

    int counter = 0;
    bool swapped = false;



    do {
        swapped = false;
        while (!pile.empty()) {
            if (aux.empty()) {
                aux.push_back(pile[0]);
                pile.erase(pile.begin());
                counter++;
            }
            if (pile[0] == aux[0]){
                pile.erase(pile.begin());
                aux.erase(aux.begin());
                counter++;
                swapped = true;
            }
            else {
                aux.push_back(pile[0]);
                pile.erase(pile.begin());
            }
        }
        
        while (!aux.empty()) {
            if (pile.empty()) {
                pile.push_back(aux[0]);
                aux.erase(aux.begin());
                counter++;
            }
            if (aux[0] == pile[0]){
                aux.erase(aux.begin());
                pile.erase(pile.begin());
                counter++;
                swapped = true;
            }
            else {
                pile.push_back(aux[0]);
                aux.erase(aux.begin());
            }
        }
    } while (swapped == true);

    if (!pile.empty() || !aux.empty())
        cout << "impossible" << endl;
    else
        cout << counter << endl;
}
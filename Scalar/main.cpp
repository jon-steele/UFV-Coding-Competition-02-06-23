#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    long long t, n;
    vector<long long> a;
    vector<long long> b;
    long long answers[10];

    cin >> t;

    long long value;
    long long sum1 = 0;

    for (long long i = 0; i < t; i++){
        cin >> n;
        for (long long j = 0; j < n; j++){
            cin >> value;
            a.push_back(value);
        }
        for (long long j = 0; j < n; j++){
            cin >> value;
            b.push_back(value);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        reverse(a.begin(), a.end());

        long long size = a.size();

        for (long long j = 0; j < n; j++){
            sum1 = sum1 + (a[j] * b[j]);
        }

        a.clear();
        b.clear();

        answers[i] = sum1;

        sum1 = 0;
    }

    for (long long i = 1; i <= t; i++){
        cout << "Case #" << (i) << ": " << answers[i - 1] << endl;
    }
}
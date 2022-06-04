#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> task1(const vector<int> &v) {
    vector<int> v_copy = v;
    int actual= v[0], cont=1;
    int agg=0;
    for (int i=1; i<v.size()+1; i++) {
        if (actual == v[i]) 
            cont++;
        else {
            v_copy.insert(v_copy.begin()+i+agg, cont);
            agg++;
            actual = v[i];
            cont = 1;
        }
    }
    return v_copy;
}

vector<int> task2(const vector<int> &v) {
    vector<int> v_copy = v;
    int agg=0;
    for (int i=0; i<v.size(); i++) {
        if (abs(v[i])%2 != 0 && v[i] < 0) {
            v_copy.erase(v_copy.begin()+i-agg);
            agg++;
        }
    }
    return v_copy;
}

vector<int> task3(const vector<int> &v) {
    vector<int> v_copy = v;
    int impar = 0;
    for (int i=0; i<v.size(); i++) {
        if (abs(v[i]) % 2 != 0 && v[i] > 0) {
            if (v[i] > impar)
                impar = v[i];
        }
    }
    v_copy.resize(impar);
    for (int i=0; i<v_copy.size(); i++) {
        if (v_copy[i] == 0)
            v_copy[i] = -1;
    }
    return v_copy;
}

int main() {
    vector<int> v1 = {1,1,1,2,2,3,3,3,3};
    vector<int> v2 = {1,3,4,-2,5,-3,-3,3};
    vector<int> v3 = {8,3,7,-2,2};
    // vector<int> result = task1(v1);
    // vector<int> result = task2(v2);
    vector<int> result = task3(v3);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
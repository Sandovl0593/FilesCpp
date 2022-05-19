#pragma region 
#ifndef _PRINTT
#define _PRINTT

#include <iostream>
#include <vector>
using namespace std;

void printt_vet(vector<int> &vector) {
    cout << "{";
    for (int i=0; i<vector.size()-1;i++)
        cout << vector.at(i) << ", ";
    cout << vector.at(vector.size()-1) <<"}" << endl;
}

#pragma endregion
#endif // FILE_PRINTT.H
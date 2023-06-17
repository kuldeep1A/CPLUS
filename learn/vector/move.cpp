#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> sourceVec = {1, 2, 3, 4, 5};
    vector<int> destinationVec = move(sourceVec);
    // After the move, sourceVec is in a valid but unspecified state,
    // and destinationVec contains the data from sourceVec.

    cout << "sourceVec: " << sourceVec.size()<< endl;
    cout << "destinationVec: " << destinationVec.size() << endl;
    destinationVec[3] = 43;
    for(int ele: destinationVec){
        cout << ele << " ";
    }

    cout << endl;
    sourceVec.push_back(2);
    cout << "sourceVec: " << sourceVec.size()<< endl;
    cout << "destinationVec: " << destinationVec.size() << endl;
    
}
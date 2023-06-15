#include <iostream>

using namespace std;

int main(){
    string food = "Pizza";
    string* ptr = &food;
    

    cout << &food << "\n";

    cout << *ptr << endl;


    *ptr = "new Pizza";
    cout << *ptr << endl;
    
    return 0;

}
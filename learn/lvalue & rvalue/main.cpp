#include <iostream>
using namespace std;

void PrintName(string &name)
{
    cout << name << endl;
}

void PrintName(string &&name)
{
    cout << name << endl;
}

int main()
{
    string firstName = "k_name";
    string lastName = "l_name";

    string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName(firstName + lastName);
}
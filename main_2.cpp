#include "iostream"
#include "stdlib.h"
using namespace std;
int main()
{
    int i, n = rand() % 100;
    do
    {
        cout << endl << "Please enter the correct number : ";
        cin >> i;
        if (i == n)
            break;
        if (n > i)
        {
            cout << "No, Try a greater number.";
            continue;
        }
        cout << "No, Try a smaller number.";
    } while (i!=n);
}
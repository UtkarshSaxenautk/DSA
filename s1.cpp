#include <iostream>
using namespace std;

class Airthematic
{
public:
    int num1;
    int num2;
    char op;
    void add()
    {
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    }
    void subtract()
    {
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    }
    void multiply()
    {
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    }
    void divide()
    {
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    }
};

int main()
{
    cout << "Enter number 1 , operator and number 2 "
         << "\n";
    Airthematic A;
    cin >> A.num1 >> A.op >> A.num2;
    switch (A.op)
    {
    case '+':
        A.add();
        break;
    case '-':
        A.subtract();
        break;

    case '*':
        A.multiply();
        break;
    case '/':
        A.divide();
        break;
    default:
        "Choose correct operator.";
        break;
    }
}
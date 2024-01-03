// create a calculator which can add, divide, subtract, multiply two values

#include <iostream>

using namespace std;

double AddValue(double, double);
double SubtractValue(double, double);
double MultiplyValue(double, double);
double DivideValue(double, double);

double AcceptValue(int);

int MainMenu();
bool EndMenu();

int main()
{
    const int MAXVALUE = 2;

    int actionChoosen;
    string selectedAction;
    double val1, val2, result = 0;

    do
    {
        actionChoosen = MainMenu();

        system("cls");

        for (int counter = 0; counter < MAXVALUE; counter++)
        {
            if (counter == 0)
                val1 = AcceptValue(counter);
            else
                val2 = AcceptValue(counter);
        }

        switch (actionChoosen)
        {
        case 1: // Add
            result = AddValue(val1, val2);
            selectedAction = " + ";
            break;
        case 2:// Subtract
            result = SubtractValue(val1, val2);
            selectedAction = " - ";
            break;
        case 3:// Multiply
            result = MultiplyValue(val1, val2);
            selectedAction = " x ";
            break;
        case 4:// Divide
            result = DivideValue(val1, val2);
            selectedAction = " / ";
            break;
        default:
            cout << "Choice is out of range";
            break;
        }

        cout << val1 << selectedAction << val2 << " = " << result << endl << endl;
        system("pause");
        system("cls");
    } while (EndMenu());

}

double AddValue(double val1, double val2)
{
    return val1 + val2;
}

double SubtractValue(double val1, double val2)
{
    return val1 - val2;
}

double MultiplyValue(double val1, double val2)
{
    return val1 * val2;
}

double DivideValue(double val1, double val2)
{
    if (val2 == 0)
    {
        cout << "Undefined";
        return 0;
    }

    return val1 / val2;
}

double AcceptValue(int counter)
{
    double input;

    cout << "Enter Value " << counter + 1 << ":";
    cin >> input;

    return input;
}

int MainMenu()
{
    int actionChoosen;

    cout
        << "Welcome this is Calculator that accepts 2 Value\n"
        << "1. Add\n"
        << "2. Subtract\n"
        << "3. Multiply\n"
        << "4. Divide\n"
        << "\n"
        << "Enter Action: ";
    cin >> actionChoosen;

    return actionChoosen;
}

bool EndMenu()
{
    string answer;

    cout << "Want to do another math problem?";
    cin >> answer;

    if (answer.find('y') != string::npos)
    {
        return 1;
    }
    else
        return 0;
}

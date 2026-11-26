#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <limits>
#include <stdexcept>

using namespace std;

const int MAX_CUSTOMERS = 500;
const int MAX_TECHNICIANS = 100;
const int MAX_PARTS = 300;
const int MAX_JOBS = 1000;

string readLine(const string& message)
{
    string value;
    cout<<message;
    getline(cin,  value);
    return value;
}
int readInt(const string& message)
{
    int value;
    while(true)
    {
        cout<<message;
        if(cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
            cout << "Please enter a valid whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
double readDouble(const string& message)
{
    double value;
    while(true)
    {
        cout<<message;
        if(cin>>value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(value>=0)
            return value;
        }

        cout<<"Please enter a non-negative amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool isBlank(const string& value)
{
    return value.find_first_not_of(" \t\r\n")==string::npos;
}

void checkRequired(const string& value, const string& field)
{
        if(isBlank(value))
               throw invalid_argument(field + "cannot be empty.");
}
void line()
{
    cout<<"----------------------------------------------------------\n";
}

string todayDate()
{
    time_t now=time(0);
    tm* local=localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local);
    return buffer;
}

template <class T>
void showMessage(const T& message)
{
    cout<<message<<'\n';
}

template <class T>
class SimpleBox
{
    private:
       T value;
    
    public:
       SimpleBox() : value() {}
       SimpleBox(T input) : value(input) {}

       void setValue(T input)
       {
        value = input;
       }

       T getValue() const
       {
        return value;
       }
};

template <>
class SimpleBox<string>
{
    private:
       string value;

    public: 
       SimpleBox() : value("") {}
       SimpleBox(string input) : value(input) {}

       void setValue(string input){}
}
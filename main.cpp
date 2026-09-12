#include <array>
#include <iostream>
#include <string>

#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::duration;
using std::array;

void print(string msg, float delay);
void printWord(string msg, float delay);
array<float, 2> debug();

int main()
{   
    string msg;

    float charDelay = 0.25;
    float wordDelay = 0.4;

    cout << "Please enter a msg : ";
    getline(cin,msg);

    while (msg == "debug")
    {
        array<float,2> vars;
        vars = debug();
        charDelay = vars[0];
        wordDelay = vars[1];

        cout << "Please enter a msg : ";
        getline(cin,msg);
    }

    printWord(msg, wordDelay);

    return 0;
}

void print(string msg, float delay)
{
    for ( char ch : msg)
    {
        sleep_for(duration<float>(delay));
        cout << ch;
    }

}

void printWord(string msg, float delay)
{
    sleep_for(duration<float>(delay)); // initial delay
   
    for (char ch : msg)
    {
        if (ch != ' ')
        {
            cout << ch;
        }
        else 
        {
            cout << " ";
            sleep_for(duration<float>(delay));
        }
    }
    sleep_for(duration<float>(delay));
}

array<float,2> debug()
{   
    array<float,2> vars;
    cout << "Enter a value for char delay : ";
    cin >> vars[0];
    cout << "Enter a value for word delay : ";
    cin >> vars[1];

    cin.ignore();

    return vars;
    
}
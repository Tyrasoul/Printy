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

void print(string msg, float delay);
void printWord(string msg, float delay);

int main()
{   
    string msg;

    float charDelay = 0.25;
    float wordDelay = 0.4;

    cout << "Please enter a msg : ";
    getline(cin,msg);

    //add debug here to change chardelay and worddelay

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
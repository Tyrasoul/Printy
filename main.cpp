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

const float charDelay = 0.25;

void print(string msg, float delay);

int main()
{   
    string msg;

    cout << "Please enter a msg : ";
    getline(cin,msg);

    print(msg, charDelay);
}

void print(string msg, float delay = charDelay)
{   int i;
    for ( char ch : msg)
    {
        sleep_for(duration<float>(delay));
        cout << ch;
    }

}
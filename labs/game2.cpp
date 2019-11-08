#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int defSize = 4;
const int minSize = 3;
const int maxSize = 6;

using namespace std;

int parseCmdLineArgs(int argc, char* argv[]);
vector<string> fillNumbers(int n);
void showHelp(int n);
string getUserNumber(const vector<string>& numbers);
void analyze(const string& compNumber, const string& userNumber, int& dig, int& pos);

int main(int argc, char* argv[])
{
    srand(time(0));
    
    int n = parseCmdLineArgs(argc, argv);

    vector<string> numbers = fillNumbers(n);
    
    random_shuffle(begin(numbers), end(numbers));
    string compNumber = numbers.front();
    
    showHelp(n);

    int moves = 0;
    int dig = 0;
    int pos = 0;
    
    while (dig != n || pos != n)
    {
        string userNumber = getUserNumber(numbers);
        analyze(compNumber, userNumber, dig, pos);
        cout << "digits   : " << dig << endl;
        cout << "positions: " << pos << endl;
        ++moves;
    }
    
    cout << "You are winner!!!" << endl;
    cout << "Your result is " << moves << (moves == 1? " move.": " moves.") << endl;
}

int parseCmdLineArgs(int argc, char* argv[])
{
    int res = defSize;
    
    if (argc == 2)
    {
        int t; 
        istringstream sinp(argv[1]);
        if (sinp >> t >> ws && sinp.eof())
        {
            t = abs(t);
            res = minSize <= t && t <= maxSize ? t: defSize;
        }
    }
    
    return res;
}

vector<string> fillNumbers(int n)
{
    vector<int> lowBounds = {102, 1023, 10234, 102345};
    vector<int> uppBounds = {987, 9876, 98765, 987654};
        
    vector<string> res;
    
    for (int i = lowBounds[n - minSize]; i <= uppBounds[n - minSize]; ++i)
    {
        string t = to_string(i);
        set<char> s(t.begin(), t.end());
        if (size(s) == n)
        {
            res.push_back(t);
        }
    }
    
    return res;
}

void showHelp(int n)
{
    cout << "------------------------BULLS AND COWS-----------------------------------" << endl;
    cout << "Computer chose " << n << "-digit number without repeating digits." << endl;
    cout << "Your goal is to guess it. After each try computer shows 2 numbers: " << endl;
    cout << "Digits   : <how many digits you guessed>" << endl;
    cout << "Positions: <how many of them are in correct place>" << endl;
    cout << "Good luck!" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

string getUserNumber(const vector<string>& numbers)
{
    for (;;)
    {
        cout << "your guess: ";
        string line;
        getline(cin, line);
        istringstream sinp(line);
        int t;
        if (sinp >> t >> ws && sinp.eof())
        {
            string res = to_string(t);
            if (find(begin(numbers), end(numbers), res) != end(numbers))
            {
                return res;
            }
        }
        cout << "Incorrect number. Try again..." << endl;
    }
}

void analyze(const string& compNumber, const string& userNumber, int& dig, int& pos)
{
    dig = 0;
    pos = 0;
    for (int i = 0; i < int(size(userNumber)); ++i)
    {
        for (int j = 0; j < int(size(compNumber)); ++j)
        {
            if (userNumber[i] == compNumber[j])
            {
                ++dig;
                pos += i == j;
            }
        }
    }
}
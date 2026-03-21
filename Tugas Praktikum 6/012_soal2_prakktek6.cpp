#include <iostream>
#include <string>

using namespace std;

int hitungKarakter(string *input)
{
    int totalKarakter = 0;

 
    for (int i = 0; i < input->length(); i++)
    {

        if (input->at(i) != ' ')
        {
            totalKarakter++;
        }
    }

    return totalKarakter;
}

int main()
{
    string input;
    getline(cin, input);

    cout << hitungKarakter(&input);

    return 0;
}
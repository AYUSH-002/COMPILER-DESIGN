#include <bits/stdc++.h>
using namespace std;
string input;
int P = 0;
void error()
{
    cout << "Error in parsing!\n";
    exit(1);
}
void match(char expected)
{
    if (input[P] == expected)
    {
        P++;
    }
    else
    {
        error();
    }
}
void E();
void Eprime();
void T();
void Tprime();
void F();
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (input[P] == '+')
    {
        match('+');
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if (input[P] == '*')
    {
        match('*');
        F();
        Tprime();
    }
}
void F()
{
    if (isalnum(input[P]))
    {
        P++;
    }
    else if (input[P] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else
    {
        error();
    }
}
int main()
{
    cout << "Enter an arithmetic expression: ";
    cin >> input;
    E();
    if (P == input.length())
    {
        cout << "Parsing successful!\n";
    }
    else
    {
        cout << "Parsing failed!\n";
    }
    return 0;
}


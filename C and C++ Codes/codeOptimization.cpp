#include <bits/stdc++.h>
using namespace std;
struct Expression
{
    string id;
    string value;
};
void eliminateCommonSubexpressions(map<string, Expression> &expressions)
{
    map<string, string> subexpressions;
    for (auto &entry : expressions)
    {
        const string &id = entry.first;
        Expression &expression = entry.second;
        if (subexpressions.find(expression.value) !=
            subexpressions.end())
        {
            expression.value = subexpressions[expression.value];
        }
        else
        {
            subexpressions[expression.value] = expression.id;
        }
    }
}
int main()
{
    map<string, Expression> expressions = {
        {"A", {"expr1", "a + b"}},
        {"B", {"expr2", "a + b"}},
        {"C", {"expr3", "c + d"}},
        {"D", {"expr4", "c + d"}},
        {"E", {"expr5", "e * f"}},
        {"F", {"expr6", "e * f"}},
    };
    //Here we can use the same code for different expressions as well by putting them in map
    cout << "Expressions before common subexpression elimination : " << endl;
                      for (const auto &entry : expressions)
    {
        cout << entry.first << ": " << entry.second.value << endl;
    }
    eliminateCommonSubexpressions(expressions);
    cout << "Expressions after common subexpression elimination : " << endl;
                      for (const auto &entry : expressions)
    {
        cout << entry.first << ": " << entry.second.value << endl;
    }
    return 0;
}

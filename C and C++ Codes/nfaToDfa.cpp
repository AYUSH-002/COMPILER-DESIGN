#include <bits/stdc++.h>
using namespace std;
void printNfa(vector<vector<vector<int>>> table)
{
    // Print the header row
    cout << " STATE/INPUT | ";
    char a = 'a';
    for (int i = 0; i < table[0].size() - 1; i++)
    {
        cout << " " << a++ << "| ";
    }
    cout << " ^ "
         << "\n"
         << "\n";
    for (int i = 0; i < table.size(); i++)
    {
        // Print the state number
        cout << " " << i << " ";
        for (int j = 0; j < table[i].size(); j++)
        {
            // Print the separator
            cout << " | ";
            for (int k = 0; k < table[i][j].size(); k++)
            {
                // Print the output states for each input symbol
                cout << table[i][j][k] << " ";
            }
        }
        cout << "\n";
    }
}
void printdfa(vector<vector<int>> states, vector<vector<vector<int>>>
                                              dfa)
{
    // Print the header row
    cout << " STATE/INPUT ";
    char a = 'a';
    for (int i = 0; i < dfa[0].size(); i++)
    {
        cout << " | " << a++ << " ";
    }
    cout << "\n";
    for (int i = 0; i < states.size(); i++)
    {
        // Print the state set
        cout << " { ";
        for (int h = 0; h < states[i].size(); h++)
            cout << states[i][h] << " ";
        if (states[i].empty())
        {
            cout << " ^ ";
        }
        cout << " } ";
        for (int j = 0; j < dfa[i].size(); j++)
        {
            // Print the output states for each input symbol
            cout << " | ";
            for (int k = 0; k < dfa[i][j].size(); k++)
            {
                cout << dfa[i][j][k] << " ";
            }
            if (dfa[i][j].empty())
            {
                cout << " ^ ";
            }
        }
        cout << "\n";
    }
}
vector<int> closure(int s, vector<vector<vector<int>>> v)
{
    vector<int> t;
    queue<int> q;
    t.push_back(s);
    int a = v[s][v[s].size() - 1].size();
    for (int i = 0; i < a; i++)
    {
        t.push_back(v[s][v[s].size() - 1][i]);
        q.push(t[i]);
    }
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (!v[f][v[f].size() - 1].empty())
        {
            int u = v[f][v[f].size() - 1].size();
            for (int i = 0; i < u; i++)
            {
                int y = v[f][v[f].size() - 1][i];
                if (find(t.begin(), t.end(), y) == t.end())
                {
                    t.push_back(y);
                    q.push(y);
                }
            }
        }
    }
    return t;
}
int main()
{
    int noOfStates, noOfAlphabets;
    cout << "------------------- NFA to DFA --------------------"
         << "\n"
         << "\n";
    cout << "Enter total number of states in NFA: ";
    cin >> noOfStates;
    cout << "Enter number of elements in alphabet: ";
    cin >> noOfAlphabets;
    vector<vector<vector<int>>> table;
    for (int i = 0; i < noOfStates; i++)
    {
        cout << "For state " << i << "\n";
        vector<vector<int>> v;
        char a = 'a';
        int y, yn;
        for (int j = 0; j < noOfAlphabets; j++)
        {
            vector<int> t;
            cout << "Enter no. of output states for input " << a++ << " : ";
            cin >> yn;
            cout << "Enter output states: "
                 << "\n";
            for (int k = 0; k < yn; k++)
            {
                cin >> y;
                t.push_back(y);
            }
            v.push_back(t);
        }
        vector<int> t;
        cout << "Enter no. of output states for input ^ : ";
        cin >> yn;
        cout << "Enter output states :"
             << "\n";
        for (int k = 0; k < yn; k++)
        {
            cin >> y;
            t.push_back(y);
        }
        v.push_back(t);
        table.push_back(v);
    }
    cout << "---------- TRANSITION TABLE OF NFA ----------"
         << "\n";
    printNfa(table);
    cout << "\n"
         << "---------- TRANSITION TABLE OF DFA ----------"
         << "\n";
    vector<vector<vector<int>>> dfa;
    vector<vector<int>> states;
    states.push_back(closure(0, table));
    queue<vector<int>> q;
    q.push(states[0]);
    while (!q.empty())
    {
        vector<int> f = q.front();
        q.pop();
        vector<vector<int>> v;
        for (int i = 0; i < noOfAlphabets; i++)
        {
            vector<int> t;
            set<int> s;
            for (int j = 0; j < f.size(); j++)
            {
                for (int k = 0; k < table[f[j]][i].size(); k++)
                {
                    vector<int> cl = closure(table[f[j]][i][k],
                                             table);
                    for (int h = 0; h < cl.size(); h++)
                    {
                        if (s.find(cl[h]) == s.end())
                            s.insert(cl[h]);
                    }
                }
            }
            for (set<int>::iterator u = s.begin(); u != s.end(); u++)
                t.push_back(*u);
            v.push_back(t);
            if (find(states.begin(), states.end(), t) ==
                states.end())
            {
                states.push_back(t);
                q.push(t);
            }
        }
        dfa.push_back(v);
    }
    printdfa(states, dfa);
}

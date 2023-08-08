#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> st;
vector<char> a;

void stackInp(){ 
  cout<<"\n$";
  for(auto x: st)
      cout<<x;
  cout<<"\t";
  for(auto x : a)
      cout<<x;
}
void evaluate()
{   
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='I')
        {
            st[i]='S';
            stackInp();
            cout<<"$\t"<<"REDUCE S->ID";
            evaluate(); 
        }
        if(st[i]=='N')
        {
            st[i]='S';
            stackInp();
            cout<<"$\t"<<"REDUCE S->NUM";
            evaluate();
        }
        if(i+2<st.size() && st[i]=='S'&& (st[i+1]==('+') || st[i+1]==('*')||st[i+1]==('-')||st[i+1]==('/')) && st[i+2]=='S')
        {
            st.pop_back();
            st.pop_back();
            stackInp();
            if(st[i+1]=='+')
              cout<<"$\t"<<"REDUCE S->S+S";
            else if(st[i+1]=='*')
              cout<<"$\t"<<"REDUCE S->S*S";
            else if(st[i+1]=='-')
              cout<<"$\t"<<"REDUCE S->S-S";
            else if(st[i+1]=='/')
            cout<<"$\t"<<"REDUCE S->S/S";
        }
    }
}
int main()
{
    cout<<"GRAMMAR is : \n S->S+S\n S->S-S \n E->S*S \n S->S/S\n S->(S)\n S->I\n S->N\n";
    cout<<"Enter the input string: "<<endl;
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
      a.push_back(s[i]);

    cout<<"\nStack\t Input\tOperation";
    for(int i=0;i<n;i++)
    {
        st.push_back(a[i]);
        a[i]=' '; 
        stackInp();
        cout<<"$\t"<<"SHIFT->"<<st.back();
        evaluate();
    }
    if(st.size()==1 && st[0]=='S')
        cout<<"\n\nString accepted";
    else
        cout<<"\n\nString rejected";

    cout<<endl;
}


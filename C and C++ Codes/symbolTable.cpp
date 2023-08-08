#include <bits/stdc++.h>
#define null nullptr
using namespace std;

int size=0;
struct node
{
    char label[10];
    int addr;
    node *next;
};

node *first=null, *last=null;

void insert();
void display();
void del();
void modify();
int search(char []);

int main()
{
    int Option, y;
    char lable[10];

    do
    {
        cout << "\nSYMBOL TABLE IMPLEMENTATION\n";
        cout << "1.INSERT\n";
        cout << "2.DISPLAY\n";
        cout << "3.DELETE\n";
        cout << "4.SEARCH\n";
        cout << "5.MODIFY\n";
        cout << "6.END\n";
        cout << "\nEnter the option which you want from the above given options: "<<endl;
        cin >> Option;
        switch(Option)
        {
            case 1:
                insert();
                display();
                break;
            case 2:
                display();
                break;
            case 3:
                del();
                display();
                break;
            case 4:
                cout << "Enter the label to be searched: "<<endl;
                cin >> lable;
                y = search(lable);
                if(y == 1)
                    cout << "The label is already present in the symbol table"<<endl;
                else
                    cout << "The label is not present in the symbol table"<<endl;
                break;
            case 5:
                modify();
                display();
                break;
            case 6:
                break;
            default:
                cout << "Invalid option"<<endl;
                break;
        }
    } while(Option < 6);

    return 0;
}

void insert()
{
    int n;
    char l[10];
    cout << "Enter the identifier input: "<<endl;
    cin >> l;
    n = search(l);
    if(n == 1)
        cout << "The label is already present in the symbol table. Duplicate cannot be inserted"<<endl;
    else
    {
        node *p = new node;
        strcpy(p->label, l);
        cout << "Enter the address: "<<endl;
        cin >> p->addr;
        p->next = null;
        if(size == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        size++;
    }
}

void display()
{
    node *p = first;
    cout << "LABEL ADDRESS"<<endl;
    for(int i = 0; i < size; i++)
    {
        cout << p->label << "      " << p->addr << "\n";
        p = p->next;
    }
}

int search(char lab[])
{
    int flag = 0;
    node *p = first;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(p->label, lab) == 0)
            flag = 1;
        p = p->next;
    }
    return flag;
}

void modify()
{
    char l[10], nl[10];
    int add, choice, s;
    node *p = first;
    cout << "What do you want to modify?\n";
    cout << "1.Only the label\n";
    cout << "2.Only the address of a particular label\n";
    cout << "3.Both the label and address\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: {
        cout << "Enter the old label: ";
        char l[10], nl[10];
        cin >> l;
        cout << "Enter the new label: ";
        cin >> nl;
        int s = search(l);
        if (s == 0) {
            cout << "\nNo such label";
        }
        else {
            struct node *p = first;
            for (int i = 0; i < size; i++) {
                if (strcmp(p->label, l) == 0) {
                    strcpy(p->label, nl);
                }
                p = p->next;
            }
        }
        break;
    }
    case 2: {
        cout << "Enter the label whose address is to be modified: ";
        char l[10];
        cin >> l;
        cout << "Enter the new address: ";
        int add;
        cin >> add;
        int s = search(l);
        if (s == 0) {
            cout << "\nNo such label";
        }
        else {
            struct node *p = first;
            for (int i = 0; i < size; i++) {
                if (strcmp(p->label, l) == 0) {
                    p->addr = add;
                }
                p = p->next;
            }
        }
        break;
    }
    case 3: {
        cout << "Enter the old label: ";
        char l[10], nl[10];
        cin >> l;
        cout << "Enter the new label: ";
        cin >> nl;
        cout << "Enter the new address: ";
        int add;
        cin >> add;
        int s = search(l);
        if (s == 0) {
            cout << "\nNo such label";
        }
        else {
            struct node *p = first;
            for (int i = 0; i < size; i++) {
                if (strcmp(p->label, l) == 0) {
                    strcpy(p->label, nl);
                    p->addr = add;
                }
                p = p->next;
            }
        }
        break;
    }
    }
}
void del() {
    int a;
    char l[10];
    node *p, *q;
    p = first;
    cout << "Enter the label to be deleted: ";
    cin >> l;
    a = search(l);
    if (a == 0)
        cout << "Label not found\n";
    else {
        if (strcmp(first->label, l) == 0)
            first = first->next;
        else if (strcmp(last->label, l) == 0) {
            q = p->next;
            while (strcmp(q->label, l) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = nullptr;
            last = p;
        }
        else {
            q = p->next;
            while (strcmp(q->label, l) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
        }
        size--;
    }
}

#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class Role{
    protected:
        string username;
        string password;
    public:
        friend ofstream &operator <<(ofstream &ofs, Role &R);
        friend ifstream &operator >>(ifstream &ifs, Role &R);
        friend ostream &operator <<(ostream &out, Role &R);
        friend istream &operator >>(istream &in, Role &R);
};

class Admin : public Role{
    public:
        string ret_user()
        {
            return username;
        }
};

class User : public Role{
    public:
        string ret_user()
        {
            return username;
        }
};

ofstream &operator <<(ofstream &ofs, Role &R)
{
    ofs<<R.username<<" "<<R.password<<endl;
    return ofs;
}

ifstream &operator >>(ifstream &ifs, Role &R)
{
    ifs>>R.username;
    ifs>>R.password;
    return ifs;
}

istream &operator >>(istream &in, Role &R)
{
    string p1, p2;
    cout<<"Please Enter Username and Password both in LOWERCASE and WITHOUT SPACES.\n\n";
    cout<<"Enter Username: ";
    in>>R.username;
    cout<<"Enter Password: ";
    in>>p1;
    cout<<"Confirm Password: ";
    in>>p2;
    while(p1!=p2)
    {
        cout<<"Passwords don't Match. Please Enter Again!\n";
        cout<<"Enter Password: ";
        in>>p1;
        cout<<"Confirm Password: ";
        in>>p2;
    }
    R.password = p1;
    return in;
}

ostream &operator <<(ostream &out, Role &R)
{
    out<<"Username: "<<R.username<<"\tPassword: "<<R.password<<endl;
    return out;
}

void user_registration()
{
    system("cls");
    User U;
    string us, pass;
    int allowed = 0;
    while(allowed == 0)
    {
        system("cls");
        cout<<"USER REGISTRATION PORTAL\n";
        cin>>U;
        ifstream ifs("User.txt");
        while (!ifs.eof())
        {
            ifs>>us>>pass;
            if(U.ret_user() == us)
            {
                allowed = 0;
                cout<<"Username Already Exists. Please Try Another One!\n";
                system("pause");
                break;
            }
            allowed = 1;
        }
        ifs.close();
    }
    if(allowed == 1)
    {
        ofstream ofs("User.txt", ios::app);
        ofs<<U;
        ofs.close();
        cout<<"User Account Created Successfully.\n";
    }
    cout<<"Press Any Key to Continue.\n";
    getch();
}

void admin_registration()
{
    system("cls");
    Admin A;
    string us, pass;
    int allowed = 0;
    while(allowed == 0)
    {
        system("cls");
        cout<<"ADMIN REGISTRATION PORTAL\n";
        cin>>A;
        ifstream ifs("Admin.txt");
        while (!ifs.eof())
        {
            ifs>>us>>pass;
            if(A.ret_user() == us)
            {
                allowed = 0;
                cout<<"Username Already Exists. Please Try Another One!\n";
                system("pause");
                break;
            }
            allowed = 1;
        }
        ifs.close();
    }
    if(allowed == 1)
    {
        ofstream ofs("Admin.txt", ios::app);
        ofs<<A;
        ofs.close();
        cout<<"Admin Account Created Successfully.\n";
    }
    
    cout<<"Press Any Key to Continue.\n";
    getch();
}

/*int main()
{
    /*Role *ptr;
    Admin A;
    User U;
    int n;
    string file;
    cout<<"REGISTRATION PORTAL"<<endl;
    cout<<"1. ADMIN REGISTRATION"<<endl;
    cout<<"2. USER REGISTRATION"<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            ptr = &A;
            file = "Admin.txt";
            break;
        }
        case 2:
        {
            ptr = &U;
            file = "User.txt";
            break;
        }
    }
    /*ofstream ofs(file, ios::app);
    cin>>*ptr;
    ofs<<*ptr;
    ofs.close();
    ifstream ifs(file);
    while(!ifs.eof())
    {
        ifs>>*ptr;
        cout<<*ptr;
    }
    ifs.close();
    user_registration();
    return 0;
}*/
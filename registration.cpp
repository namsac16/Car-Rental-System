#include <iostream>
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
};

class User : public Role{
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
    User U;
    cout<<"USER REGISTRATION PORTAL\n";
    ofstream ofs("User.txt", ios::app);
    cin>>U;
    ofs<<U;
    ofs.close();
    cout<<"User Account Created Successfully.\n";
    cout<<"Press Any Key to Continue.\n";
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
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include "registration.cpp"

using namespace std;

void login()
{
    int n;
    string file;
    string a_user, a_pass;
    bool u_success = false, p_success = false, success = false;
    string user, pass;
    while(!success)
    {
        system("cls");
        cout<<"LOGIN PORTAL\n";
        cout<<"1. ADMIN LOGIN"<<endl;
        cout<<"2. USER LOGIN"<<endl;
        cin>>n;
        system("cls");
        switch(n)
        {
            case 1:
            {
                file = "Admin.txt";
                break;
            }
            case 2:
            {
                file = "User.txt";
                int x;
                cout<<"1. LOGIN AS EXISTING USER\n";
                cout<<"2. CREATE NEW USER ACCOUNT\n";
                cin>>x;
                switch(x)
                {
                    case 1 : break;
                    case 2 : 
                    {
                        system("cls");
                        user_registration();
                        getch();
                        continue;
                    }
                }
                break;
            }
        }
        system("cls");
        cout<<"Enter Username: ";
        cin>>user;
        cout<<"Enter Password: ";
        cin>>pass;
        ifstream ifs(file);
        while(!ifs.eof())
        {
            ifs>>a_user>>a_pass;
            if(user == a_user)
            {
                u_success = true;
                if(pass == a_pass)
                    p_success = true;
                break;
            }
        }
        if(u_success == false)
            cout<<"No Such User Exists\n";
        else if(p_success == false)
            cout<<"Incorrect Password\n";
        else if(u_success == true and p_success == true)
            success = true;
        if(success == true)
            cout<<"LOGIN SUCCESSFUL\n";
        else
            cout<<"LOGIN FAILED\n";
        cout<<"\nPress Any Key to Continue\n";
        getch();
        ifs.close();
    }
}

/*int main()
{
    login();
    return 0;
}*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "registration.cpp"
#include "admin_menu.cpp"
#include "user_menu.cpp"

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
        u_success = false, p_success = false;
        system("cls");
        cout<<"Welcome To Naman's Car Rental Portal\n";
        cout<<"LOGIN PORTAL\n";
        cout<<"1. ADMIN LOGIN"<<endl;
        cout<<"2. USER LOGIN"<<endl;
        cout<<"3. EXIT"<<endl;
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
                        continue;
                    }
                }
                break;
            }
            case 3: {exit(0);}
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
        if(n == 1 && success == true)
            admin_menu(success);
        else if(n == 2 && success == true)
            user_menu(success, user);
    }
}

/*int main()
{
    login();
    return 0;
}*/
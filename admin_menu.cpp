#include <iostream>
#include "cars.cpp"
//#include "registration.cpp"

using namespace std;

void admin_menu(bool &success)
{
    int n;
    while(1)
    {
        system("cls");
        cout<<"ADMIN MENU\n";
        cout<<"1. Add New Car\n";
        cout<<"2. Update Fare\n";
        cout<<"3. Create New Admin\n";
        cout<<"4. Logout\n";
        cout<<"Select Option: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                input_car();
                break;
            }
            case 2 : break;
            case 3:
            {
                admin_registration();
                break;
            }
            case 4:
            {
                success = false;
                return;
            }
        }
    }
}

/*int main()
{
    admin_menu();
    return 0;
}*/
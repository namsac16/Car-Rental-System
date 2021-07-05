#include <iostream>
#include <fstream>
#include "book_car.cpp"
#include "car_rates.cpp"

using namespace std;

void user_menu(bool &success)
{
    int n;
    while(1)
    {
        system("cls");
        cout<<"1. Book A Car\n";
        cout<<"2. Rate Menu\n";
        cout<<"3. Logout\n";
        cout<<"Select Option: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                int x;
                system("cls");
                cout<<"CAR RENTAL PORTAL\n";
                cout<<"Types of Cars Available are:\n";
                cout<<"1. Hatchback\n";
                cout<<"2. Sedan\n";
                cout<<"3. MUV\n";
                cout<<"4. SUV\n";
                cout<<"5. Traveller\n";
                cout<<"6. Bus\n";
                cout<<"Select your Option: ";
                cin>>x;
                switch (x)
                {
                    case 1:
                    {
                        book_car("Hatchback");
                        break;
                    }
                    case 2:
                    {
                        book_car("Sedan");
                        break;
                    }
                    case 3:
                    {
                        book_car("Multi-Utility Vehicle (MUV)");
                        break;
                    }
                    case 4:
                    {
                        book_car("Sports-Utility Vehicle (SUV)");
                        break;
                    }
                    case 5:
                    {
                        book_car("Traveller");
                        break;
                    }
                    case 6:
                    {
                        book_car("Bus");
                        break;
                    }
                }
                break;
            }
            case 2: 
            {
                display();
                break;
            }
            case 3:
            {
                success = false;
                return;
            }
        }
    }
}

/*int main()
{
    user_menu();
    return 0;
}*/
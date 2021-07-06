#include <iostream>
#include <fstream>
#include "book_car.cpp"
#include "car_rates.cpp"

using namespace std;

void user_menu(bool &success, string user, string pass)
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
                string model;
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
                        model = "Hatchback";
                        break;
                    }
                    case 2:
                    {
                        model = "Sedan";
                        break;
                    }
                    case 3:
                    {
                        model = "Multi-Utility Vehicle (MUV)";
                        break;
                    }
                    case 4:
                    {
                        model = "Sports-Utility Vehicle (SUV)";
                        break;
                    }
                    case 5:
                    {
                        model = "Traveller";
                        break;
                    }
                    case 6:
                    {
                        model = "Bus";
                        break;
                    }
                }
                book_car(model, user, pass);
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
#include <iostream>

using namespace std;

void display()
{
    system("cls");
    cout<<"1. Booking Charge per Car is Rs. 2000 which has to paid at the time of booking.\n";
    cout<<"2. There are different rates depending on the type of car booked which should be paid after the travel is complete.\n";
    cout<<"   Rates for Various Types of Cars are as follows:\n";
    cout<<"\t-> HatchBack : Rs. 25 per km\n";
    cout<<"\t-> Sedan : Rs. 30 per km\n";
    cout<<"\t-> MUV : Rs. 35 per km\n";
    cout<<"\t-> SUV : Rs. 40 per km\n";
    cout<<"\t-> Traveller : Rs. 45 per km\n";
    cout<<"\t-> Bus : Rs. 50 per km\n";
    cout<<"3. For In-Station Travel a fixed cost for 80 kms has to be paid per day. Extra Cost per km should be paid after that.\n";
    cout<<"4. For Out-Station Travel a fixed cost for 200 kms has to be paid per day. Extra Cost per km should be paid after that.\n";
    cout<<"5. Extra Rs. 500 per day has to paid as Driver's Night Cost if a driver has also been booked.\n";
    cout<<"6. All the Toll and Car Charges including Petrol Charges would be paid by the User.\n";
    getch();
}

/*int main()
{
    display();
    system("pause");
}*/
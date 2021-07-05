#include <iostream>

using namespace std;

float calculate_fare(string mod, int days, int kms[], string type)
{
    float cost = 0.0;
    int min_kms = 0;
    float fare = 0.0;

    if(mod == "Hatchback")
        cost = 25.0;
    else if(mod == "Sedan")
        cost = 30.0;
    else if(mod == "Multi-Utility Vehicle (MUV)")
        cost = 35.0;
    else if(mod == "Sports-Utility Vehicle (SUV)")
        cost = 40.0;
    else if(mod == "Traveller")
        cost = 45.0;
    else if(mod == "Bus")
        cost = 50.0;

    if(type == "In")
        min_kms = 80;
    else if(type == "Out")
        min_kms = 200;

    for(int i = 0; i<days; i++)
    {
        fare = fare + (cost*min_kms);
        if(kms[i] > min_kms)
            fare = fare + ((kms[i] - min_kms) * cost);
    }
    return fare;
}

float calculate_fare(int days)
{
    return 500.0*days;
}

float calculate_fare()
{
    return 2000;
}

/*int main()
{
    Car *ptr;
    int kms[] = {30, 85, 125, 45, 98, 78};
    HatchBack H("xyz", "yz", "yy", 5);
    ptr = &H;
    float ans = calculate_fare(ptr, 6, kms, "In") + calculate_fare(6) + calculate_fare();
    cout<<ans;
    return 0;
}*/
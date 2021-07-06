#include <iostream>

using namespace std;

float calculate_fare(string mod, int days, string type)
{
    float cost = 0.0;
    int min_kms = 0;

    if(mod == "Hatchback")
        cost = 15.0;
    else if(mod == "Sedan")
        cost = 20.0;
    else if(mod == "Multi-Utility Vehicle (MUV)")
        cost = 25.0;
    else if(mod == "Sports-Utility Vehicle (SUV)")
        cost = 30.0;
    else if(mod == "Traveller")
        cost = 35.0;
    else if(mod == "Bus")
        cost = 40.0;

    if(type == "In")
        min_kms = 80;
    else if(type == "Out")
        min_kms = 200;

    return cost*min_kms*days;
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
    float ans = calculate_fare("Hatchback", 6, "In") + calculate_fare(6) + calculate_fare();
    cout<<ans;
    return 0;
}*/
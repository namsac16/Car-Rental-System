#include <iostream>
#include <cmath>

using namespace std;

bool check_leap(int yy)
{
    if(yy % 400 == 0)
        return true;
    else if(yy % 4 == 0 && yy%100 != 0)
        return true;
    return false;
}

int calc_days(int dd, int mm, int yy)
{
    int ans = 0;
    for(int i = 1900; i<yy; i++)
    {
        if(check_leap(i))
            ans+=366;
        else
            ans+=365;
    }
    for(int i = 1; i<mm; i++)
    {
        switch(i)
        {
            case 1: ans += 31; break;
            case 2: ans += check_leap(yy) ? 29 : 28; break;
            case 3: ans += 31; break;
            case 4: ans += 30; break;
            case 5: ans += 31; break;
            case 6: ans += 30; break;
            case 7: ans += 31; break;
            case 8: ans += 31; break;
            case 9: ans += 30; break;
            case 10: ans += 31; break;
            case 11: ans += 30; break;
            case 12: ans += 31; break;
        }
    }
    return ans+= dd;
}

/*int main()
{
    int days = fabs((calc_days(2, 1, 2021) - calc_days(2, 1, 2021)));
    cout<<days;
    return 0;
}*/
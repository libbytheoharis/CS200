#ifndef _LOCATION_HPP
#define _LOCATION_HPP

#include <string>
using namespace std;

class Location
{
    public:
    void Setup( const string& name, int ammo, int food );

    string GetName();
    int GetAmmo();
    int GetFood();

    private:
    string m_name;
    int m_ammo;
    int m_food;
};

#endif

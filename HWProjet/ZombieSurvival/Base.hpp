#ifndef _BASE_HPP
#define _BASE_HPP

#include <string>
using namespace std;

class Base
{
    public:
    Base();

    int GetAmmo();
    int GetFood();
    int TakeFood( int desiredAmount );
    void SetAmmo( int amount );
    void AddAmmo( int amount );
    void AddFood( int amount );
    void SubtractAmmo( int amount );
    void SubtractFood( int amount );

    private:
    int m_food;
    int m_ammo;
};

#endif

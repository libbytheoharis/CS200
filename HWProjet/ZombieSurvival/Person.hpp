#ifndef _PERSON_HPP
#define _PERSON_HPP

#include <string>
#include <fstream>
using namespace std;

class Person
{
    public:
    void Setup( const string& name );
    void DisplayStats();
    void Update();

    string GetName();
    int GetHunger();
    bool IsDead();
    void Hurt( int amount );
    void Eat( int amount );

    private:
    string m_name;
    int m_hunger;
    int m_health;
};

#endif

/*
DON'T MODIFY THIS FILE
*/

#ifndef _PROGRAM_HPP	// Don't allow duplicates
#define _PROGRAM_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

#include "Base.hpp"
#include "Person.hpp"
#include "Location.hpp"

class Program
{
public:
    Program();
    ~Program();

    void Main();

    void Setup();
    void Cleanup();

private:
    void LoadLocations();
    void LoadPeople();
    void SetupDynamicArrays();

    void DisplayWeekStats();
    void UpdateTeam();
    void ScavengePhase();
    void ZombiePhase();
    bool IsEveryoneDead();
    void DisplaySummary();
    void RoundPause();

private:
    Base m_base;
    Location* m_locationList;
    int m_locationCount;
    Person* m_team;
    int m_teamCount;

    int m_week;

    friend class Tester;
};

#endif

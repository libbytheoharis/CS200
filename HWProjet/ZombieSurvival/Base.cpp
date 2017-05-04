#include "Base.hpp"

//! Initialize the base's ammo and food to 10 each.
Base::Base()
{
	m_food = 10;
	m_ammo = 10;
}

//! Returns the amount of ammo the base has.
/**
    @return <int>           The amount of ammo that the base has, from m_ammo.
*/
int Base::GetAmmo()
{
	return m_ammo;
}

//! Returns the amount of food the base has.
/**
    @return <int>           The amount of food that the base has, from m_food.
*/
int Base::GetFood()
{
	return m_food;
}

//! Attempts to take the desired amount of food, but if desired amount is more than what base has, just return total food quantity instead.
/**
    The amount of food desired is passed in as a parameter. Check the amount of food stores the base has (m_food).

    If m_food is more than the desiredAmount, subtract the desiredAmount from m_food
    and return the desiredAmount.

    If there is not enough m_food, then you will return the quantity of food m_food,
    and set m_food to zero.

    @param desiredAmount <int>      The amount of food we would like to retrieve.
    @return <int>                   The amount of food that is actually returned.
*/
int Base::TakeFood( int desiredAmount )
{
	if (m_food > desiredAmount)
	{
		m_food -= desiredAmount;
		return desiredAmount;
	}
	else
	{
		int tempFood = m_food;
		m_food = 0;
		return tempFood;
	}
}

//! Update the private member variable m_ammo to the value passed in.
/**
    @param amount <int>     Set the private member variable m_ammo to the amount passed in.
    @return <void>
*/
void Base::SetAmmo( int amount )
{
	m_ammo = amount;
}

//! Add some amount to the quantity of ammo the base has.
/**
    @param amount <int>     Add the amount passed in to the current amount of ammo the base has (m_ammo).
    @return <void>
*/
void Base::AddAmmo( int amount )
{
	m_ammo += amount;
}

//! Add some amount to the quantity of food the base has.
/**
    @param amount <int>     Add the amount passed in to the current amount of food the base has (m_food).
    @return <void>
*/
void Base::AddFood( int amount )
{
	m_food += amount;
}

//! Subtract some amount from the quantity of ammo the base has.
/**
    @param amount <int>     Subtract the amount passed in to the current amount of ammo the base has (m_ammo).
    @return <void>
*/
void Base::SubtractAmmo( int amount )
{
	m_ammo -= amount;
}

//! Subtract some amount from the quantity of food the base has.
/**
    @param amount <int>     Subtract the amount passed in to the current amount of food the base has (m_food).
    @return <void>
*/
void Base::SubtractFood( int amount )
{
	m_food -= amount;
}


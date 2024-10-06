#pragma once 



#include"MetroSystem.h"


using namespace std;




class Admin
{
private:
	MetroSystem& metroSystem; // Reference to the MetroSystem object

public:
	string name;
	string fixed_Password;


	//they will be helper functions 
	void create_Subscription_Plan();
	void update_Subscription_Plan();
	void remove_Subscription_Plan();
	//this is the fare management that enable the admin to control the price of each stage 
	void edit_StageAmount();





};


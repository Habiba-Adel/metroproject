#pragma once

#include<string>
#include"SubscriptionPlan.h"
#include"Period.h"
using namespace std;

// in the .h file i just put the declartions of the methods and the constructors and the defination in the .cpp file  


class Subscription
{
private:
  // the default access modifier for the class is private
	string start_Date;
	string end_Date;
	SubscriptionPlan type;
	int available_Trips;
	bool active; // 0 for no and 1 for yes 
	int card; // it will be multiply 10 always if the plan is not fixed and its max value will be 400 always and he has an access to charge it and with every check in and check out this card decreases deponds on how many stages you go 
	// if the plan is fixed i will put in the card 0 and he can not access it or charge it 


	//........................................................the methods part ......................................................//
public:
	Period choosen;
	Stage schoosen;
	int stationnum;

	// Getters
	string getStartDate();
	string getEndDate();
	SubscriptionPlan getType();
	int getAvailableTrips();
	bool isActive();
	int getCard();

	// Setters
	void setStartDate(string date);
	void setEndDate(string date);
	void setType(SubscriptionPlan subscriptionPlan);
	void setAvailableTrips(int trips);
	void setActive(bool isActive);
	void setCard(int cardValue);


	void purchase_Subscription(); // done
	void view_Subscription_details(); // done
	void renew_Subscription();
	void upgrade_Subscription(Subscription copy);
	

};


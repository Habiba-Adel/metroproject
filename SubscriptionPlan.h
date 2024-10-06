#pragma once

#include<string>
#include<vector>
#include"Period.h"

using namespace std;

//class MetroSystem;  // it called a forward declartION 


class SubscriptionPlan
{
public:
	string name;
private:
	bool fixed; //if it fixed or flexable like the cash wallet
	vector<Period>periods;
	

public:
	void add_Subscription_Plan(); //done
	void edit_Subscription_Plan(); //done
	void delete_Subscription_Plan(); //done
	void display_All_Plans(); //done 

    // Getters
   
    bool isFixed() ;
     vector<Period>& getPeriods() ;
	 void addPeriod(Period& period);

    // Setters
    
    void setFixed(bool isFixed);

    // Methods to manage periods
  
};




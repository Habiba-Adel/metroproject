#pragma once

#include <iostream>
#include<unordered_map>
#include"MetroSystem.h"
#include"User.h"
#include"SubscriptionPlan.h"
#include"Subscription.h"
using namespace std;




int main()
{
	//it must put in the metro system class 
	//cout << "elhamdoulelallah \n";

	MetroSystem metro;
	SubscriptionPlan plan;

	// this for testing the subscriptions plans for the admin and it is done 
	while (true)
	{
		
		cout << "enter 1 to display \n";
		cout << "enter 2 to add \n";
		cout << "enter 3 to edit \n";
		cout << "enter 4 to delete \n";
		cout << "enter 5 ti exist \n";
		int num;
		cin >> num;
		if (num == 1)
		{
			plan.display_All_Plans();
		}
		else if (num == 2)
		{
			SubscriptionPlan newone;
			newone.add_Subscription_Plan();
		}
		else if (num == 4)
		{
			plan.delete_Subscription_Plan();
		}
		else if (num == 3)
			plan.edit_Subscription_Plan();
		else
			break;
	}


	//now testing the part of the subscription for the user 
	User user;
	while (true)
	{
		// now in subscription and renew and upgrade there is a check it must be done first that there is no any subscriptions he subscribe on it now 
		cout << "enter 1 to display details  \n";
		cout << "enter 2 to subscribe \n";
		cout << "enter 3 to renew \n";
		cout << "enter 4 to upgrade \n";
		cout << "enter 5 to see the history \n";
		cout << "enter 6 to stop your current subscription \n";
		int num;
		cin >> num;
		if (num == 1)
		{
			if (user.current.isActive())//if he have one active it will be in the current so he can view else no
				user.current.view_Subscription_details();
			else
				cout << "there is no any active subscription \n";
			//plan.display_All_Plans();
		}
		else if (num == 2)
		{
			if (user.current.isActive())//if is account still active 
			{
				cout << "you an not subscribe on any other subscribtions until the current one finish. \n";
			}
			else
			{
				Subscription temp;
				temp.purchase_Subscription();
				user.history.push_back(user.current);
				user.setCurrent(temp);
			}
			
		}
		else if (num == 3)
		{
			// in the renew plan we must first chech if its current subscription is active or not 
			if (user.current.isActive())
				cout << "you can not renew until your currnet one finished. \n";
			else
			{
				user.history.push_back(user.current);//push the old 
				user.current.renew_Subscription();
			}

		}
		else if (num == 4)
		{
			// in the upgrade plan we must first chech if its current subscription is active or not 
			if (user.current.isActive())
				cout << "you can not upgrade until your currnet one finished. \n";
			else
			{
				Subscription copy = user.current;
				user.history.push_back(user.current);//push the old 
				user.current.upgrade_Subscription(copy);
			}
		}
		else if (num == 5)
		{
			for (auto it : user.history)// it must display all the details for every subscription in this history
			{
				cout << it.getAvailableTrips();
			}
		}
		else if(num==6) {
			//plan.edit_Subscription_Plan();
		}
		else
		{

		}
	}


	return 0;
}


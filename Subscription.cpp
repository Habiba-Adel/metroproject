#include "Subscription.h"
#include"MetroSystem.h"
#include"Period.h"
#include"Stage.h"
#include<iostream>
#include"SubscriptionPlan.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>



// Getters
string Subscription::getStartDate() {
	return start_Date;
}

string Subscription::getEndDate() {
	return end_Date;
}

SubscriptionPlan Subscription::getType() {
	return type;
}

int Subscription::getAvailableTrips() {
	return available_Trips;
}

bool Subscription::isActive() {
	return active;
}

int Subscription::getCard() {
	return card;
}

// Setters
void Subscription::setStartDate(string date) {
	start_Date = date;
}

void Subscription::setEndDate(string date) {
	end_Date = date;
}

void Subscription::setType(SubscriptionPlan subscriptionPlan) {
	type = subscriptionPlan;
}

void Subscription::setAvailableTrips(int trips) {
	available_Trips = trips;
}

void Subscription::setActive(bool isActive) {
	active = isActive;
}

void Subscription::setCard(int cardValue) {
	card = cardValue;
}



// tested done except the name of the plan 
//trying to make the end date manual 
void Subscription:: purchase_Subscription() {
	SubscriptionPlan t;
	t.display_All_Plans();
	while (true) {
		string name;
		cout << "Enter the name of plan you want to sunscribe on it . \n";
		cin >> name;
		auto it = MetroSystem::availablePlans.find(name);
		if (it == MetroSystem::availablePlans.end())//it means the name is not existed 
		{
			cout << "It is invalid name please enter the exactrly name as shown. /n";
			continue;
		}
		else  //it means the name is existed 
		{


			// first we will display all periods in this plan to make him choose one of them
			int i = 0;
			SubscriptionPlan& tempplan = MetroSystem::availablePlans[name];
			vector<Period>& v = tempplan.getPeriods();

			for (auto& iter : v)
			{

				cout << "----* Period: " << ++i << "  *----\n";
				cout << "the name of period is " << iter.name << "\n";
				cout << "the trips is " << iter.getTotalTrips() << "\n";
				vector<Stage>& temp2 = iter.getStages();
				for (auto& stage : temp2)
				{
					cout << "name: " << stage.name << "\n";
					cout << "price: " << stage.getprice() << "\n";

				}
				cout << "========================================================= \n";

			}

			int cc;
			while (true)
			{
				cout << "enter the number of the period you want to subscribe on it  \n ";
				cin >> cc;
				if (cc >= 1 && cc <= v.size())
					break;
				else {
					cout << "this number doesnot exist please try again \n";
					continue;
				}
			}
			cc--;
			cout << "enter the number of stations \n";
			cin>>stationnum;
			vector<Stage>ss=v[cc].getStages();
			cout << "the vector stages size is " << ss.size() << "\n";
			if (stationnum >= 1 && stationnum <= 9)
			{
				schoosen = ss[0];
			}
			else if (stationnum >= 10 && stationnum <= 16)
			{
				schoosen = ss[1];
			}
			else if (stationnum >= 17 && stationnum <= 23)
			{
				schoosen = ss[2];
			}
			else
				schoosen = ss[3];

			
			// now i have which plan and which period he want from inside to it
			choosen = v[cc];
			//string x= MetroSystem::availablePlans[name].name;
			//type.name =x ;
			//  first we will need to determine the start date and the end date
			{
				time_t now = time(nullptr);
				tm localTime;
				localtime_s(&localTime, &now);
				//  format the date
				start_Date = to_string(localTime.tm_year + 1900) + "-" +
					to_string(localTime.tm_mon + 1) + "-" +
					to_string(localTime.tm_mday);
				string duration = v[cc].name;
				// Parse the start date
				struct tm startTm = {};
				stringstream ss(start_Date);
				ss >> get_time(&startTm, "%Y-%m-%d");

				// Extract the number and the unit from the period
				auto spacePos = duration.find(' ');
				if (spacePos == string::npos) {
					throw invalid_argument("Invalid period format.");
				}

				int num = stoi(duration.substr(0, spacePos));
				string unit = duration.substr(spacePos + 1);

				// Calculate the end date
				if (unit == "day" || unit == "days") {
					startTm.tm_mday += num; // Add days
				}
				else if (unit == "month" || unit == "months") {
					startTm.tm_mon += num; // Add months
				}
				else if (unit == "year" || unit == "years") {
					startTm.tm_year += num; // Add years
				}
				else {
					throw invalid_argument("Invalid time unit.");
				}

				// Normalize the tm structure (e.g., handle overflow of days/months)
				mktime(&startTm);

				// Convert back to string
				char buffer[11]; // YYYY-MM-DD is 10 characters + 1 for null terminator
				strftime(buffer, sizeof(buffer), "%Y-%m-%d", &startTm);
				end_Date = string(buffer);

			}

			//now making the other things 
			setActive(true);

			if (name == "wallet")
			{
				v[cc].name = "unlimited";
				int temp;
				while (true) {

					cout << "Enter the balance (Card limit can't exceed 400 LE and amount of money (Multiples of 10)) \n";
					cin >> temp;
					if (temp <= 400 && (temp % 10 == 0))break;
					else if (temp > 400 || (temp % 10 != 0)) cout << "The value is invalid, try again \n ";
				}

				setCard(temp);

			}
			setAvailableTrips(v[cc].getTotalTrips());





		}

		cout << "congratualtions \n";
		return;

	}
		
	}

	// tested done except the name of the plan 
void Subscription::view_Subscription_details()
{
	    
		cout << "\n--------------------------\n";
		cout << " subscribtion status : ";  (isActive()) ? cout << "active\n" : cout << "not active\n";
		cout << " the type of subscribtion: " << type.name << "\n";
		cout << " period: " << choosen.name  <<  "\n";
		if (getType().name != "wallet") {
			cout << " number of stations: " << stationnum << "\n";
			cout << " the type of stage: " << schoosen.name << "\n";
			cout << " total trips : " << choosen.getTotalTrips() << "\n";
			cout << " remaining trips: " << getAvailableTrips() << "\n";
			cout << " price: " << schoosen.getprice() << "LE\n";
			cout << "ExpiryDate: " << getEndDate() << "\n";
			cout << "start Date: " << getStartDate() << "\n";
			cout << "--------------------------";
			return;
		}
		cout << "balanc :" << card << "\n";
		cout << "--------------------------\n";
}

//checking about how he can renew if he dioesnot subscribe in any before 
void Subscription::renew_Subscription() {

	if (type.name == "wallet")
	{
		cout << "can not renew \n";
		return;
	}
	// in the renew we just rennew the start date and the end date and the total trips only
			active = true;
			{
				time_t now = time(nullptr);
				tm localTime;
				localtime_s(&localTime, &now);
				//  format the date
				start_Date = to_string(localTime.tm_year + 1900) + "-" +
					to_string(localTime.tm_mon + 1) + "-" +
					to_string(localTime.tm_mday);
				string duration = choosen.name;
				// Parse the start date
				struct tm startTm = {};
				stringstream ss(start_Date);
				ss >> get_time(&startTm, "%Y-%m-%d");

				// Extract the number and the unit from the period
				auto spacePos = duration.find(' ');
				if (spacePos == string::npos) {
					throw invalid_argument("Invalid period format.");
				}

				int num = stoi(duration.substr(0, spacePos));
				string unit = duration.substr(spacePos + 1);

				// Calculate the end date
				if (unit == "day" || unit == "days") {
					startTm.tm_mday += num; // Add days
				}
				else if (unit == "month" || unit == "months") {
					startTm.tm_mon += num; // Add months
				}
				else if (unit == "year" || unit == "years") {
					startTm.tm_year += num; // Add years
				}
				else {
					throw invalid_argument("Invalid time unit.");
				}

				// Normalize the tm structure (e.g., handle overflow of days/months)
				mktime(&startTm);

				// Convert back to string
				char buffer[11]; // YYYY-MM-DD is 10 characters + 1 for null terminator
				strftime(buffer, sizeof(buffer), "%Y-%m-%d", &startTm);
				end_Date = string(buffer);

			}

			available_Trips = choosen.getTotalTrips();
		
			cout << " Congratulations Your subscription is been active now again! ^^ \n";
		
}

		

// the upgrade here will be based on the user can only upgrade to plan that will give him more number of trips only if it will not so he can not upgrade if he wnat to upgrade to the same plan so we will make him to renew  

void Subscription::upgrade_Subscription(Subscription copy)
{
	// first i will display all the plans available in our system;
	cout << "this is all the plans in our system choose any to upgare to it. \n";
	cout << " in our system you can only to upgrade to the plan that will give you more trips. \n";
	SubscriptionPlan t;
	t.display_All_Plans();
	while (true) {
		string name;
		cout << "Enter the name of plan you want to sunscribe on it . \n";
		cin >> name;
		auto it = MetroSystem::availablePlans.find(name);
		if (it == MetroSystem::availablePlans.end())//it means the name is not existed 
		{
			cout << "It is invalid name please enter the exactrly name as shown. /n";
			continue;
		}
		else  //it means the name is existed 
		{


			// first we will display all periods in this plan to make him choose one of them
			int i = 0;
			SubscriptionPlan& tempplan = MetroSystem::availablePlans[name];
			vector<Period>& v = tempplan.getPeriods();
			cout << "the periods in this plan are : \n";
			for (auto& iter : v)
			{

				cout << "----* Period: " << ++i << "  *----\n";
				cout << "the name of period is " << iter.name << "\n";
				cout << "the trips is " << iter.getTotalTrips() << "\n";
				vector<Stage>& temp2 = iter.getStages();
				for (auto& stage : temp2)
				{
					cout << "name: " << stage.name << "\n";
					cout << "price: " << stage.getprice() << "\n";

				}
				cout << "========================================================= \n";

			}

			int cc;
			while (true)
			{
				cout << "enter the number of the period you want to subscribe on it  \n ";
				cin >> cc;
				if (cc >= 1 && cc <= v.size())
					break;
				else {
					cout << "this number doesnot exist please try again \n";
					continue;
				}
			}
			cc--;

			//now checking about the plan name and the period name that they are not the same as the last current
			if (v[cc].name == copy.choosen.name && copy.getType().name == name)
			{
				while (true)
				{


					cout << "it is the same of the last subscription do you want to renew it?enter(y||n) \n";
					char let;
					cin >> let;
					if (let == 'y' || let == 'Y')
					{
						renew_Subscription();
						break;
					}
					else if (let == 'n' || let == 'N')
					{
						cout << "so choose again the plan you want to upgrade to it. \n";
						upgrade_Subscription(copy);
						break;
					}
					else
						cout << "invalid choice. \n";
				}
			}

			// now checking is done we want to know now the number of trips
			if (v[cc].getTotalTrips() <= copy.choosen.getTotalTrips())//it doesnot achieve the upgrade condition 
			{
				cout << "you only can upgrade to plan which have more number of trips than your last subscription. \n";
				cout << "so try again . \n";
				upgrade_Subscription(copy);
			}
			else
			{
				// now this the main logic of the upgrade
				// first gettting the new start date and the end date 
				{
					time_t now = time(nullptr);
					tm localTime;
					localtime_s(&localTime, &now);
					//  format the date
					start_Date = to_string(localTime.tm_year + 1900) + "-" +
						to_string(localTime.tm_mon + 1) + "-" +
						to_string(localTime.tm_mday);
					string duration = v[cc].name;
					// Parse the start date
					struct tm startTm = {};
					stringstream ss(start_Date);
					ss >> get_time(&startTm, "%Y-%m-%d");

					// Extract the number and the unit from the period
					auto spacePos = duration.find(' ');
					if (spacePos == string::npos) {
						throw invalid_argument("Invalid period format.");
					}

					int num = stoi(duration.substr(0, spacePos));
					string unit = duration.substr(spacePos + 1);

					// Calculate the end date
					if (unit == "day" || unit == "days") {
						startTm.tm_mday += num; // Add days
					}
					else if (unit == "month" || unit == "months") {
						startTm.tm_mon += num; // Add months
					}
					else if (unit == "year" || unit == "years") {
						startTm.tm_year += num; // Add years
					}
					else {
						throw invalid_argument("Invalid time unit.");
					}

					// Normalize the tm structure (e.g., handle overflow of days/months)
					mktime(&startTm);

					// Convert back to string
					char buffer[11]; // YYYY-MM-DD is 10 characters + 1 for null terminator
					strftime(buffer, sizeof(buffer), "%Y-%m-%d", &startTm);
					end_Date = string(buffer);

				}
				// determine the new subscription plan and the new number of available trips
				choosen = v[cc];
				setAvailableTrips(choosen.getTotalTrips());
				active = 1;

			}
		}
	}
	

}




		//void Subscription::upgrade_Subscription()
		//{    
		//	// think more about if there will be any checks must making before allow to the user to upgrade qits plan 
		//
		//
		//	if (active == false)// so the admin stop this subscription and thats mean he can upgrade
		//	{
		//		display_Subscription_Plans();
		//		while (true) {
		//			string name;
		//			cout << "Enter the name of plan you want to upgrade to it . \n";
		//			cin >> name;
		//			auto it = metroSystem.availablePlans.find(name);
		//			if (it == metroSystem.availablePlans.end())//it means the name is not existed 
		//			{
		//				cout << "It is invalid name please enter the exactrly name as shown. /n";
		//				continue;
		//			}
		//			else  //it means the name is existed 
		//			{
		//				    type = it->second;
		//				if (type.fixed) {
		//					while (true) {
		//						cout << "Enter in which stage you want your subscription \n";
		//						char letter;
		//						cin >> letter;
		//						if (letter == '1')
		//							price = type.amount_ForEachStage[0];
		//						else if (letter == '2')
		//							price = type.amount_ForEachStage[1];
		//						else if (letter == '3')
		//							price = type.amount_ForEachStage[2];
		//						else if (letter == '4')
		//							price = type.amount_ForEachStage[3];
		//						else
		//						{
		//							cout << "Invalid stage number please try again \n";
		//							continue;
		//						}
		//						break;
		//					}
		//				}
		//				break;
		//
		//				// now we upgrade the type of the plan and the price so we will renew it 
		//			}
		//
		//		}
		//		cout << "Your subscription plan was upgraded successfully! ^^ \n";
		//		renew_Subscription();
		//	}
		//
		//	else
		//	{
		//		cout << "Your subscription is still active you can only upgrade after finishing the current subscription. \n";
		//		return;
		//	}
		//}
		////  EDIT RENEW , UPGRADE 


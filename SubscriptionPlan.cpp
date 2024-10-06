#include "SubscriptionPlan.h"
#include"MetroSystem.h"
#include"Period.h"
#include"Stage.h"
#include<iostream>
using namespace std;
#include<string>

// Getter for fixed
bool SubscriptionPlan::isFixed()  {
    return fixed;
}

// Setter for fixed
void SubscriptionPlan::setFixed(bool isFixed) {
    fixed = isFixed;
}

// Getter for periods
 vector<Period>& SubscriptionPlan::getPeriods() {
    return periods;
}

// Method to add a period
void SubscriptionPlan::addPeriod( Period& period) {
    periods.push_back(period);
}

//tested done 
void SubscriptionPlan::display_All_Plans()
{

	if (MetroSystem::availablePlans.size() == 0)
	{
		cout << "there is no plans \n";
		return;
	}
	int counter = 0;
	// first i will display all the plans in our system and its details to choose one of them 
	for (auto it = MetroSystem::availablePlans.begin(); it != MetroSystem::availablePlans.end(); it++) {
		counter++;
		cout << "Plan number " << counter << " : ................................... \n";
		cout << "Its name is : " << it->first << "\n";
		cout << "the available periods is : \n";
		//cout << "the " << counter << " \n";
		vector<Period>temp = it->second.getPeriods();

		for (auto iter : temp)
		{
			cout << "the name of period is " << iter.name << "\n";
			cout << "the trips is " << iter.getTotalTrips() << "\n";
			vector<Stage>temp2 = iter.getStages();
			for (auto stage : temp2)
			{
				cout << "name: " << stage.name << "\n";
				cout << "price: " << stage.getprice() << "\n";

			}
		}

	}

}


// tested done  
void SubscriptionPlan::add_Subscription_Plan() {

	// i think we will not need to make an object here because he will add this things in this onjevt which will call this methode
	while (true) {
		//do not forget to make the logical checks for this part 

		cout << "Enter the name of the plan you wan to add. \n";
		string name;
		cin >> name;
		cin.ignore();
		if ((MetroSystem::availablePlans.find(name)) != MetroSystem::availablePlans.end()) {// it means the name is existed 
			cout << "Invalid name please enter again \n";
			continue;
		}
		cout << "how many periods will be inside this plan \n";
		int n;
		while (true) {
			cin >> n;
			if (cin.fail()) {
				cout << "Invalid input. Please enter a valid number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {

				break;
			}
		}

		cin.ignore();

		for (int i = 0; i < n; i++) {
			Period t;
			cout << "----* Period: " << i + 1 << "  *----\n";
			cout << "Enter period of Subscription Plan (number of days, months, or years like '2 years'):\n";
			string s;
			while (true) {
				getline(cin, s);
				auto spacePos = s.find(' ');
				if (spacePos != string::npos) {
					int num = stoi(s.substr(0, spacePos));
					string unit = s.substr(spacePos + 1);
					if ((num > 0) && ((unit == "day" || unit == "days") ||
						(unit == "month" || unit == "months") ||
						(unit == "year" || unit == "years"))) {
						t.name = s;
						break;
					}
					else {
						cout << "The value is invalid, try again \n ";
					}
				}
				else {
					cout << "The input is invalid, try again \n ";
				}
			}

			cout << "enter the number of trips \n";
			int trips;
			cin >> trips;
			cin.ignore();
			t.setTotalTrips(trips);


			cout << "Enter prices of 4 stages:\n";
			for (int j = 1; j <= 4; j++) {
				Stage s;
				s.name = j;
				cout << "Enter price of stage " << s.name << ": ";
				int pr;
				cin >> pr;
				cout << " \n";
				while (true) {
					if (j != 1) {
						int temp = t.getStages().back().getprice();
						
						if (pr <= temp)
						{
							cout << "The value is invalid, enter a price greater than the previous stage price, try again \n ";
							cin >> pr;
							cin.ignore();
							continue;
						}
					}
					s.setprice(pr);
					t.addStage(s);
						break;
				}


			}
			addPeriod(t);


			cout << "done \n";
			MetroSystem::availablePlans[name] = *this;
			



		}
		break;
	}
}

//tested done 
void SubscriptionPlan::edit_Subscription_Plan() {

	        display_All_Plans();
	        cout << "Enter the name of the subscription plan you want to edit it. \n";
			string name;
			cin >> name;
			bool flag = false;
			for (auto it = MetroSystem::availablePlans.begin(); it != MetroSystem::availablePlans.end(); it++) {
				if (it->first == name)
				{
					flag = true;
				}
			}
			if (!flag)// it means the name not found
			{
				while (true) {
					cout << "This name isnot found do you want to try again? just write ( y , n ) \n";
					char answer;
					cin >> answer;
					if (answer == 'y' || answer == 'Y')
					{
						edit_Subscription_Plan();
					}
					else if (answer == 'n' || answer == 'N')
						return;
					else
					{
						cout << "Invalid choice please write y or n only . \n";
						continue;
					}
				}
			}
			else {//it means the name of the plan the admin enteres is existed in our system 
				while (true)
				{
					// we can here display the dtails of the choosen plan 

					cout << "Enter the number of the choice you want. \n";
					cout << " 1. If you want to edit period . \n";
					cout << " 2. If you want to edit name of plan  . \n";
					cout << "3 . to exist \n";
					char answer;
					cin >> answer;
					if (answer == '1')
					{
						int i = 0;
						SubscriptionPlan &tempplan= MetroSystem::availablePlans[name];
						vector<Period>&v = tempplan.getPeriods();
						
						for (auto &iter : v)
						{

							cout << "----* Period: " << ++i << "  *----\n";
							cout << "the name of period is " << iter.name << "\n";
							cout << "the trips is " << iter.getTotalTrips() << "\n";
							vector<Stage>&temp2 = iter.getStages();
							for (auto &stage : temp2)
							{
								cout << "name: " << stage.name << "\n";
								cout << "price: " << stage.getprice() << "\n";

							}
							cout << "========================================================= \n";
							
						}

						int cc;
						while (true)
						{
							cout << "enter the number of the period you want \n ";
							cin >> cc;
							if (cc >= 1 && cc <= v.size())
								break;
							else {
								cout << "this number doesnot exist please try again \n";
								continue;
							}
						}
						cc--;
						while (true)
						{
							int loc;
							cout << "enter 1 to edit period name \n ";
							cout << "enter 2 to edit total trips  \n ";
							cout << "enter 3 to edit stages price  \n ";
							cin >> loc;
							if (loc == 1)
							{
								cout << "enter the new name \n";
								string s;
								while (true) {
									getline(cin, s);
									auto spacePos = s.find(' ');
									if (spacePos != string::npos) {
										int num = stoi(s.substr(0, spacePos));
										string unit = s.substr(spacePos + 1);
										if ((num > 0) && ((unit == "day" || unit == "days") ||
											(unit == "month" || unit == "months") ||
											(unit == "year" || unit == "years"))) {
											v[cc].name = s;
											break;
										}
										else {
											cout << "The value is invalid, try again \n ";
										}
									}
									else {
										cout << "The input is invalid, try again \n ";
									}
								}

							} //tested done
							else if (loc == 2)
							{
								//logical check
								cout << "enter the new total trips \n";
								int trips;
								cin >> trips;
								v[cc].setTotalTrips(trips);
							}
							else if (loc == 3)
							{
								cout << "Enter prices of 4 stages:\n";
								vector<Stage>&vtemp = v[cc].getStages();
								int j = 0;
									
									for (auto &s : vtemp)
									{
										++j;
										cout << "Enter price of stage " << s.name << ": ";
										int pr;
										cin >> pr;
										cout << " \n";
										while (true) {
											if (j != 1) {
												int temp = v[cc].getStages().back().getprice();

												if (pr <= temp)
												{
													cout << "The value is invalid, enter a price greater than the previous stage price, try again \n ";
													cin >> pr;
													cin.ignore();
													continue;
												}
											}
											s.setprice(pr);
											break;
										}
									}
									
									
									


								
							}
							else {
								cout << "this number doesnot exist please try again \n";
								continue;
							}
							break;
						}

					}
					else if (answer == '2') { //tested done
						while (true)
						{
							cout << "enter the new name \n";
							string newone;
							cin >> newone;
							auto ff = MetroSystem::availablePlans.find(newone);
							if (ff == MetroSystem::availablePlans.end()) // it means doesnot exist
							{	 
								SubscriptionPlan tt = MetroSystem::availablePlans[name];
								MetroSystem::availablePlans.erase(name);
								MetroSystem::availablePlans[newone] = tt;
								break;

							}
							else {
								if (newone == name)
								{
									break;
								}
								else
								{
									cout << "this name existed \n";
									continue;

								}
							}
						}
					}
					else if (answer == '3')return;
					else {
						cout << "Invalid choice please try again. \n ";
						continue;
					}
				}
				cout << "Do you want to make another update ? just write ( y , n ). \n ";
				char choice;
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					edit_Subscription_Plan();
				}
				else if(choice == 'n' || choice == 'N')
					return;   // here we can put function that having the all admin services so we can call it here instead
			}
}


//tested done
void SubscriptionPlan::delete_Subscription_Plan() {
	display_All_Plans();
	if (MetroSystem::availablePlans.size() == 0)
	{
		cout << "there is no plans to delete them \n";
		return;
	}
	// first taking the name pf the plan and check if it existed in our plans or no 
	cout << "Enter the name of the subscription plan you want to remove it. \n";
	string name;
	cin >> name;
	bool flag = false;
	for (auto it = MetroSystem::availablePlans.begin(); it != MetroSystem::availablePlans.end(); it++) {
		if (it->first == name)
		{
			flag = true;
			// we can after finding the name here to store the iterator for this name to decrease the time 
		}
	}
	if (!flag)// it means the name not found
	{
		while (true) {
			cout << "This name isnot found do you want to try again? just write ( y , n ) \n";
			char answer;
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				delete_Subscription_Plan();
			}
			else if (answer == 'n' || answer == 'N')
				return;  // the same thing i can make him retrun to the admin services function list 
			else
			{
				cout << "Invalid choice please write y or n only . \n";
				continue;
			}
		}
	}
	else { //it means the name is existed so now we will remove it from the plans data structure 
		auto iter= MetroSystem::availablePlans.find(name);
	    // i will not check if the iter equals to the end because i make this check before
		MetroSystem::availablePlans.erase(iter);
		cout << "Congratulations the plan removed  !! ^^";
	}


}


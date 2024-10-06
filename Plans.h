#include<string>
#include <iostream>
#include<vector>
#include <utility> // Needed for std::pair

using namespace std;


class Plans
{

public:
	string name;
	vector<pair<int, int>>amount_ForEachStage;
	bool fixed; //if it fixed or flexable like the cash wallet
	int number_OfTrips;

	//SubscriptionPlan();
	void addSubscriptionPlan();
	void editSubscriptionPlan();
	void deleteSubscriptionPlan();



};


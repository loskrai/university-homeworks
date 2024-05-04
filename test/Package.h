#pragma once
#include"headfile.h"

class Package;
class TwoDayPackage;
class OvernightPackage;

class Package {
public:
	Package(const string& sender = "00", const string& receiver = "00", const string& adress = "00",
		const string& city = "00", const string& province = "00",const int &postcode=0000,
		const unsigned long&weight=0,const unsigned long&costperans=0) :
		sender(sender), receiver(receiver), adress(adress),city(city),province(province),
		postalcode(postcode),weight(weight),costperans(costperans){}
	double calculate_Cost() {
		return weight * costperans;
	}
private:
protected:
	string sender;
	string receiver;
	string adress;
	string city;
	string province;
	int postalcode;
	unsigned long weight;
	unsigned long costperans;
};

class TwoDayPackage :public Package {
public:
	TwoDayPackage(const string& sender = "00", const string& receiver = "00", const string& adress = "00",
		const string& city = "00", const string& province = "00", const int& postcode = 0000, const unsigned long& weight = 0, 
		const unsigned long& costperans = 0, const unsigned long& flatpostagecharge = 0):
		Package(sender,receiver,adress,city,province,postcode,weight,costperans),flatpostagecharge(flatpostagecharge){}
	double calculate_Cost() {
		return this->Package::calculate_Cost() + flatpostagecharge;
	}
private:
	unsigned long flatpostagecharge;
protected:
};

class OvernightPackage :public Package {
public:
	OvernightPackage(const string& sender = "00", const string& receiver = "00", const string& adress = "00",
		const string& city = "00", const string& province = "00", const int& postcode = 0000, const unsigned long& weight = 0,
		const unsigned long& costperans = 0, const unsigned long& extraper = 0):
		Package(sender, receiver, adress, city, province, postcode, weight, costperans),extracost(extraper){}
	double calculate_Cost() {
		return weight * (costperans + extracost);
	}
private:
	unsigned long extracost;
};



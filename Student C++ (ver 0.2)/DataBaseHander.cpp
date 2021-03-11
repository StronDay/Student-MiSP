#include "DataBaseHander.h"
#include <sstream>

unsigned int DataBaseHander::CostReaderInstitute(const string& city, const string& institute) const
{
	unsigned int cost = 0;

	string line;
	string fCity;
	string fInstitute;
	string lineCost;

	fstream fileReader;
	fileReader.open("Institute.csv");
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Institute.csv)" << ")" << endl;
		exit(0);
	}
	else {

		//getline(fileReader, line);
		while (getline(fileReader, line)) {
			
			stringstream lineStream(line);

			getline(lineStream, fCity, ',');
			getline(lineStream, fInstitute, ',');
			getline(lineStream, lineCost, ',');

			if (fCity == city && fInstitute == institute) {

				return stoi(lineCost);
			}
		}
	}

	fileReader.close();

	return 0;
}

unsigned int DataBaseHander::CostReaderTransport(const string& city, const string& district, const string& institute) const
{
	unsigned int cost = 0;

	string line;
	string fCity;
	string fInstitute;
	string fDistrict;
	string lineCost;

	fstream fileReader;
	fileReader.open("Transport.csv");
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Transport.csv)" << ")" << endl;
		exit(0);
	}
	else {

		//getline(fileReader, line);
		while (getline(fileReader, line)) {

			stringstream lineStream(line);

			getline(lineStream, fCity, ',');
			getline(lineStream, fDistrict, ',');
			getline(lineStream, fInstitute, ',');
			getline(lineStream, lineCost, ',');

			if (fCity == city && fInstitute == institute && fDistrict == district) {

				return stoi(lineCost);
			}
		}
	}

	fileReader.close();

	return 0;
}

unsigned int DataBaseHander::CostReaderCosts(const string& city, const string& age) const
{
	string line;
	string fCity;
	string fAge;
	string lineCostFood;
	string lineCostOther;

	fstream fileReader;
	fileReader.open("Costs.csv");
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Costs.csv)" << ")" << endl;
		exit(0);
	}
	else {

		//getline(fileReader, line);
		while (getline(fileReader, line)) {

			stringstream lineStream(line);

			getline(lineStream, fCity, ',');
			getline(lineStream, fAge, ',');
			getline(lineStream, lineCostFood, ',');
			getline(lineStream, lineCostOther, ',');

			if (fCity == city && fAge == age) {

				return stoi(lineCostFood) + stoi(lineCostOther);
			}
		}
	}

	fileReader.close();

	return 0;
}

struct Recreation {

	string city;
	string adress;
	string name;
	string cost;
};

unsigned int DataBaseHander::CostReaderCaffeAndCinema
(
	const string& city, 
	const string& adress, 
	const string& caffe, 
	const string& cinema
)	const
{
	string line;
	
	Recreation fCinema;
	Recreation fCaffe;

	fstream fileReader;
	fileReader.open("Caffe-and-cinema.csv");
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Caffe-and-cinema.csv)" << ")" << endl;
		exit(0);
	}
	else {

		//getline(fileReader, line);
		while (getline(fileReader, line)) {

			stringstream lineStream(line);

			getline(lineStream, fCaffe.city, ',');
			getline(lineStream, fCaffe.adress, ',');
			getline(lineStream, fCaffe.name, ',');
			getline(lineStream, fCaffe.cost, ',');
			getline(lineStream, fCinema.name, ',');
			getline(lineStream, fCinema.cost, ',');

			if (fCaffe.city == city && fCaffe.adress == adress && fCaffe.name == caffe && fCinema.name == cinema) {

				return stoi(fCaffe.cost) + stoi(fCinema.cost);
			}
		}
	}

	fileReader.close();

	return 0;
}
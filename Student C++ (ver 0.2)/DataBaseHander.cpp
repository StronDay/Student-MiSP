#include "DataBaseHander.h"
#include <sstream>

unsigned int DataBaseHander::CostReaderInstitute(const string& city, const string& institute, const string& path)
{
	fstream fileReader;
	fileReader.open(path);
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Institute.csv)" << ")" << endl;
		return 0;
	}

	unsigned int cost = 0;

	string line;
	string fCity;
	string fInstitute;
	string lineCost;

	while (getline(fileReader, line)) {

		stringstream lineStream(line);

		getline(lineStream, fCity, ',');
		getline(lineStream, fInstitute, ',');
		getline(lineStream, lineCost, ',');

		if (fCity == city && fInstitute == institute) {

			return stoi(lineCost);
		}
	}

	return 0;
}

unsigned int DataBaseHander::CostReaderTransport(const string& city, const string& district, const string& institute, const string& path)
{
	fstream fileReader;
	fileReader.open(path);
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Transport.csv)" << ")" << endl;
		return 0;
	}

	string line;
	string fCity;
	string fInstitute;
	string fDistrict;
	string lineCost;

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

	return 0;
}

unsigned int DataBaseHander::CostReaderCosts(const string& city, const string& age, const string& path)
{
	fstream fileReader;
	fileReader.open(path);
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Costs.csv)" << ")" << endl;
		return 0;
	}

	string line;
	string fCity;
	string fAge;
	string lineCostFood;
	string lineCostOther;
	
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

	return 0;
}

unsigned int DataBaseHander::CostReaderCaffeAndCinema
(
	const string& city,
	const string& adress,
	const string& caffe,
	const string& cinema,
	const string& path
)
{
	fstream fileReader;
	fileReader.open(path);
	if (!fileReader.is_open()) {

		cout << "FILE OPENING ERROR (Caffe-and-cinema.csv)" << ")" << endl;
		return 0;
	}

	string line;

	Recreation fCinema;
	Recreation fCaffe;
	
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
	
	return 0;
}
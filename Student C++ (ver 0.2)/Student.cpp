#include "Student.h"

Student::Student
(
	
	const string& age,
	const string& name,
	const string& city,
	const string& institute,
	const string& district,
	const string& adress,
	const string& caffe,
	const string& cinema,
	unsigned int numberWorkDay,
	unsigned int numberNonWorkDay
)
{

	_numberNonWorkDay = numberNonWorkDay;
	_numberWorkDay = numberWorkDay;
	_institute = institute;
	_district = district;
	_adress = adress;
	_cinema = cinema;
	_caffe = caffe;
	_city = city;
	_age = age;
}

unsigned int Student::CounterMonthCost(unsigned int numberWorkDay, unsigned int numberNonWorkDay)
{
	unsigned int costCaffeAndCinema;
	unsigned int costTransport;
	unsigned int costInstitute;
	unsigned int costCosts;
	unsigned int cost = 0;
	
	DataBaseHander data;

	costCaffeAndCinema = data.CostReaderCaffeAndCinema(_city, _adress, _caffe, _cinema);
	costTransport = data.CostReaderTransport(_city, _district, _institute);
	costInstitute = data.CostReaderInstitute(_city, _institute);
	costCosts = data.CostReaderCosts(_city, _age);

	if (costTransport != NULL && costInstitute != NULL && costCosts != NULL && costCaffeAndCinema != NULL) {

		cost = (costTransport * 2 + costInstitute) * numberWorkDay + (costCaffeAndCinema) * numberNonWorkDay;
		cost = cost + costCosts;
	}
	else {

		/*cout << "Entered data incorect: " << endl;

		if (costTransport == NULL) {

			cout << "check positions: city, district, institute" << endl;
		}

		if (costInstitute == NULL) {

			cout << "check positions: city, institute" << endl;
		}

		if (costCosts == NULL) {

			cout << "check positions: city, age" << endl;
		}

		if (costCaffeAndCinema == NULL) {

			cout << "check positions: city, adress, caffe, cinema" << endl;
		}*/

		return cost;
	}

	return cost;
}

//const string& Student::GetInstitute() { return _institute; }
//
//const string& Student::GetDistrict() { return _district; }
//
//const string& Student::GetAdress() { return _adress; }
//
//const string& Student::GetCinema() { return _cinema; }
//
//const string& Student::GetCaffe() { return _caffe; }
//
//const string& Student::GetCity() { return _city; }
//
//const string& Student::GetAge() { return _age; }
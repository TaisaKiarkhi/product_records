#include <iostream>
#include <vector>
#include <format>
#include <cctype>

using namespace std;

int main() {

	vector <unsigned int> record_id{};
	vector <unsigned int> quantity{};
	vector <double> price_unit{};

	unsigned int ID{};
	unsigned int amount{};
	double price{};

	cout << "This program will calculate the cost and total cost of all products."
		<< "Enter the record ID, quantity and the price per unit. "
		<<endl;
	
	char y_n{};

	do {
		cout << "record ID: ";
		cin >> ID;
		cout << "Quantity: ";
		cin >> amount;
		cout << "Price per unit: ";
		cin >> price;

		record_id.push_back(ID);
		quantity.push_back(amount);
		price_unit.push_back(price);

		cout << "Do you want to enter more records? (y/n): ";
		cin >> y_n;
		

	} while (tolower(y_n)=='y');

	double total_cost{};

	cout << "_____________________________________________________________________"<<endl;
	cout << format("{:<15} {:<15} {:<15} {:<15} {:<15}", "Product", "Quantity", "Unit Price", "Cost", "Total")
		<<endl;
	cout << "_____________________________________________________________________" << endl;

	for (size_t i{}; i < size(record_id); i++) {
		double cost = static_cast<double>(quantity.at(i) * price_unit.at(i));
	
		cout<< format("{:<15} {:<15} {:<15.2f} {:<15.2f}", record_id.at(i), quantity.at(i), price_unit.at(i), cost);
		cout << endl;
		total_cost += cost;
	}

	cout << "_____________________________________________________________________" << endl;
	cout << format("{:>69.2f}", total_cost);

	return 0;
}

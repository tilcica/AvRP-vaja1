#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string romanSort(string inputText) {
	vector<int> numbers;
	string output = "";
	istringstream iss(inputText);
	int num;
	while (iss >> num) {
		numbers.push_back(num);
	}
	int minNum = *min_element(numbers.begin(), numbers.end());
	int maxNum = *max_element(numbers.begin(), numbers.end());
	vector<int> B(maxNum-minNum + 1, 0);
	for (int i : numbers) {
		i -= minNum;
		B[i]++;
	}
	int counter = 0;
	for (int i = 0; i < B.size(); i++) {
		if (B[i] != 0) {
			for (int j = 0; j < B[i]; j++) {
				output += to_string(i + minNum) + " ";
			}
		}
	}
	return(output);
}
string countingSort(string inputText) {
	vector<int> numbers;
	string output = "";
	istringstream iss(inputText);
	int num;
	while (iss >> num) {
		numbers.push_back(num);
	}
	int minNum = *min_element(numbers.begin(), numbers.end());
	int maxNum = *max_element(numbers.begin(), numbers.end());
	vector<int> C(maxNum - minNum + 1, 0);
	vector<int> B(numbers.size(), 0);
	for (int i = 0; i < numbers.size(); i++) {
		numbers[i] -= minNum;
		C[numbers[i]]++;
	}
	for (int i = 1; i < C.size(); i++) {
		C[i] = C[i - 1] + C[i];
	}

	for (int i = numbers.size()-1; i >= 0; i--) {
		B[C[numbers[i]] - 1] = numbers[i];
		C[numbers[i]] = C[numbers[i]] - 1;
	}

	for (int i : B) {
		output += to_string(i + minNum) + " ";
	}
	return(output);
}

int main(int argc, char* argv[]) {
	string sortType, inputFile;
	if (argc >= 3) {
		sortType = argv[1];
		inputFile = argv[2];
	}
	else {
		sortType = "0";
		inputFile = "C:/Users/Tilen/Desktop/sula naloge/4 semester/algoritmi v racunalniski praksi/vaja 1/log.txt";
	}


	fstream file;
	string input = "";
	string output = "";
	try {
		file.open(inputFile, ios::in);
		getline(file, input);
		file.close();
	}
	catch (...) {
		cout << "Error when opening input file" << endl;
		exit(1);
	}

	if (sortType == "0") {
		output = countingSort(input);
	}
	else if (sortType == "1") {
		output = romanSort(input);
	}
	else {
		cout << "invalid sort type. valid ones are 0 (Counting) and 1 (Roman)" << endl;
		exit(1);
	}

	try {
		file.open("C:/Users/Tilen/Desktop/sula naloge/4 semester/algoritmi v racunalniski praksi/vaja 1/output.txt", ios::out);
		file << output;
		file.close();
	}
	catch (...) {
		cout << "Error when opening output file" << endl;
		exit(1);
	}
}
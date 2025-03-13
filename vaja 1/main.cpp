#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string romanSort(string inputText) {
	return(inputText);
}
string countingSort(string inputText) {
	return(inputText);
}

int main(int argc, char* argv[]) {
	string sortType = argv[1];
	string inputFile = argv[2];

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
		output = "Counting sort: \n" + countingSort(input);
	}
	else if (sortType == "1") {
		output = "Roman sort: \n" + romanSort(input);
	}
	else {
		cout << "invalid sort type. valid ones are 0 (Counting) and 1 (Roman)" << endl;
		exit(1);
	}

	try {
		file.open("output.txt", ios::out);
		file << output;
		file.close();
	}
	catch (...) {
		cout << "Error when opening output file" << endl;
		exit(1);
	}
}
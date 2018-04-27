#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int readFromFile(vector<string>&, string);
void displayArray(vector<string>, int);
void alphaSort(vector<string>&, int);
void swap(string&, string&);
void saveFile(vector<string>, int, string);


int main() {
	//Declare variables
	string fileName;
	vector<string>names(1);
	int nameQty;

	//Prompt for file name
	cout << "Please enter the name of the file to read names from: " << endl;
	cin >> fileName;

	//Call function to open file and read names into a vector array. 
	//Function will return the number of names in file
	nameQty = readFromFile(names, fileName);

	//Display unsorted names
	cout << "Here are the unsorted names: " << endl;
	cout << "----------------------------" << endl;
	displayArray(names, nameQty);
	cout << endl;

	//Sort names into alphabetical order
	alphaSort(names, nameQty);

	//Display sorted names
	cout << "Here are the sorted names: " << endl;
	cout << "--------------------------" << endl;
	displayArray(names, nameQty);
	cout << endl;

	//Prompt for output file name and save file
	string outputFilename;
	cout << "Please enter the name of the file to save sorted names to: " << endl;
	cin >> outputFilename;
	saveFile(names, nameQty, outputFilename);

	system("pause");
	return 0;
}
/*
* Function to read a list from a text file into an array.
* The array starts at size 1, then increments by 1 for each subsequent iteration
* The array then deletes the final element when there is nothing more to read
* (since the last element will be uninitialized)
*/
int readFromFile(vector<string>& array, string fileName) {
	ifstream inputFile;
	inputFile.open(fileName);

	if (!inputFile) {
		cout << "Invalid file name. Please restart program and try again."
			<< endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	else {
		int index = 0;
		getline(inputFile, array[0]); //Fill first element
		while (inputFile) { //Append subsequent names
			string newName;
			getline(inputFile, newName);
			array.push_back(newName);
			index++;
		}
		
		return (index); //Return number of names read to main()
		}
}

//Function to display list of items in array
void displayArray(vector<string> array, int quantity) {
	for (int i = 0; i < quantity; i++)
	cout << array[i] << endl;
}

//Selection sort function puts array elements in alphabetical order
void alphaSort(vector<string>& names, int qty) {
	for (int j = 0; j < qty - 1; j++) {

		for (int i = j + 1; i < qty; i++) {
			if (names[j] > names[i]) {
				swap(names[j], names[i]);
			}
		}
	}

}

//Function to swap elements a and b in array
void swap(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
}

//Function to write names to a file
void saveFile(vector<string> names, int qty, string fileName) {
	
	//Open output stream
	ofstream outputFile;
	outputFile.open(fileName);

	//Write names to file
	for (int i = 0; i < qty; i++) {
		outputFile << names[i] << endl;
	}

	//Report success and close file
	cout << "File successfully created" << endl;
	outputFile.close();
}
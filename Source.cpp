#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define size 100

using namespace std;

// BASE Functions

void addPatient();

void modify();
void menu();


void writeFile();
void readFile();

void deletePatient();

void writeDeletedFile();
void readDeletedFile();

void totalCharge();


//-----------
//USED IN Functions

int emptyIndex();           // function to check if there is an empty index or not
bool searchIndex(int idNum);			  // function to check if the index entered exist before or not
int indexLocation(int ID);

//-----------
// variables needed 

int idNumber[size];
string firstName[size];
string lastName[size];
int phoneNumber[size];
string Nationality[size];

string first, last, nationality;
int phone;


int d_idNumber[size];
string d_firstName[size];
string d_lastName[size];
int d_phoneNumber[size];
string d_Nationality[size];

char ch;

int counter = 0;

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


// Main Function :
int main() {
	int choose = 0;
	do {
		system("cls");
		cout << " \n\n\tPLEASE SELECT FRON THE MENU .. ";
		cout << "\n\n\t choose one of the below options : ";
		cout << "\n\n ------------------------------------ \n";

		cout << " 1. add a new patient ";
		cout << "\n 2. modify patient record";
		cout << "\n 3. delete patient record";
		cout << "\n 4. list of all patients";
		cout << "\n 5. total cost";
		cout << "\n 6. list of all deleted patients";
		cout << "\n 7. Exit\n";

		cin >> choose;
		
		//readFile();
		system("cls");

		switch (choose) {
		case 1:
			readFile();
			addPatient();
			writeFile();
			break;
		
		case 2:
			readFile();
			modify();
			writeFile();
			break;

		case 3:
			deletePatient();
			writeFile();
			writeDeletedFile();
			break;

		case 4:
			readFile();
			for (int i = 0; i < counter; i++) {
				cout << idNumber[i] << "\t" << firstName[i] << "\t" << lastName[i] << "\t" << phoneNumber[i] << "\t" << Nationality[i] << endl;
			}
			break;

		case 5:
			readFile();
			totalCharge();
			break;

		case 6: 
			readDeletedFile();
			for (int i = 0; i < counter; i++) {
				cout << d_idNumber[i] << "\t" << d_firstName[i] << "\t" << d_lastName[i] << "\t" << d_phoneNumber[i] << "\t" << d_Nationality[i] << endl;
			}
			break;
			
		case 7:
			cout << " \n\n\n\n\n\t\t\t\t   GOOD BYE ... ";
			break;

		default:
			cout << "wrong choice.. please try again";
			break;
		}

		cin.ignore();
		cin.get();

	}while (choose != 7);

	system("pause");
	return 0;
}



// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

int emptyIndex() {
	for (int i = 0; i < size; i++) {
		if (idNumber[i] == 0)
			return i;
	}
	return -1;
}

// -------------------------------------

bool searchIndex(int idNum) {
	for (int i = 0; i < size; i++) {
		if (idNumber[i] == idNum)
			return true;
	}
	return false;
}

// -------------------------------------

int indexLocation(int ID) {
	for (int i = 0; i < size; i++) {
		if (idNumber[i] == ID)
			return i;
	}
	return -1;
}

// -------------------------------------

int d_emptyIndex() {
	for (int i = 0; i < size; i++) {
		if (d_idNumber[i] == 0)
			return i;
	}
	return -1;
}


// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void addPatient() {
	string x;
	int id_add; 

	do {
		int A = emptyIndex();
		if (A == -1) {
			cout << "\n\t Sorry, There is no available space for a new patient \n";
			return;
		}

		bool h = 0;
		do {
			system("cls");
			cout << "\n\tPlease Enter The ID Number: ";
			cin >> id_add;

			if (searchIndex(id_add)) {
				cout << "\n\tTHE PATIENT NUMBER IS EXIST, TRY AGAIN:  ";
				h = 1;
			}
			else
				h = 0;
		} while (h);

		idNumber[A] = id_add;

		cout << "\n\tPlease Enter The Patient's First Name : ";
		cin >> first;
		cout << "\n\tPlease Enter The Patient's Last Name : ";
		cin >> last;
		cout << "\n\tPlease Enter The Patient's Phone : ";
		cin >> phone;
		cout << "\n\tPlease Enter The Patient's Nationality : ";
		cin >> nationality;

		firstName[A] = first;
		lastName[A] = last;
		phoneNumber[A] = phone;
		Nationality[A] = nationality;

		cout << "\n\n TO ADD MORE ENTER (Y) .. OR TO EXIT ENTER (N)";
		cin >> x;
	} while (x != "n" && x != "N");

	cout << "\n\tTHE INFORMATION IS SUCCESSFULLY CREATED.. ";
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void menu() {
	cout << "\n\n\tTO UPDATE,  CHOOSE FROM THE FOLLOWING : ";
	cout << "\n\n\t 1. UPDATE THE ID NUMBER : ";
	cout << "\n\n\t 2. UPDATE THE FIRST NAME : ";
	cout << "\n\n\t 3. UPDATE THE LAST NAME : ";
	cout << "\n\n\t 4. UPDATE THE PHONE NUMBER : ";
	cout << "\n\n\t 5. UPDATE THE NATIONALITY : ";

	cout << "\n\n\n\t  PLEASR ENTER YOUR CHOICE .. :\t ";
}

//---------------------------

void modify() {
	system("cls");

	int id_modify;
	cout << "\n PLEASE ENTER YOUR ID : \t";
	cin >> id_modify;

	if (!searchIndex(id_modify)) {
		cout << "\n\t\t ID NUMBER IS NOT FOUND .. \n";
		return;
	}

	int M = indexLocation(id_modify);
	idNumber[M] = id_modify;

	do {
		system("cls");
		menu();
		int x;
		cin >> x;
		switch (x) {
		case 1:
			cout << "\n\n\tPLEASE ENTER THE NEW ID :\t";
			cin >> id_modify;
			idNumber[M] = id_modify;
			cout << "\n\n DONE .. THANK YOU";
			break;

		case 2:
			cout << "\n\n\tPLEASE ENTER THE FIRST NAME : \t";
			cin >> first;
			firstName[M] = first;
			cout << "\n\n DONE .. THANK YOU";
			break;

		case 3:
			cout << "\n\n\tPLEASE ENTER THE LAST NAME : \t";
			cin >> last;
			lastName[M] = last;
			cout << "\n\n DONE .. THANK YOU";
			break;

		case 4:
			cout << "\n\n\tPLEASE ENTER PHONE NUMBER : \t";
			cin >> phone;
			phoneNumber[M] = phone;
			cout << "\n\n DONE .. THANK YOU";
			break;

		case 5:
			cout << "\n\n\tPLEASE ENTER THE NATIONALITY : \t";
			cin >> nationality;
			Nationality[M] = nationality;
			cout << "\n\n DONE .. THANK YOU";
			break;

		default:
			cout << "\n\n INVALID ENTERED.. TRY AGAIN ";
			break;
		}
		
		cout << "\n\n WOULD YOU LIKE TO CHANGE ANOTHER FEILD ? (Y/N) :  ";
		cin >> ch;
	} while (ch != 'n' && ch != 'N');

	cout << "\n\n THE PATIENT FILE HAS BEEN UPDATED.. ";
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void writeFile() {
	ofstream write;
	write.open("patients.txt", ios::binary);
	for (int i = 0; i < size; i++) {
		if (idNumber[i] == 0)
			break;
		write << "\n" << idNumber[i] << '\t' << firstName[i] << '\t' << lastName[i] << '\t' << phoneNumber[i] << '\t' << Nationality[i] << endl;
	}
	write.close();

}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void readFile() {
	counter = 0;
	ifstream read;
	read.open("patients.txt");
	while (!read.eof()) {
		read >> idNumber[counter] >> firstName[counter] >> lastName[counter] >> phoneNumber[counter] >> Nationality[counter];
		counter++;
	}
	read.close();
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void deletePatient() {
	int id_delete;
	cout << "\n\t PLEASE ENTER THE PATIENT ID :  ";
	cin >> id_delete;
	if (!searchIndex(id_delete)) {
		cout << "\n\t PATIENT ID CANNOT BE FOUND.. \n";
		return;
	}
	int D = indexLocation(id_delete);
	idNumber[D] = id_delete;

	int dd = d_emptyIndex();
	if (dd == -1) {
		cout << "DELETE LIST IS FULL ..";
		return;
	}

	d_idNumber[dd] = idNumber[D];
	d_firstName[dd] = firstName[D];
	d_lastName[dd] = lastName[D];
	d_phoneNumber[dd] = phoneNumber[D];
	d_Nationality[dd] = Nationality[D];



	if (idNumber[D + 1] == 0) {
		idNumber[D] = 0;
		cout << "\n\n\t THE PATIENT HAS BEEN DELETED.. ";
		return;
	}

	for (int i = D; i < size - 1; i++) {
		if (idNumber[D + 1] == 0) {
			idNumber[D] = 0;
			cout << "\n\n\t THE PATIENT HAS BEEN DELETED.. ";
			i = size;

		}
		else
			idNumber[D] = idNumber[D + 1];
	}

	//writeDeletedFile();
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void writeDeletedFile() {
	ofstream d_write;
	d_write.open("deletedPatients.txt", ios::binary);
	for (int i = 0; i < size; i++) {
		if (d_idNumber[i] == 0)
			break;
		d_write << "\n" << d_idNumber[i] << '\t' << d_firstName[i] << '\t' << d_lastName[i] << '\t' << d_phoneNumber[i] << '\t' << d_Nationality[i] << endl;
	}
	d_write.close();

}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void readDeletedFile() {
	counter = 0;
	ifstream read_d;
	read_d.open("deletedPatients.txt", ios::binary);
	while (read_d) {
		read_d >> d_idNumber[counter] >> d_firstName[counter] >> d_lastName[counter] >> d_phoneNumber[counter] >> d_Nationality[counter];
		counter++;
	}
	read_d.close();
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void totalCharge() {
	system("cls");
	int id_pay;
	cout << "\n\nPLEASE ENTER THE ID NUMBER :  ";
	cin >> id_pay;

	if (!searchIndex(id_pay)) {
		cout << "\n\t\t ID NUMBER CANNOT BE FOUND..\n";
		return;
	}

	int C = indexLocation(id_pay);
	idNumber[C] = id_pay;

	int x, z;
	float surgery_ch = 0, stay_ch = 0, med_ch = 0, total = 0;

	do {
		system("cls");
		cout << "\n WHAT KIND OF TREATMENT HAD THE PATIENT HAD ? ";
		cout << "\n\n\t 1. Surgery";
		cout << "\n\n\t 2. Accomodation";
		cout << "\n\n\t 3. Medication\n\n";

		cin >> x;
		
		switch (x) {
		case 1:
			cout << "\n PLEASE ENTER SURGERY CHARGE : \n\n";
			cout << "\t 1. Surgery 1 \n\n";
			cout << "\t 2. Surgery 2 \n\n";
			cout << "\t 3. Surgery 3 \n\n";

			cin >> z;
			if (z == 1)
				surgery_ch = 100;
			else if (z == 2)
				surgery_ch = 200;
			else if (z == 3)
				surgery_ch = 300;
			else
				surgery_ch = 0;
			break;

		case 2:
			cout << "\n\n PLEASE ENTER HOW MANY DAYS THE PATIENT STAYED IN THE HOSPITAL : \n";
			cin >> z;
			stay_ch = z * 200;
			break;

		case 3:
			cout << "\n\n PLEASE ENTER MEDICINE THE PATIENT HAD : ";
			cout << "\n\n\t 1. med 1";
			cout << "\n\n\t 2. med 2";
			cout << "\n\n\t 3. med 3\n\n";
			cin >> z;
			if (z == 1)
				med_ch = 100;
			else if (z == 2)
				med_ch = 200;
			else if (z == 3)
				med_ch = 300;
			else
				med_ch = 0;
			break;
		}
		cout << "\n\n WOULD YOU LIKE ANOTHER TREATMENT ? (Y/N):  ";
		cin >> ch;
	} while (ch != 'N' && ch != 'n');
	total = surgery_ch + stay_ch + med_ch;
	
	cout << "idNumber : " << "\t" << idNumber[C] << "\n";
	cout << "Total : " << "\t" << total << "\n";



}
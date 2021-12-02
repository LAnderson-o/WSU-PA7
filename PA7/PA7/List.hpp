#include "Node.hpp"

template <class T>
class List {
public:
	List();
	
	void importRecords();
	void display();
	void markAbsences();
	void generateReports(int threshhold);
	void loadMasterList();
	void storeMasterList();
	void menu();

private:
	Node<T>* pHead;
};

template <class T>
List<T>::List() {
	pHead = nullptr;
}

template <class T>
void List<T>::importRecords() {
	std::fstream infile;
	infile.open("classList.csv", std::fstream::in);
	if (infile) {
		while (!infile.eof()) {
			std::string temp;
			getline(infile, temp, '\n');
			std::string arr[7];
			std::string load;
			bool inQuotes = false;
			int i = 0;
			for (auto c : temp) {
				if (c == '"' && inQuotes == true) {
					inQuotes = false;
				} else if (c == '"' && inQuotes == false) {
					inQuotes = true;
				} else if (c == ',' || c == '\n') {
					if (inQuotes == false) {
						arr[i] = load;
						load = "";
						++i;
					}else {
						load.push_back(' ');
					}
				} else if (c != ',') {
					if (c != '"') {
						load.push_back(c);
					}
				}
			}
			arr[6] = load;//lazy af
			if (arr[0] != "") {
				Data newData(stoi(arr[0]), stoi(arr[1]), arr[2], arr[3], arr[4], arr[5], arr[6]);
				if (pHead == nullptr) {
					pHead = new Node<T>(newData, nullptr);
				} else {
					pHead = new Node<T>(newData, pHead);
				}
			}
		}
	}
	infile.close();
}

template <class T>
void List<T>::display() {
	Node<T>* curr = pHead;
	while (curr != nullptr) {
		curr->getData().display();
		curr = curr->getNext();
	}
}

template <class T>
void List<T>::markAbsences() {
	Node<T>* curr = pHead;
	char c;
	while (curr != nullptr) {
		curr->getData().display();
		std::cout << "Absent: y/n\n";
		std::cin >> c;
		if (c != 'y' && c != 'n') {
			std::cout << "Wrong input\n";
			return;
		} else if (c == 'y') {
			system("cls");
			curr->incrementAbsence();
		} else if (c == 'n') {
			system("cls");
		}
		curr = curr->getNext();
	}
}

template <class T>
void List<T>::generateReports(int threshhold) {
	std::fstream outfile;
	outfile.open("recentAbsences.txt", std::fstream::out);
	if (outfile) {
		Node<T>* curr = pHead;
		while (curr != nullptr){
			outfile << curr->getData().getName();
			outfile << ',';
			outfile << curr->getData().getAbsenceNum();
			outfile << ',';
			outfile << curr->getData().getAbsenceDates().peek();
			outfile << std::endl;
			curr = curr->getNext();
		}
	}
	outfile.close();

	outfile.open("threshholdAbsences.txt", std::fstream::out);
	if (outfile) {
		Node<T>* curr = pHead;
		while (curr != nullptr) {
			if (curr->getData().getAbsenceNum() > threshhold) {
				outfile << curr->getData().getName();
				outfile << curr->getData().getAbsenceNum();
				outfile << std::endl;
			}
			curr = curr->getNext();
		}
	}
	outfile.close();
}

template <class T>
void List<T>::loadMasterList() {
	std::fstream infile;
	infile.open("masterList.txt", std::fstream::in);
	if (infile) {
		while (!infile.eof()) {
			///////
			std::string temp;
			getline(infile, temp, '\n');
			std::string arr[8];
			std::string load;
			int i = 0;
			for (auto c : temp) {
				if (c == ',' || c == '\n') {
					arr[i] = load;
					load = "";
					++i;
				}
				else if (c != ',') {
					if (c != '"') {
						load.push_back(c);
					}
				}
			}
			if(arr[0]!=""){
				Data newData(stoi(arr[0]), stoi(arr[1]), arr[2], arr[3], arr[4], arr[5], arr[6], stoi(arr[7]));
				if (pHead == nullptr) {
					pHead = new Node<T>(newData, nullptr);
				}
				else {
					pHead = new Node<T>(newData, pHead);
				}
			}
			///////
		}
	}
	infile.close();
}

template <class T>
void List<T>::storeMasterList() {
	std::fstream outfile;
	outfile.open("masterList.txt", std::fstream::out);
	if (outfile) {
		Node<T>* curr = pHead;
		while (curr != nullptr) {
			outfile << curr->getData().getRecordNum() << ",";
			outfile << curr->getData().getId() << ",";
			outfile << curr->getData().getName() << ",";
			outfile << curr->getData().getEmail() << ",";
			outfile << curr->getData().getUnits() << ",";
			outfile << curr->getData().getProgram() << ",";
			outfile << curr->getData().getLevel() << ",";
			outfile << curr->getData().getAbsenceNum() << ",";
			outfile << curr->getData().getAbsenceDates().getStack();
			outfile << "\n";
			curr = curr->getNext();
		}
	}
	outfile.close();
}

template <class T>
void List<T>::menu() {
	bool exit = false;
	int command;
	std::string reply;
	while (!exit) {
		std::cout << "1.    Import course list\n";
		std::cout << "2.    Load master list\n";
		std::cout << "3.    Store master list\n";
		std::cout << "4.    Mark absences\n";
		std::cout << "5.    Generate report\n";
		std::cout << "6.    Display\n";
		std::cout << "7.    Exit\n";
		std::cout << "8.    CLS\n";
		std::cout << reply << "\n";
		std::cin >> command;
		switch (command) {
			case 1:
				importRecords();
				reply = "Records Imported";
				break;
			case 2:
				loadMasterList();
				reply = "Master List Loaded";
				break;
			case 3:
				storeMasterList();
				reply = "Master List Stored";
				break;
			case 4:
				markAbsences();
				reply = "Attendance Noted";
				break;
			case 5:
				std::cout << "Enter threshhold\n";
				int num;
				std::cin >> num;
				generateReports(num);
				reply = "Reports Generated";
				break;
			case 6:
				display();
				break;
			case 7:
				exit = true;
				break;
			case 8:
				system("cls");
				reply = "";
				break;
			default:
				reply = "Enter a correct value";
		}
	}
}
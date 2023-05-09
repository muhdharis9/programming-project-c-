#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include <time.h>
#include <ctime>

#define DISCOUNT 0.1
using namespace std;

struct kereta
{
	char name[50];
	char warna[20];
	char no_plate[20];
	int passenger;
	int rate;
};
void getline_(int x)
{
	cout << "\t";
	for (int i = 0; i < x; i++)
	{
		cout << "-";
	}
	cout << endl;
}
kereta sewa(int x, kereta car[6])
{

	car[0] = { "PRODUA BEZZA", "Black", "JJR113",4 ,  200 };
	car[1] = { "PRODUA MYVI", "Yellow", "MBV9564", 4 ,  167 };
	car[2] = { "PROTON PERSONA", "Red", "AKN6654", 4 ,  200 };
	car[3] = { "PROTON WIRA", "Black", "MBU3245",4, 150 };
	car[4] = { "HONDA CR-V", "White", "WA8765A", 7, 350 };
	car[5] = { "TOYOTA ALPHARD", "Black", "W402J", 6, 320 };
	getline_(x);
	cout << "\t|" << setfill(' ') << setw(17) << "Car Model |" << setfill(' ') << setw(10) << "color |" << setw(13) << setfill(' ') << "No. Plate |" << setfill(' ') << setw(21) << "No.of Passenger |" << right << setfill(' ') << setw(21) << "Rental Rate(per Day)|" << endl;
	getline_(x);
	for (int i = 0; i < 6; i++)
	{
		cout << "      " << i + 1 << ")" << "| " << setfill(' ') << setw(14) << car[i].name << " | " << setfill(' ') << setw(7) << right << car[i].warna << " | " << setfill(' ') << setw(10) << right << car[i].no_plate << " | " << setfill(' ') << setw(18) << right << car[i].passenger << " |" << " RM " << setfill(' ') << setw(2) << right << car[i].rate << setfill(' ') << setw(14) << "|" << endl;
		getline_(x);
	}
	return car[6];
}
struct customer
{
	char nama[60];
	char no_tel[15];
};
void detail(customer& pelanggan)
{
	cout << "\t" << "Please Enter Your Name : ";
	cin.getline(pelanggan.nama, 59);
	cout << "\t" << "Please Enter Your Number Phone : ";
	cin.getline(pelanggan.no_tel, 15);
	cout << "\t" << "Welcome " << pelanggan.nama << " To ADZ CAR RENTAL, Here are the list of cars we have to offer : " << endl;
}
void input(kereta sewa[6], int& choice, double& total, int& hari,double& dis)
{
	cout << "\n\t" << "Please enter the number of the car you want to rent(1-6) : ";
	cin >> choice;
	while (choice <= 0 || choice >= 7)
	{
		cout << "\tInvalid! Please enter the number between(1-6) again : ";
		cin >> choice;
	}
	if (choice >= 1 && choice <= 6)
	{
		choice = choice - 1;

		cout << "\tThe car you choose is: " << endl;
		getline_(74);
		cout << "\t|";
		cout << setw(17) << setfill(' ') << "Car Model |" << setw(10) << setfill(' ') << "color |" << setw(13) << setfill(' ') << "No. Plate |" << setw(12) << setfill(' ') << "Passenger |" << right << setfill(' ') << setw(21) << "Rental Rate(per Day)|" << endl;
		getline_(74);
		cout << "\t| " << setfill(' ') << setw(14) << sewa[choice].name << " | " << setfill(' ') << setw(7) << sewa[choice].warna << " | " << setfill(' ') << setw(10) << sewa[choice].no_plate << " | " << setfill(' ') << setw(9) << sewa[choice].passenger << " | " << setfill(' ') << setw(4) << " RM " << sewa[choice].rate << setfill(' ') << setw(13) << "|" << endl;
		getline_(74);
		cout << "\tNOTE/ - If you rent more than 3 day, you get 10% discount for this car!!!!" << endl;
		cout << "\n\t" << "Please enter how many days you want to use this car: ";
		cin >> hari;
		while (hari <= 0)
		{
			cout << "\t" << "Invalid, Please enter how many days you want to use this car: ";
			cin >> hari;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (hari > 3)
		{
			total = hari * sewa[choice].rate;
		    dis = 0;
			dis = (total * DISCOUNT);
			cout << "\t" << "Your discount 10% is : RM  " << fixed << showpoint << setprecision(2) << setfill('*') << setw(11) << dis << endl;
			total = total - dis;
			cout << "\t" << "The total of your booking after discount 10% is: RM " << fixed << showpoint << setprecision(2) << setfill('*') << setw(11) << total << endl;
		}
		else if (hari >= 1 && hari <= 3)
		{
			total = hari * sewa[choice].rate;
			dis = 0;
			cout << "\t" << "The total of your booking is: RM " << fixed << showpoint << setprecision(2) << setfill('*') << setw(11) << total << endl;
		}
	}
}
struct PEMBAYARAN
{
	char nama[60];
	char bank[30];
	char cardNum[30];
	char CCV[10];
	char Date[10];
};
void getTAC(int& tac1, int& tac2, int& inputtac, int& totaltac)
{
	srand(time(0));
	tac1 = rand() % 1000;
	tac2 = rand() % 1000;
	totaltac = (tac1 * tac2) - tac1;
}
void display(PEMBAYARAN pay, int totaltac, double total, char continue_2, int tac1, kereta sewa[6], int chooice, int hari,char receipt, customer& pelanggan, double& dis)
{
	cout << "\n\tYour detail Payment is below" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "NAME |" << setw(47) << setfill(' ') << pay.nama << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "BANK |" << setw(47) << setfill(' ') << pay.bank << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "CARD NUM |" << setw(47) << setfill(' ') << pay.cardNum << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "CCV |" << setfill(' ') << setw(47) << pay.CCV << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "EXPIRED DATE |" << setw(47) << setfill(' ') << pay.Date << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "CAR NAME |" << setw(47) << setfill(' ') << sewa[chooice].name << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "DAY |" << setw(47) << setfill(' ') << right << hari << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "TAC NUMBER |" << setfill(' ') << setw(47) << totaltac << " |" << endl;
	getline_(65);
	time_t ttime = time(NULL);
	tm* local_time = localtime(&ttime);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "DATE |" << setw(39) << setfill(' ') << local_time->tm_mday << "/" << setw(2) << setfill(' ') << 1 + local_time->tm_mon << "/" << setw(2) << setfill(' ') << 1900 + local_time->tm_year << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "TIME |" << setw(41) << setfill(' ') << local_time->tm_hour << ":" << setw(2) << setfill(' ') << local_time->tm_min << ":" << setw(2) << setfill(' ') << local_time->tm_sec << " |" << endl;
	getline_(65);
	cout << "\t|";
	cout << setw(15) << setfill(' ') << "TOTAL |" << setfill(' ') << setw(36) << "RM" << setw(6) << setfill(' ') << fixed << showpoint << setprecision(2) << setfill('*') << setw(11) << total << " |" << endl;
	getline_(65);
	cout << "\n\tAre you confirm for this transaction? (Y/N) : ";
	cin >> continue_2;
	while (continue_2 != 'N' && continue_2 != 'n' && continue_2 != 'Y' && continue_2 != 'y')
	{
		cout << "\n\t\t\tINVALID COMMAND. Key-In Agian.! " << endl;
		cout << "\n\tAre you confirm for this transaction? (Y/N) : ";
		cin >> continue_2;
	}
	if (continue_2 == 'N' || continue_2 == 'n')
	{
		cout << "\n\tYour transaction has failed, please booking again.";
	}
	else
	{
		if (continue_2 == 'Y' || continue_2 == 'y')
		{
			system("cls");
			cout << "\n\n\n\t\t\t  Your Payment has successful." << endl;
			cout << "\t\t  Thank for booking at ADZ CAR RENTAL SDN BHD." << endl;
			cout <<"\n\n\t\tAre you want receipt for this transaction? (Y/N) : ";
			cin >> receipt;
			while (receipt != 'Y' && receipt != 'y' && receipt != 'n' && receipt != 'N')
			{
				cout << "\t\t\tError, Invalid Command! Key-in again," << endl;
				cout << "\n\n\t\tAre you want receipt for this transaction? (Y/N) : ";
				cin >> receipt;
			}
			if (receipt == 'N' || receipt == 'n')
			{
				cout << "\n\tYour transaction has successful, Your booking Number is AZ99" << tac1 << endl;
				time_t ttime = time(NULL);
				char* dt = ctime(&ttime);
				cout << "\t     Your Date seccessful booked : " << dt;
				cout << "\t\t  Thank for booking at ADZ CAR RENTAL SDN BHD." << endl;
			}
			else
			{
				system("color 9");
				cout << "\n\n\n";
				cout << setw(108) << setfill(' ') << "RECEIPT" << endl;
				cout << "\tADZ CAR RENTAL SDN BHD\n" << endl;
				cout << "\tAddress  : No 7 Lorong 1 Jalan BJ 29 Taman Bertam Jaya" << endl;
				cout << "\tDistrict : Cheng" << endl;
				cout << "\tCity     : Melaka" << endl;
				cout << "\tPoscode  : 74560\n" << endl;
				getline_(100);
				cout << "\t" << setfill(' ') << setw(54) << left << "Bill to       : " << setfill(' ') << setw(47) << "Details      : \n" << endl;
				cout << "\t" << "Name          : " << setfill(' ') << setw(38) << left  <<pelanggan.nama<< setfill(' ') << setw(0) << "Receipt No   : AD5132Z8"<<tac1 << endl;
				cout << "\t" << "No Telephone  : "<< setfill(' ') << setw(38) << left  <<pelanggan.no_tel<< setfill(' ') << setw(0) << "Receipt Date : "<< local_time->tm_mday << "/" << setw(2) << setfill(' ') << 1 + local_time->tm_mon << "/" << setw(2) << setfill(' ') << 1900 + local_time->tm_year << endl;
				cout << "\t" << "Payment Using : " << setfill(' ') << setw(38)<<left  <<"Credit/Debit Card" << setfill(' ') << setw(0) << "Payment Time : " << local_time->tm_hour << ":" << setw(2) << setfill(' ') << local_time->tm_min << ":" << setw(2) << setfill(' ') << local_time->tm_sec << endl;
				cout << "\t" << "Card Name     : " << setfill(' ') << setw(38) << left  << pay.nama << setfill(' ') << setw(0) << "Card Number  : " << pay.cardNum << setfill(' ') << setw(0) << endl;
				getline_(100);
				cout << "\n\n";
				cout << "\t" << setfill(' ') << setw(46) << left << "Description" << setfill(' ') << setw(20) << "  Day" << setfill(' ') << setw(18) << "  Rate" << setfill(' ') << setw(15) << "  Amount" << endl;
				getline_(100);
				total = hari * sewa[chooice].rate;
				cout << "\t" << setfill(' ') << setw(45) << left << sewa[chooice].name << "   " << setfill(' ') << setw(17) << hari << "   " << setfill(' ') << setw(15) << sewa[chooice].rate << "   " << setfill(' ') << setw(11) << total << "  " << setfill(' ') << setw(4) << endl;
				cout << "\n";
				getline_(100);
				cout << "\n";
				cout << "\tNotes : " << endl;
				cout << setfill(' ') << setw(75) << " " << "Sub-Total " << setfill(' ') << setw(7) << " " << " RM " << total << endl;
				cout << setfill(' ') << setw(75) << " " << "Discout " << setfill(' ') << setw(9) << " " << " RM " <<dis << endl;
				cout << setfill(' ') << setw(75) << " " << "Tax " << setfill(' ') << setw(13) << " " << " RM 0\n" << endl;
				cout << setfill(' ') << setw(74) << " " << setfill('-') << setw(28) << " " << endl;
				total = total - dis;
				cout << setfill(' ') << setw(75) << " " << "Total Paid " << setfill(' ') << setw(6) << " " << " RM " << total << "\n\n" << endl;
				cout << "\tThis receipt is only for you transaction, If you cancel this order, your money will not be refunded" << endl;
				cout << "\t\t\t\t\t\tThank for you commitment\n\n\n" << endl;
			}
		}
	}
	cout << endl;
}
void functionNew(PEMBAYARAN& pay, char& continue_, int& inputtac, int& totaltac, char& comtac, char& continue_2, double total, int tac1, int tac2, kereta sewa[6], int chooice, int hari,char receipt, customer& pelanggan, double&dis)
{
	cout << "\n\tKey-in (1) for procced (2) for re-enter Credit/Debit card detail : ";
	cin >> continue_;
	if (continue_ == '1')
	{
		display(pay, totaltac, total, continue_2, tac1, sewa, chooice, hari,receipt, pelanggan ,dis);
	}
}
void functionValidationTac(int& inputtac, int& totaltac,int& data)
{
	if (data == 1)
	{
		cout << "\n\tINVALID, YOU HAVE ONE MORE ATTEMPTS." << endl;
		cout << "\tYOUR TAC NUMBER IS : " << totaltac << endl;
		cout << "\tPlease key-in again : ";
		cin >> inputtac;
	}
	if (data == 2)
	{
		cout << "\n\tINVALID, YOU HAVE LAST ONE ATTEMPTS." << endl;
		cout << "\tYOUR TAC NUMBER IS : " << totaltac << endl;
		cout << "\tPlease key-in again : ";
		cin >> inputtac;
	}
}

void terminated()
{
	system("color 0");
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\n\n\n\n\t\t\tThis section was terminated by you!"<<endl;
	cout << "\t\t\tThanks for come and see you agian!!"<<endl;

}
void payment(PEMBAYARAN& pay, char& continue_, int inputtac, int totaltac, char& comtac, char& continue_2, double total, int tac1, int tac2, kereta sewa[6], int chooice, int hari,int& data,int& terminate,char& receipt, customer pelanggan, double& dis)
{
	cout << "\n\tPlease confirm your booking payment using Credit/Debit card." << endl;
	cout << "\t" << "----------------------------------------" << endl;
	cout << "\t" << "Please enter your Bank Account details:- " << endl;
	cout << "\tplease key-in Card Name ( FULLNAME ) : ";
	cin.getline(pay.nama, 59);
	cout << "\tPlease key-in Name Of Bank : ";
	cin.getline(pay.bank, 30);
	cout << "\tPlease key-in Card Number (**** **** **** ****) : ";
	cin.getline(pay.cardNum, 30);
	cout << "\tPlease key-in CCV Number (***): ";
	cin.getline(pay.CCV, 10);
	cout << "\tPlease key-in Card Expired Date (**/**): ";
	cin.getline(pay.Date, 10);
	cout << "\tRequest TAC Number ? (Y/N) : ";
	cin >> comtac;
	if (comtac == 'Y' || comtac == 'y')
	{
		getTAC(tac1, tac2, inputtac, totaltac);
		cout << "\tYour TAC Number is : " << totaltac << endl;
		cout << "\tPlease key-in TAC number: ";
		cin >> inputtac;
		if (inputtac == totaltac)
		{
			display(pay, totaltac, total, continue_2, tac1, sewa, chooice, hari, receipt, pelanggan, dis);
			while (continue_ == '2')
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari,data, terminate,receipt, pelanggan, dis);
			}
		}
		else
		{
			if (inputtac != totaltac)
			{
				data = 0;
				while (inputtac != totaltac)
				{
					data++;
					functionValidationTac(inputtac, totaltac, data);
					if (inputtac == totaltac)
					{
						functionNew(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari,receipt, pelanggan, dis);
						while (continue_ == '2')
						{
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari, data, terminate, receipt, pelanggan, dis);
						}
					}
					if (data >= 3)
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\tWRONG TAC!!!. YOU NEED TO GET THE NEW TAC NUMBER AGAIN.!";
						cout << "\n\tPLEASE KEY IN (Y) TO PROCCED";
						cout << "\n\n\tRequest TAC Number ? (Y/N) : ";
						cin >> comtac;
						if (comtac == 'Y' || comtac == 'y')
						{
							getTAC(tac1, tac2, inputtac, totaltac);
							cout << "\tYour TAC Number is : " << totaltac << endl;
							cout << "\tPlease key-in TAC number: ";
							cin >> inputtac;
							data = 0;
							while (inputtac != totaltac)
							{
								data++;
								functionValidationTac(inputtac, totaltac, data);
								if (data == 3)
								{
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n\tYOU HAVE ALREADY ENTERED THE WRONG TAC NUMBER TWICE, YOU NEED TO START OVER OR TERMINATE" << endl;
									cout << "\tKey-in (1) for re-enter Credit/Debit card detail (2) terminate this section : ";
									cin >> terminate;
									while ( terminate != 1 && terminate != 2)
									{
										cout << "\tWRONG COMMAD!!! key-in again." << endl;
										cout << "\tKey-in (1) for re-enter Credit/Debit card detail (2) terminate this section : ";
										cin >> terminate;
									}
									if (terminate == 2)
									{
										terminated();
									}
									else if (terminate == 1)
									{
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari, data, terminate, receipt, pelanggan, dis);
									}
								}	
							}
							if (inputtac == totaltac)
							{
								functionNew(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari, receipt, pelanggan, dis);
								while (continue_ == '2')
								{
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari,data, terminate,receipt ,pelanggan,  dis);
								}
							}
						}
						else
						{
							if (comtac == 'N' || comtac == 'n' && comtac != 'Y' || comtac != 'y')
							{
								cout << "\tInvalid, YOU NEED TO REQUEST TAC NUMBER TO PROCCED!!" << endl;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari, data, terminate, receipt, pelanggan, dis);
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (comtac == 'N' || comtac == 'n' && comtac != 'Y' || comtac != 'y')
		{
			cout << "\tInvalid, YOU NEED TO REQUEST TAC NUMBER TO PROCCED!!" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, sewa, chooice, hari, data, terminate, receipt, pelanggan, dis);
		}
	}
}


int main()
{
	kereta car[6];
	customer pelanggan;
	PEMBAYARAN pay;
	char continue_, continue_2, comtac,receipt;
	int x = 83, choice, tac1, tac2, totaltac, inputtac, hari,data, terminate;
	double total,dis;
	system("color 9");
	cout << "\n\n\t\t\t    WELCOME TO ADZ CAR RENTAL SDN BHD." << endl;
	cout << "\t\t" << "No 7 Lorong 1 Jalan BJ 29 Taman Bertam Jaya, Cheng 75460 Melaka" << endl;
	cout << "\t" << "-" << setfill('-') << setw(80) << "-" << endl;
	detail(pelanggan);
	sewa(x, car);
	input(car, choice, total, hari, dis);
	getTAC(tac1, tac2, inputtac, totaltac);
	payment(pay, continue_, inputtac, totaltac, comtac, continue_2, total, tac1, tac2, car, choice, hari,data, terminate,receipt,pelanggan,dis);
}
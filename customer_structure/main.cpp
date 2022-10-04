#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Customer {
  string name;
  string address;
  string city;
  string state;
  string zip;
  string phoneNumber;
  int balance;
  string lastPayment;
};

void getInfo(vector<Customer>& customers) {
  Customer newCust;

  cout << "Enter customer's name: ";
  while (true) {
    string name;
    getline(cin, name);

    if (name.empty()) {
      continue;
    }

    newCust.name = name;
    break;
  }

  while (true) {
    cout << "Enter street address: ";
    string address;
    getline(cin, address);

    newCust.address = address;
    break;
  }

  while (true) {
    cout << "Enter city: ";
    string city;
    getline(cin, city);

    newCust.city = city;
    break;
  }

  while (true) {
    cout << "Enter state: ";
    string state;
    getline(cin, state);

    newCust.state = state;
    break;
  }

  while (true) {
    cout << "Enter ZIP code: ";
    string zip;
    cin >> zip;

    newCust.zip = zip;
    break;
  }

  cout << "Enter telephone number: ";
  while (true) {
    string phoneNumber;
    getline(cin, phoneNumber);

    if (phoneNumber.empty()) {
      continue;
    }

    newCust.phoneNumber = phoneNumber;
    break;
  }

  cout << "Enter balance: ";
  while (true) {
    string strBalance;
    cin >> strBalance;

    if (strBalance.empty()) {
      continue;
    }

    int balance;
    try {
      balance = stoi(strBalance);
    } catch (invalid_argument& e) {
      cout << "Invalid balance. Please enter a valid integer" << endl;
      cout << "Enter balance: ";
      continue;
    }

    if (balance < 0) {
      cout << "Balance cannot be negative" << endl;
      cout << "Enter balance: ";
      continue;
    }

    newCust.balance = balance;
    break;
  }

  cout << "Enter date of last payment: ";
  while (true) {
    string lastPayment;
    getline(cin, lastPayment);

    if (lastPayment.empty()) {
      continue;
    }

    newCust.lastPayment = lastPayment;
    break;
  }

  customers.push_back(newCust);
};

void showInfo(vector<Customer> customers) {
  if (customers.size() == 0) {
    cout << "No customers to display" << endl;
  } else {
    for (int i = 0; i < customers.size(); i++) {
      Customer cust = customers.at(i);

      stringstream strStreamBalance;
      strStreamBalance << fixed << setprecision(2) << cust.balance;
      string strBalance = strStreamBalance.str();

      cout << "---------------------" << endl
          << "Info for customer: " << cust.name << endl
          << "- Address: " << cust.address << endl
          << "- City: " << cust.city << endl
          << "- State: " << cust.state << endl
          << "- ZIP Code: " << cust.zip << endl
          << "- Telephone Number: " << cust.phoneNumber << endl
          << "- Balance: " << strBalance << endl
          << "- Last Payment: " << cust.lastPayment << endl;
    }

    cout << "---------------------" << endl;
  }
};

int main() {
  vector<Customer> customers = {};

  while (true) {
    cout << "[1] Enter new account info" << endl
         << "[2] Change account info" << endl
         << "[3] Display all accounts info" << endl
         << "[4] Exit" << endl
         << "Enter selection: ";

    string selection;
    cin >> selection;

    if (selection == "1") {
      getInfo(customers);
    } else if (selection == "2") {
      if (customers.size() < 1) {
        cout << "There are no customers to edit" << endl;
        continue;
      }

      while (true) {
        cout << "Customers available to edit:" << endl;
        for (int i = 0; i < customers.size(); i++) {
          cout << "[" << i << "] " << customers.at(i).name << endl; 
        }
        cout << "Enter your selection: ";
        string strCustSelection;
        cin >> strCustSelection;

        int custSelection;
        try {
          custSelection = stoi(strCustSelection);
        } catch (invalid_argument& e) {
          cout << "Invalid selection. Please enter a valid integer" << endl;
          continue;
        }

        if (custSelection >= customers.size() || custSelection < 0) {
          cout << "Invalid selection. Please enter one of the numbers shown" << endl;
          continue;
        }

        Customer cust = customers.at(custSelection);

        cout << "Enter customer's name: ";
        while (true) {
          string name;
          getline(cin, name);

          if (name.empty()) {
            continue;
          }

          cust.name = name;
          break;
        }

        while (true) {
          cout << "Enter street address: ";
          string address;
          getline(cin, address);

          cust.address = address;
          break;
        }

        while (true) {
          cout << "Enter city: ";
          string city;
          getline(cin, city);

          cust.city = city;
          break;
        }

        while (true) {
          cout << "Enter state: ";
          string state;
          getline(cin, state);

          cust.state = state;
          break;
        }

        while (true) {
          cout << "Enter ZIP code: ";
          string zip;
          cin >> zip;

          cust.zip = zip;
          break;
        }

        cout << "Enter telephone number: ";
        while (true) {
          string phoneNumber;
          getline(cin, phoneNumber);

          if (phoneNumber.empty()) {
            continue;
          }

          cust.phoneNumber = phoneNumber;
          break;
        }

        cout << "Enter balance: ";
        while (true) {
          string strBalance;
          cin >> strBalance;

          if (strBalance.empty()) {
            continue;
          }

          int balance;
          try {
            balance = stoi(strBalance);
          } catch (invalid_argument& e) {
            cout << "Invalid balance. Please enter a valid integer" << endl;
            cout << "Enter balance: ";
            continue;
          }

          if (balance < 0) {
            cout << "Balance cannot be negative" << endl;
            cout << "Enter balance: ";
            continue;
          }

          cust.balance = balance;
          break;
        }

        cout << "Enter date of last payment: ";
        while (true) {
          string lastPayment;
          getline(cin, lastPayment);

          if (lastPayment.empty()) {
            continue;
          }

          cust.lastPayment = lastPayment;
          break;
        }

        customers[custSelection] = cust;

        break;
      }
    } else if (selection == "3") {
      showInfo(customers);
    } else if (selection == "4") {
      break;
    } else {
      cout << "Invalid selection" << endl;
      continue;
    };
  }

  return 0;
}
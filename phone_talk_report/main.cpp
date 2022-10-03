#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Contraints
//  Talk minutes: 0<=t<=10080

const int MAX_MINUTES = 10080;

int main() {
  while (true) {
    cout << "Enter your customer ID (or enter 'x' to quit): ";
    string strId;
    cin >> strId;

    if (strId == "x") {
      break;
    } else {
      int id;
      try {
        id = stoi(strId);
      } catch(invalid_argument & e) {
        cout << "Invalid customer ID (enter 'x' to quit)" << endl;
        continue;
      }

      while (true) {
        cout << "Plans:" << endl
             << "- Commercial Plan: enter 'c'" << endl
             << "- Residential Plan: enter 'r'" << endl
             << "- Student Plan: enter 's'" << endl
             << "Enter plan type: ";
        
        string strPlan;
        cin >> strPlan;
        transform(strPlan.begin(), strPlan.end(), strPlan.begin(), ::tolower);

        if (strPlan != "c" && strPlan != "r" && strPlan != "s") {
          cout << "Invalid plan entered" << endl;
          continue;
        }

        char plan = strPlan.c_str()[0];

        while (true) {
          cout << "Enter the amount of minutes you've used this week: ";
          
          string strMinutes;
          cin >> strMinutes;

          int minutes;
          try {
            minutes = stoi(strMinutes);
          } catch(invalid_argument & e) {
            cout << "Invalid number. Please enter a valid integer" << endl;
            continue;
          }

          if (minutes < 0) {
            cout << "Talk minutes cannot be negative" << endl;
            continue;
          }

          if (minutes > MAX_MINUTES) {
            cout << "Minutes cannot be more than the amount of minutes in a week (10080)" << endl;
            continue;
          }

          // Commerical
          //  $0.20/min (=<300 minutes)
          //  $0.10/min (>300 minutes)

          // Residential
          //  $0.10/min (=<120 minutes)
          //  $0.05/min (>120 minutes)

          // Student
          //  $0.15/min

          // Pre-payment: $25.00
          float balance = 25.00;
          float cost = 0.00;

          switch (plan) {
            case 'c':
              if (minutes > 300) {
                cost += 0.2*300;
                cost += 0.1*(minutes-300);
              } else cost += 0.1*minutes;
              break;
            case 'r':
              if (minutes > 120) {
                cost += 0.1*120;
                cost += 0.05*(minutes-120);
              } else cost += 0.1*minutes;
              break;
            case 's':
              cost += 0.15*minutes;
              break;
          }

          string balanceDesc = (balance-cost) >= 0 ? "Remaining credit" : "Amount due";
          
          stringstream strStreamCost;
          strStreamCost << fixed << setprecision(2) << cost;
          string strCost = strStreamCost.str();

          stringstream strStreamBalance;
          strStreamBalance << fixed << setprecision(2) << fabs(balance-cost);
          string strBalance = strStreamBalance.str();

          cout << "Weekly Report for customer " << strId << endl
               << "- Plan Type: " << strPlan << endl
               << "- Talk Minutes: " << strMinutes << endl
               << "- Total Cost: $" << strCost << endl
               << "- " << balanceDesc << ": $" << strBalance << endl;

          break;
        }
        break;
      }
    }
  }

  return 0;
}
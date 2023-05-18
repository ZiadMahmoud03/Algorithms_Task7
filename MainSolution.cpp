#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main() {

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> random(0, 1);
    int Starting_Spot = 1;
    int Num_Shots = 0;
    int Start_Spot = 1;
    int Target_Spot;
    bool Target_Hit = false;
    int Hiding_Spots;
    
    cout << "Please enter number of hiding spots: ";
    cin >> Hiding_Spots;                                                  // Enter number of Hiding spots
    int Last_Spot = Hiding_Spots;                                         // Number of Hiding spots = Last Spot
    
    do {
        cout << "Please enter target hiding spot: ";
        cin >> Target_Spot;
    } while (Target_Spot < 1 || Target_Spot > Hiding_Spots);      // 1 < Enter Target hiding Spot < Hiding spot
   
    while (!Target_Hit) {
        cout << "_____________________________________ "<< endl << endl;
        cout << "Hitting targets " << Start_Spot << " & " << Last_Spot << endl;
        if (Start_Spot > Hiding_Spots) {
            Start_Spot = 1;
            Last_Spot = Hiding_Spots;
        }

        Num_Shots++;

        if (Start_Spot == Target_Spot) {
            cout << "Target hit!" << endl;
            Target_Hit = true;
            break;
        }

        Num_Shots++;

        if (Last_Spot == Target_Spot) {
            cout << "Target hit!" << endl;
            Target_Hit = true;
            break;
        }

        int randomNum = random(rng);

        cout << "Number of shots: " << Num_Shots << endl;
        if (randomNum == 0) {
            Target_Spot--;

            if (Target_Spot < Starting_Spot) {
                Target_Spot = Target_Spot + 2;
                cout << "The target moved forward to hiding spot: " << Target_Spot << endl;
            }
            else {
                cout << "The target moved backward to hiding spot: " << Target_Spot << endl;
            }
        }
        else if (randomNum == 1) {
            Target_Spot++;

            if (Target_Spot > Hiding_Spots) {
                Target_Spot = Target_Spot - 2;
                cout << "The target moved backward to hiding spot: " << Target_Spot << endl;
            }
            else {
                cout << "The target moved forward to hiding spot : " << Target_Spot << endl;
            }
        }
        else {
            cout << "Invalid random number generated" << endl;
        }
        Start_Spot += 2;
        Last_Spot -= 2;
    }
    cout << "**************************************** "<< endl << endl;
    cout << "Last Hitting targets " << Start_Spot << " & " << Last_Spot << endl;
    cout << "Total number of shots: " << Num_Shots << endl;
    cout << "Target hit at postion: " << Target_Spot << endl;

    return 0;
}


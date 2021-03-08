#include <iostream> // Required for cout, cin, endl
#include <iomanip> // Required for setprecision
#include <cmath>
using namespace std; // The compiler will use all the library filenames in std
// The main function - the starting point of our program
int main() {
    // Declare and initialize objects
    double length = 0, gk = 0, qk = 0, h = 0, b = 0, Ws = 0, TCPA = 0, Wd = 0, V = 0, M = 0;
    int counter1;
    const int Cuw = 25;
    const double PERMANENT_LOAD_MARGIN = 0.60;
    const double VARIABLE_LOAD_MARGIN = 0.20;
    do{
        // Print values
        do
        {
            cout << "Enter the Length of the Beam (m)" << endl;
            cin >> length;
            if (length <= 0)
                cout << "You Must Enter a Positive Value for Length." << endl;
        }
        while (length <= 0);
        do
        {
            cout << "Enter the Permanent Load of the Beam (gk, kN/m):" << endl;
            cin >> gk;
            if (gk <= 0)
                cout << "You Must Enter a Positive Value for the Permanent Load." << endl;
        }
        while (gk <= 0);
        do
        {
            cout << "Enter the Variable Load of the Beam (qk, kN/m):" << endl;
            cin >> qk;
            if (qk <= 0)
                cout << "You Must Enter a Positive Value for the Variable Load." << endl;
        }
        while (qk <= 0);
        //Calculating the Size
        h = (length * 1000) / 14;
        b = 0.4 * round(h);
        //Calculating Total Characteristic Load
        Ws = (h/ 1000) * (b/1000) * Cuw;
        TCPA = Ws + gk;
        //Calculating Shear Force and Bending Moment
        Wd = (((1 + PERMANENT_LOAD_MARGIN)*gk) + ((1 + VARIABLE_LOAD_MARGIN)*qk));
        V = Wd * (length / 2);
        M = Wd * ((length*length) / 8);
        //Printing the Values
        cout << "The depth of the beam is " << round(h) << " mm" << endl;
        cout << "The width of the beam is " << round(b) << " mm" << endl;
        cout << "The Total Characteristic Load is " << setprecision (6) <<  TCPA << " kN/m" << endl;
        cout << "The Shear Force is " << V << " kN" << endl;
        cout << "The Bending Moment is " << M << " kNm" << endl;
        //Prompting to repeat the program
        cout << "Enter -1 to Exit or any other number to repeat"<<endl;
        cin>> counter1;
    }while(counter1 != -1);
    cout << "Program Terminating ..."<<endl;
    system("pause");
    // Exit program
    return 0;
}

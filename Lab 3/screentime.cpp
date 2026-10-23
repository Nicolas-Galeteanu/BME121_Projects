#include <iostream>
using namespace std;

int main()
{
    const double WAKING_MINUTES = 960;
    const int DAYS_PER_YEAR = 365;
    const double REDUCTION = 0.25;

    double dailyMinutes;
    int workoutLength;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Daily screen time (minutes): ";
    cin >> dailyMinutes;
    cout << "Workout length (minutes): ";
    cin >> workoutLength;
    if (cin.fail() || dailyMinutes > WAKING_MINUTES) {
        cout<<"DANGER";
        return 1;
    }
    double percentAwake = dailyMinutes * 100 / WAKING_MINUTES;

    double savedPerDay = dailyMinutes * REDUCTION;
    int savedYearly = savedPerDay * DAYS_PER_YEAR;

    int workouts = savedYearly / workoutLength;
    int spare = savedYearly % workoutLength;


    cout << "Share of waking hours: " << percentAwake << "%\n";
    cout << "Saved " << savedYearly << " min/year: " << workouts
         << " full workouts, " << spare << " leftover\n";

    return 0;
}
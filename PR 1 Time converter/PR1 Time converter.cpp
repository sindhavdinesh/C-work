#include <iostream>
using namespace std;

class TimeConverter {
public:

    // Seconds --> HH:MM:SS
    void secondsToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << seconds << endl;
    }

    // HH:MM:SS --> Seconds
    void timeToSeconds(int hours, int minutes, int seconds) {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main() {
    TimeConverter t;

    // Example 1: Seconds --> HH:MM:SS
    int secInput;
    cout << "Enter total seconds: ";
    cin >> secInput;
    t.secondsToTime(secInput);

    cout << endl;

    // Example 2: HH:MM:SS --> Seconds
    int h, m, s;
    cout << "Enter hours: ";
    cin >> h;
    cout << "Enter minutes: ";
    cin >> m;
    cout << "Enter seconds: ";
    cin >> s;

    t.timeToSeconds(h, m, s);

    return 0;
}

// output //

Enter total seconds: 4200
HH:MM:SS => 1:10:0

Enter hours: 4
Enter minutes: 34
Enter seconds: 30
Total seconds: 16470

--------------------------------
Process exited after 49.78 seconds with return value 0
Press any key to continue . . .

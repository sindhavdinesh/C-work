#include <iostream>
using namespace std;

class TimeConverter {
public:


    void secondsToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":";

        
        if (minutes < 10) cout << "0";
        cout << minutes << ":";

        
        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }

    
    void timeToSeconds(int hours, int minutes, int seconds) {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main() {
    TimeConverter t;


    int secInput;
    cout << "Enter total seconds: ";
    cin >> secInput;
    t.secondsToTime(secInput);

    cout << endl;

    
    int h, m, s;
    cout << "Enter hours: ";
    cin >> h;
    cout << "Enter minutes: ";
    cin >> m;
    cout << "Enter seconds: ";
    cin >> s;

    cout << endl;

    t.timeToSeconds(h, m, s);

    return 0;
}

// output //

Enter total seconds: 4200
HH:MM:SS => 1:10:00

Enter hours: 4
Enter minutes: 34
Enter seconds: 30

Total seconds: 16470

--------------------------------
Process exited after 19.45 seconds with return value 0
Press any key to continue . . .

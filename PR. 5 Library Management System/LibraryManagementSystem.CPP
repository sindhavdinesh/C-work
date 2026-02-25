#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 10


// Abstract Base Class

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    virtual ~LibraryItem() {}

    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

   
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};


// Derived Class: Book

class Book : public LibraryItem {
private:
    string isbn;
    bool isCheckedOut;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d), isbn(i), isCheckedOut(false) {

        if (isbn.length() < 5)
            throw invalid_argument("Invalid ISBN Format!");
    }

    void checkOut() override {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "Book checked out successfully.\n";
        } else {
            cout << "Book already checked out.\n";
        }
    }

    void returnItem() override {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not checked out.\n";
        }
    }

    void displayDetails() const override {
        cout << "\n[Book]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << isbn << endl;
    }
};


// Derived Class: DVD

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d), duration(dur) {

        if (duration <= 0)
            throw invalid_argument("Invalid Duration!");
    }

    void checkOut() override {
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override {
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[DVD]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " mins\n";
    }
};


// Main Function

int main() {

    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Display All Items\n";
        cout << "4. Check Out Item\n";
        cout << "5. Return Item\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        try {

            if (choice == 1 && count < MAX_ITEMS) {
                string title, author, dueDate, isbn;
                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> dueDate;
                cout << "Enter ISBN: ";
                cin >> isbn;

                libraryItems[count++] = new Book(title, author, dueDate, isbn);
                cout << "Book added successfully.\n";
            }

            else if (choice == 2 && count < MAX_ITEMS) {
                string title, author, dueDate;
                int duration;

                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> dueDate;
                cout << "Enter Duration (mins): ";
                cin >> duration;

                libraryItems[count++] = new DVD(title, author, dueDate, duration);
                cout << "DVD added successfully.\n";
            }

            else if (choice == 3) {
                for (int i = 0; i < count; i++) {
                    cout << "\nItem Index: " << i;
                    libraryItems[i]->displayDetails();
                }
            }

            else if (choice == 4) {
                int index;
                cout << "Enter Item Index: ";
                cin >> index;
                if (index >= 0 && index < count)
                    libraryItems[index]->checkOut();
                else
                    cout << "Invalid Index!\n";
            }

            else if (choice == 5) {
                int index;
                cout << "Enter Item Index: ";
                cin >> index;
                if (index >= 0 && index < count)
                    libraryItems[index]->returnItem();
                else
                    cout << "Invalid Index!\n";
            }

            else if (choice == 6) {
                cout << "Exiting Program...\n";
            }

            else {
                cout << "Invalid Choice!\n";
            }

        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 6);

   
    for (int i = 0; i < count; i++)
        delete libraryItems[i];

    return 0;
}

// output //

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 1
Enter Title: CppBasics
Enter Author: Bjarne
Enter Due Date: 10-03-2026
Enter ISBN: 12345
Book added successfully.

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 2
Enter Title: OOPVideo
Enter Author: john
Enter Due Date: 12-03-2026
Enter Duration (mins): 120
DVD added successfully.

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 3

Item Index: 0
[Book]
Title: CppBasics
Author: Bjarne
Due Date: 10-03-2026
ISBN: 12345

Item Index: 1
[DVD]
Title: OOPVideo
Author: john
Due Date: 12-03-2026
Duration: 120 mins

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 4
Enter Item Index: 0
Book checked out successfully.

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 5
Enter Item Index: 0
Book returned successfully.

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter Choice: 6
Exiting Program...

--------------------------------
Process exited after 213 seconds with return value 0
Press any key to continue . . .


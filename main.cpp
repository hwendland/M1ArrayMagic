#include <iostream>
#include <array>

using namespace std;

array<array<int,30>,30> get_static_array(){
    array<array<int,30>,30> statArray;
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            statArray[i][j] = rand() % 10;
        }
    }
    return statArray;
}

int **get_dynamic_array(){
    int **dynArray;
    dynArray = new int*[30];
    for (int i=0; i<30; i++) {
        dynArray[i] = new int[30];
    }
    return dynArray;
}

void print_array(array<array<int,30>,30> s) {
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
};

void print_array(int **d) {
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
};

void copy_to_dynamic(array<array<int,30>,30> s, int **d) {
    cout << "Static array: \n";
    print_array(s);
    for (size_t i=0; i<30; i++) {
        for (size_t j=0; j<30; j++) {
            d[i][j] = s[i][j];
        }
    }
    cout << "Dynamic array: \n";
    print_array(d);
}

void userCtrl() {
    bool isFilledD = false;
    bool isCreatedS = false;
    bool alive = true;
    array<array<int,30>,30> s = get_static_array();
    int **d = get_dynamic_array();
    while (alive) {
        string input;
        cout << "Enter a command. Your options are:\n"
             << "0: Create static array \n"
             << "1: Create dynamic array \n"
             << "2: Copy static to dynamic array \n"
             << "3: Print static array \n"
             << "4: Print dynamic array \n"
             << "5: Exit \n"
             << ">>>";
        cin >> input;
        try {
            int cmd = stoi(input);
            switch (cmd) {
                case 0: { s = get_static_array(); isCreatedS = true; break; }
                case 1: { d = get_dynamic_array(); isFilledD = false; break; }
                case 2: { copy_to_dynamic(s, d); isFilledD = true; break; }
                case 3: {
                    if (isCreatedS) print_array(s);
                    else {cout << "You need to create the array first. \n";}
                    break;
                }
                case 4: {
                    if (isFilledD) print_array(s);
                    else cout << "You either need to create and fill the array first. \n";
                    break;
                }
                case 5: {alive = false; break;}
                default: cout << "Try again \n";
            }
        } catch (exception) {
            cout << "Invalid command. \n";
        }
    }
}

int main()
{
    userCtrl();
    return 0;
}

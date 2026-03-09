#include <iostream>
#include <string>
using namespace std;

void chkNum(string comm) {
    int ok = 1;

    for (int i = 0; i < comm.length(); i++) {
        if (!(comm[i] >= 48 && comm[i] <= 57)) {
            ok = 0;
            break;
        }
    }
    if (ok == 1)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric Constant" << endl;
}

void chkOp(string comm) {
    int count = 0;

    for (int i = 0; i < comm.length(); i++) {
        if (comm[i] == '+' || comm[i] == '-' || comm[i] == '*' || comm[i] == '/' || comm[i] == '%' || comm[i] == '=') {
            count++;
            cout << "operator" << count << ": " << comm[i] << endl;
        }
    }

    if (count == 0)
        cout << "No operator found" << endl;
}

void chkCmnt(string comm) {
    if (comm[0] == '/' && comm[1] == '/')
        cout << "Single line comment" << endl;
    else if (comm[0] == '/' && comm[1] == '*')
        cout << "Multiple line comment" << endl;
    else
        cout << "Not a comment" << endl;
}

void chkId(string comm) {
    if (!((comm[0] >= 65 && comm[0] <= 90) || (comm[0] >= 97 && comm[0] <= 122) || comm[0] == 95)) {
        cout << "Not an identifier" << endl;
        return;
    }

    for (int i = 1; i < comm.length(); i++) {
        if (!((comm[i] >= 65 && comm[i] <= 90) || (comm[i] >= 97 && comm[i] <= 122) || (comm[i] >= 48 && comm[i] <= 57) || comm[i] == 95)) {
            cout << "Not an identifier" << endl;
            return;
        }
    }
    cout << "Valid identifier" << endl;
}

int main() {
    string input;
    cout << "Enter input to check numeric: ";
    cin >> input;
    chkNum(input);

    string opr;
    cout << "Enter input to check operator: ";
    cin >> opr;
    chkOp(opr);

    string cmnt;
    cout << "Enter input to check comment: ";
    cin >> cmnt;
    chkCmnt(cmnt);

    string id;
    cout << "Enter input to check identifier: ";
    cin >> id;
    chkId(id);

    return 0;
}

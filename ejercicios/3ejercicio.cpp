#include <iostream>
#include <string>

using namespace std;

int zeller(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13*(month+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return h;
}

int main() {
    int year, month, day;
    cout << "Ingrese la fecha en formato AAAA MM DD separada por espacios: ";
    cin >> year >> month >> day;
    
    string dias[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};
    int dia_semana = zeller(year, month, day);
    cout << "El " << year << "/" << month << "/" << day << " fue " << dias[dia_semana] << endl;

    // Calcular el número de días transcurridos hasta el presente
    int days_since_epoch = 0;
    for (int y = 1970; y < year; y++) {
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            days_since_epoch += 366;
        } else {
            days_since_epoch += 365;
        }
    }
    for (int m = 1; m < month; m++) {
        if (m == 2) {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                days_since_epoch += 29;
            } else {
                days_since_epoch += 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            days_since_epoch += 30;
        } else {
            days_since_epoch += 31;
        }
    }
    days_since_epoch += day - 1;
    cout << "Han transcurrido " << days_since_epoch << " días desde el 1 de enero de 1970 hasta esa fecha." << endl;

    return 0;
}

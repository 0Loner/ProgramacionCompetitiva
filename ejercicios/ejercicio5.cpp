#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a) {
        dia = d;
        mes = m;
        anio = a;
    }
};

bool compararFechas(const Fecha& f1, const Fecha& f2) {
    if (f1.mes != f2.mes) {
        return f1.mes < f2.mes;
    }
    else if (f1.dia != f2.dia) {
        return f1.dia < f2.dia;
    }
    else {
        time_t t1 = time(NULL);
        struct tm* tm1 = localtime(&t1);
        tm1->tm_year = f1.anio - 1900;
        tm1->tm_mon = f1.mes - 1;
        tm1->tm_mday = f1.dia;
        tm1->tm_hour = 0;
        tm1->tm_min = 0;
        tm1->tm_sec = 0;
        tm1->tm_isdst = -1;
        time_t t2 = time(NULL);
        struct tm* tm2 = localtime(&t2);
        tm2->tm_year = f2.anio - 1900;
        tm2->tm_mon = f2.mes - 1;
        tm2->tm_mday = f2.dia;
        tm2->tm_hour = 0;
        tm2->tm_min = 0;
        tm2->tm_sec = 0;
        tm2->tm_isdst = -1;
        return difftime(mktime(tm1), mktime(tm2)) < 0;
    }
}

int main() {
    vector<Fecha> fechas;
    fechas.push_back(Fecha(23, 3, 1990));
    fechas.push_back(Fecha(1, 1, 1995));
    fechas.push_back(Fecha(10, 4, 1985));
    fechas.push_back(Fecha(15, 1, 1990));

    sort(fechas.begin(), fechas.end(), compararFechas);

    for (int i = 0; i < fechas.size(); i++) {
        cout << fechas[i].dia << "/" << fechas[i].mes << "/" << fechas[i].anio << endl;
    }

    return 0;
}

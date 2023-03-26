#include <iostream>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <algorithm>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <vector>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <ctime>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

using namespace std;//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

struct Fecha {//O(1)
    int dia;//O(1)
    int mes;//O(1)
    int anio;//O(1)

    Fecha(int d, int m, int a) {//O(1)
        dia = d;//O(1)
        mes = m;//O(1)
        anio = a;//O(1)
    }
};

bool compararFechas(const Fecha& f1, const Fecha& f2) {
    if (f1.mes != f2.mes) {//O(1)
        return f1.mes < f2.mes;//O(1)
    }
    else if (f1.dia != f2.dia) {//O(1)
        return f1.dia < f2.dia;//O(1)
    }
    else {//O(1)
        time_t t1 = time(NULL);//O(1)
        struct tm* tm1 = localtime(&t1);//O(1)
        tm1->tm_year = f1.anio - 1900;//O(1)
        tm1->tm_mon = f1.mes - 1;//O(1)
        tm1->tm_mday = f1.dia;//O(1)
        tm1->tm_hour = 0;//O(1)
        tm1->tm_min = 0;//O(1)
        tm1->tm_sec = 0;//O(1)
        tm1->tm_isdst = -1;//O(1)
        time_t t2 = time(NULL);
        struct tm* tm2 = localtime(&t2);
        tm2->tm_year = f2.anio - 1900;//O(1)
        tm2->tm_mon = f2.mes - 1;//O(1)
        tm2->tm_mday = f2.dia;//O(1)
        tm2->tm_hour = 0;//O(1)
        tm2->tm_min = 0;//O(1)
        tm2->tm_sec = 0;//O(1)
        tm2->tm_isdst = -1;//O(1)
        return difftime(mktime(tm1), mktime(tm2)) < 0;//la función "difftime" tiene una complejidad constante de O(1),la función "mktime" tiene una complejidad lineal de O(1) 
    }
}

int main() {
    vector<Fecha> fechas;//O(1)
    fechas.push_back(Fecha(23, 3, 1990));//O(1)
    fechas.push_back(Fecha(1, 1, 1995));//O(1)
    fechas.push_back(Fecha(10, 4, 1985));//O(1)
    fechas.push_back(Fecha(15, 1, 1990));//O(1)

    sort(fechas.begin(), fechas.end(), compararFechas);//O(N*log(N))

    for (int i = 0; i < fechas.size(); i++) {//O(1)
        cout << fechas[i].dia << "/" << fechas[i].mes << "/" << fechas[i].anio << endl;//O(1)
    }
    //ecorren el vector y muestran sus elementos. Estas operaciones tienen complejidad O(N), donde N es el número de elementos en el vector.


    return 0;//O(1)
}
//En general, la complejidad de este programa es O(N*log(N)), donde N es el número de elementos en el vector de fechas.
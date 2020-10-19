/*
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 19-10-2020
 * Resumen: Programa interactivo que programa pide al usuario el día, mes y año de
 *          una fecha y escribe en la pantalla la fecha siguiente.
 */
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Conctante que almacena el año en el que se instauró el calendario gregoriano
 * en España.
 */
const int AGNO_INICIO_GREGORIANO = 1582;

/*
 * Pre:  agno > 1582
 * Post: Ha devuelto true si y solo si el año «agno» es bisiesto de acuerdo con
 *       las reglas del calendario gregoriano.
 * Nota: Código de la clase de problemas sobre composición condicional. En el
 *       tema 7 (diseño modular), ser verá cómo reutilizar código sin necesidad de
 *       copiarlo.
 */
bool esBisiesto(unsigned int agno) {
    bool multiplo4   = (agno %   4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}

/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Ha devuelto el número de días que tiene el mes establecido por el  
 *       parámetro «mes» del año establecido por el parámetro «agno».
 *
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 *
 * Nota: Código del primer problema. En el tema 7 (diseño modular), ser verá cómo
 *       reutilizar código sin necesidad de copiarlo.
 */
unsigned int diasDelMes(unsigned int mes, unsigned int agno) {
    if (mes == 2) {
        // Febrero: el número de día depende del año
        if (esBisiesto(agno)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        // Abril, junio, septiembre o noviembre
        return 30;
    }
    else {
        // Resto de meses
        return 31;
    }
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12, agno > 1582 y la fecha formada por
 *       «dia», «mes» y «agno» representan una fecha válida del calendario
 *       gregoriano.
 * Post: Tras la ejecución de la función, los parámetros «fecha», «dia», «mes» y
 *       «agno» representan la fecha correspondiente al día siguiente al que
 *       representaban al iniciarse la ejecución de la función.
 * 
 *       Por ejemplo, si d, m y a son variables de tipo entero y d = 17, m = 10 y
 *       a = 2019, tras la invocación diaSiguiente(d, m, a) los valores de las
 *       variables serían d = 18, m = 10 y a = 2019.
 *       Si los valores fueran d = 29, m = 2 y a = 2020, tras la invocación
 *       diaSiguiente(d, m, a) los valores serían d = 1, m = 3 y a = 2020.
 *       Si los valores fueran d = 31, m = 12 y a = 2022, tras la invocación
 *       diaSiguiente(d, m, a) los valores serían d = 1, m = 1 y a = 2023.
 */
void diaSiguiente(unsigned int& dia, unsigned int& mes, unsigned int& agno) {
    dia++;
    if (dia > diasDelMes(mes, agno)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            agno++;
        }
    }
}


/*
 * Programa que pide al usuario el día, mes y año de una fecha y escribe en la
 * pantalla la fecha correspondiente al día siguiente.
 */
int main() {    
    cout << "Escriba el día, mes y año de una fecha: ";
    unsigned int dia, mes, agno;
    cin >> dia >> mes >> agno;
    
    if (mes < 1 || mes > 12) {
        // Mes incorrecto
        cout << "El mes tiene que estar comprendido entre 1 y 12." << endl;
        return 1;
    }
    else if (agno <= AGNO_INICIO_GREGORIANO) {
        // Año incorrecto
        cout << "El año tiene que ser posterior a " 
             << AGNO_INICIO_GREGORIANO << "." << endl;
        return 1;
    }
    else if (dia < 1 || dia > diasDelMes(mes, agno)) {
        // Día incorrecto
        cout << "El día tiene que estar comprendido entre 1 y el final del mes."
             << endl;
        return 1;
    }
    else {
        // Día, mes y año correctos
        diaSiguiente(dia, mes, agno);
        
        cout << "El día siguiente es " << setfill('0')
             << setw(2) << dia << "/"
             << setw(2) << mes << "/"
             << agno << endl;
             
        return 0;
    }
}
/*
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 16-10-2019
 * Resumen: Programa interactivo que programa pide al usuario el día, mes y año de
 *          una fecha y escribe en la pantalla la fecha siguiente.
 *          Versión para el grupo 411 (mañanas).
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
bool esBisiesto(int agno) {
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
int diasDelMes(int mes, int agno) {
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
 * Post: Ha devuelto la fecha correspondiente al día posterior a la fecha
 *       representada por el valor de los parámetros «dia», «mes» y «agno»
 *       codificada con el mismo formato «aaaammdd» utilizado en la práctica 2ª,
 *       donde los dígitos «aaaa» representan el año, los dígitos «mm», el mes y los
 *       dígitos «dd» el día.
 *
 *       Por ejemplo: 
 *          diaSiguiente(17, 10, 2019) devuelve 20191018
 *          diaSiguiente(29, 2, 2020) devuelve 20200301
 *          diaSiguiente(31, 12, 2022) devuelve 20230101
 */
int diaSiguiente(int dia, int mes, int agno) {
    dia++;
    if (dia > diasDelMes(mes, agno)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            agno++;
        }
    }
    return agno * 10000 + mes * 100 + dia;
}


/*
 * Programa que pide al usuario el día, mes y año de una fecha y escribe en la
 * pantalla la fecha correspondiente al día siguiente.
 */
int main() {    
    cout << "Escriba el día, mes y año de una fecha: ";
    int dia, mes, agno;
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
        int fecha = diaSiguiente(dia, mes, agno);
        
        int diaSiguiente = fecha % 100;
        int mesDiaSiguiente = fecha / 100 % 100;
        int agnoDiaSiguiente = fecha / 10000;
        
        cout << "El día siguiente es " << setfill('0')
             << setw(2) << diaSiguiente << "/"
             << setw(2) << mesDiaSiguiente << "/"
             << agnoDiaSiguiente << endl;
             
        return 0;
    }
}
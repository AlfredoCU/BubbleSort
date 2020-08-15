#include <iostream>
#include <ctime>

using namespace std;

/*
 * Funcion que imprime el array.
 */
void printArray(int arrayN[], int n) {
    cout << "[";
    for(int i = 0; i < n ; i ++) {
        if(i < n - 1) {
            cout << arrayN[i] << ", ";
        } else {
            cout << arrayN[i];
        }
    }
    cout << "]" << endl;
}

/*
 * Funcion para intercambiar los valores.
 */
void swapArray(int *a, int *b) { // *a -> Declaracion de punteros.
    int temp;
    temp = *a; // *a -> Desreferencia.
    *a = *b;
    *b = temp;
    /*
     * cout << temp << endl; // Numero.
     * cout << a << endl; // Direcion de memoria.
     * cout << *a << endl; // Numero.
     */
}

/*
 * Funcion burbuja.
 */
void bubble(int arrayN[], int n) {
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arrayN[j] > arrayN[j + 1]) {
                swapArray(&arrayN[j], &arrayN[j + 1]); // &array[j] -> Direccion de.
            }
        }
    }
}

/*
 * Funcion burbuja mejorada.
 */
void bubbleBest(int arrayN[], int n) {
    bool flag;
    int i = n - 1;

    do {
        flag = false;
        for(int j = 0; j < i; j++) {
            if(arrayN[j] > arrayN[j + 1]) {
                swapArray(&arrayN[j], &arrayN[j + 1]);
                flag = true;
            }
        }
        --i;
    } while(flag);
}

/*
 * Funcion principal.
 */
int main() {
    srand(time(0));
    int arrayNum[10];
    int length = (sizeof(arrayNum)/sizeof(*arrayNum));

    for(int i = 0; i < length; i++) {
        arrayNum[i] = 1 + rand() % 100;
    }

    cout << "Ordenamiento Burbuja" << endl << endl;
    cout << "- Longitud del array: " << length << endl;

    cout << "- El array original: ";
    printArray(arrayNum, length);

    // bubble(arrayNum, length);
    bubbleBest(arrayNum, length); // Burbuja Mejorada.

    cout << "- El array ordenado: ";
    printArray(arrayNum, length);

    return 0;
}

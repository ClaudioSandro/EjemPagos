#include "pch.h"
#include <iostream>
#include "Usuario.h"
//te funciono el git? si o no?
//sandro: si
//Francesco: si

using namespace std;
using namespace System;

int opcionesDeliver() {
    int op;
    cout << "Como desea recibir su pedido?" << endl;
    cout << "1. Delivery" << endl;
    cout << "2. Recojo en tienda" << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}

int opcionesPago() {
    int op;
    cout << "Cuando desea realizar el pago de su boleta?" << endl;
    cout << "1. Cancelar mediante la aplicacion (tarjeta)" << endl;
    cout << "2. Cancelar presencialmente" << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}
int tipoPago() {
    int op;
    cout << "Que metodo de pago usara?" << endl;
    cout << "1. Visa" << endl;
    cout << "2. MasterCard" << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}
void realizarPago(Usuario &x) {
    int o1 = opcionesDeliver();
    int op = opcionesPago();

    if (op == 1) { //Si desea pagar con tarjeta
        int tipoN = tipoPago();
        string tipo;
        switch (tipoN)
        {
        case 1: tipo = "Visa"; break;
        case 2: tipo = "MasterCard"; break;
        }
        
        if (x.pagar(tipo, x.getMetodo())) { //Llama al proceso de pago
            //Set boleta -> Estado de pago: Cancelada
            cout << "El pago de la boleta ha sido cancelada" << endl << endl;
        }
        else {
            //Set boleta -> Estado de pago: Sin Cancelar(rojo)
            cout << "El pago de la boleta sigue pendiente..." << endl << endl;
        }
        
    }
    else {
        //Set en la boleta -> Estado de pago: Se realizara durante entrega
        cout << "El pago se relizara de forma presencial..." << endl << endl;
    }
}
int main()
{
    Usuario juanito;
    //Llega el momento de pagar
    do {
        realizarPago(juanito);
    } while (true);

    return 0;
}

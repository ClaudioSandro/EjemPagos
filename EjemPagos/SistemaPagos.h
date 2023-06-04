#pragma once
#include "Recursos.h"
#include "Cliente.h"

class SistemaPagos {
    
public:

    void pagar(Cliente &x);
    void mostrarTarjeta(Cliente &x);
    void eliminarTarjeta(Cliente &x);

    bool pagoTarjeta(Cliente x);
    int menuPagos();
    int opcionesPago();
    int tipoPago();

};

void SistemaPagos::pagar(Cliente &x) {
    //Falta una seleccion de boleta

    int op = opcionesPago();

    if (op == 1) { //Si desea pagar con tarjeta
        bool repetir = pagoTarjeta(x);
        if (repetir) pagar(x);
    }
    else if (op == 2) {
        int op_entrega;
        cout << "Esta seguro que desea cancelar durante su entrega?" << endl << endl;
        cout << "1.Si, deseo pagar durante la entrega (presencial)" << endl;
        cout << "2.Volver" << endl << endl;
        cout << "Opcion: "; cin >> op_entrega; cout << endl;

        if (op_entrega == 1) {
            cout << "El pago se relizara durante la entrega... Presione Enter para continuar" << endl << endl;
            //Set en la boleta -> Estado de pago: Se realizara durante entrega
            cin.ignore(); cin.get();
            system("cls");
        }
        else {
            system("cls");
            pagar(x);
        }

    }
    else if (op == 3) {
        system("cls");
    }
}

void SistemaPagos::mostrarTarjeta(Cliente &x) {
    tarjeta aux = x.getMetodo();
    if (aux.empresa == " ") {
        int op;
        cout << "No existe ninguna tarjeta guardada ... Desea ingresar una nueva tarjeta? " << endl << endl;
        cout << "1. Si, deseo ingresar una nueva tarjeta" << endl;
        cout << "2. No, volver al sistema de pagos. " << endl << endl;
        cout << "Opcion: "; cin >> op;

        system("cls");
        if (op == 1) x.nuevaTarjeta();
    }
    else {
        x.mostrarTarjeta();
        //Pausar el programa hasta que se presione enter
        cout << "Presione Enter para volver...";
        cin.ignore(); cin.get();
        system("cls");
    }

}

void SistemaPagos::eliminarTarjeta(Cliente &x) {
    tarjeta aux = x.getMetodo();

    if (aux.empresa == " ") {
        cout << "TARJETA DE LA CUENTA" << endl << endl;
        cout << "No existe tarjeta guardada en esta cuenta...";
        cout << "Presione Enter para volver...";
        cin.ignore(); cin.get();
        system("cls");
    }
    else {
        x.mostrarTarjeta();
        int op;
        cout << "Esta seguro que desea eliminar esta tarjeta?" << endl << endl;
        cout << "1.Si, deseo eliminar esta tarjeta" << endl;
        cout << "2.No, volver al sistema de pagos" << endl << endl;
        cout << "Opcion: "; cin >> op; cout << endl;

        if (op == 1) {
            aux.codigo = " "; aux.empresa = " "; aux.numero = " "; aux.titular = " ";
            x.setMetodo(aux);
            cout << "La tarjeta de la cuenta ha sido eliminada... Presione Enter para continuar...";
            cin.ignore(); cin.get();
        }
        system("cls");
    }
}

bool SistemaPagos::pagoTarjeta(Cliente x) {
    int tipoN = tipoPago();
    string tipo;

    switch (tipoN)
    {
    case 1: tipo = "Visa"; break;
    case 2: tipo = "MasterCard"; break;
    case 3: tipo = "AmericanExpress"; break;
    case 4: tipo = "DinersClub"; break;
    case 5: system("cls"); return true;
    }
    if (x.pagar(tipo, x.getMetodo())) { //Llama al proceso de pago
        //Set boleta -> Estado de pago: Cancelada
        return false;

    }
    else {
        //Set boleta -> Estado de pago: Sin Cancelar(rojo)
        pagoTarjeta(x);
    }
}

int SistemaPagos::menuPagos() {
    int op;

    cout << "BIENVENIDO AL SISTEMA DE PAGOS" << endl << endl;

    cout << "1.Pagar una boleta " << endl;
    cout << "2.Mostrar informacion de tarjeta de la cuenta " << endl;
    cout << "3.Ingresar nueva tarjeta " << endl;
    cout << "4.Eliminar tarjeta guardada " << endl;
    cout << "5.Volver " << endl << endl;

    cout << "Opcion: "; cin >> op;
    system("cls");
    return op;
}

int SistemaPagos::opcionesPago() {
    int op;
    cout << "Como desea realizar el pago de su boleta?" << endl << endl;
    cout << "1. Cancelar mediante la aplicacion (tarjeta)" << endl;
    cout << "2. Cancelar durante la entrega (presencial)" << endl;
    cout << "3. Volver" << endl << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    system("cls");
    return op;
}

int SistemaPagos::tipoPago() {
    int op;
    cout << "Que metodo de pago usara?" << endl << endl;
    cout << "1. Visa" << endl;
    cout << "2. MasterCard" << endl;
    cout << "3. AmericanExpress" << endl;
    cout << "4. DinersClub" << endl;
    cout << "5. Volver" << endl << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}
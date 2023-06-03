#pragma once
#include "Cliente.h"

class Sesion {

private:
	Cliente usuarioCliente;
	//Trabajador usuarioTrabajador
public:

    //principales
	void iniciarSesion();
    void pagar();

    //Apoyo
    int opcionesPago();
    int tipoPago();
	
};

void Sesion::iniciarSesion() {

	string tipo; 
	tipo = "Cliente"; //Este dato se obtiene del proceso de login

	if (tipo == "Cliente") {
		//Pasar los datos de usuario cliente
	}
	if (tipo == "Trabajador") {
		//Pasar los datos de usuario trabajador
	}
}

void Sesion::pagar() {
    int op = opcionesPago();

    if (op == 1) { //Si desea pagar con tarjeta
        int tipoN = tipoPago();
        string tipo;
        switch (tipoN)
        {
        case 1: tipo = "Visa"; break;
        case 2: tipo = "MasterCard"; break;
        case 3: tipo = "AmericanExpress"; break;
        case 4: tipo = "DinersClub"; break;
        }

        if (usuarioCliente.pagar(tipo, usuarioCliente.getMetodo())) { //Llama al proceso de pago
            //Set boleta -> Estado de pago: Cancelada
            
            
        }
        else {
            //Set boleta -> Estado de pago: Sin Cancelar(rojo)
            
        }

    }
    else {
        //Set en la boleta -> Estado de pago: Se realizara durante entrega
        cout << "El pago se relizara de forma presencial..." << endl << endl;
    }
}

int Sesion::tipoPago() {
    int op;
    cout << "Que metodo de pago usara?" << endl;
    cout << "1. Visa" << endl;
    cout << "2. MasterCard" << endl;
    cout << "3. AmericanExpress" << endl;
    cout << "4. DinersClub" << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}

int Sesion::opcionesPago() {
    int op;
    cout << "Cuando desea realizar el pago de su boleta?" << endl;
    cout << "1. Cancelar mediante la aplicacion (tarjeta)" << endl;
    cout << "2. Cancelar presencialmente" << endl;
    cout << "Opcion: "; cin >> op; cout << endl;
    return op;
}
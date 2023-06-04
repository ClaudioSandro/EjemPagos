#pragma once
#include "MenuOpciones.h"
#include "SistemaPagos.h"

class Sesion {

private:
    MenuOpciones menu;
	Cliente usuarioCliente;
	//Trabajador usuarioTrabajador

    string tipoCuenta = "Cliente";
public:

    //get-set
    string getTipoCuenta() { return tipoCuenta; }
    void setTipoCuenta(string _tipoCuenta) { tipoCuenta = _tipoCuenta; }

    //principales
	void iniciarSesion();
    void menuPrincipal();
    void sistemaPagos();

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

void Sesion::menuPrincipal() {

    string tipoCuenta = getTipoCuenta(); //Esto se obtiene del sistema de validacion de cuenta
  
    if (tipoCuenta == "Cliente") {
        int op = menu.mostrarMenu("Cliente");
        system("cls");
        switch (op) {
        case 3: sistemaPagos(); break;
        case 4: exit(0);
        }
    }

    //Lo mismo para trabajador
}

void Sesion::sistemaPagos() {
    SistemaPagos pagos;
    bool continuar = true;

    do {
        int op = pagos.menuPagos();
        switch (op)
        {
        case 1:pagos.pagar(usuarioCliente); break;
        case 2:pagos.mostrarTarjeta(usuarioCliente); break;
        case 3:usuarioCliente.nuevaTarjeta(); break;
        case 4:pagos.eliminarTarjeta(usuarioCliente); break;
        case 5:continuar = false;  break;
        }
    } while (continuar);
}


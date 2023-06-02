#pragma once
#include "Recursos.h"
#include "Cuenta.h"

class Usuario {
private:
	tarjeta metodo;

public:
	Usuario() { metodo.codigo = " "; metodo.numero = " "; metodo.titular = " "; metodo.empresa = " "; }

	tarjeta getMetodo() { return metodo; }
	void setMetodo(tarjeta _metodo) { metodo = _metodo; }

	bool pagar(string tipo, tarjeta tar);
};

bool Usuario::pagar(string tipo, tarjeta tar) {
	Cuenta cuenta;
	tarjeta aux;
	aux = cuenta.pagar(tipo, tar); //Hace el pago y devuelve una tarjeta nueva o la predeterminada dependiendo si quiere guardar
	setMetodo(aux); //Por si devuelve una nueva la reescribe
	return (cuenta.getPagoRealizado()); //devuelvetrue si se concreta el pago
}
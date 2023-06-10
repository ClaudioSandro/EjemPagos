#pragma once
#include "Recursos.h"
#include "CuentaBancaria.h"

class Cliente : public Usuario {
private:

	tarjeta metodo;

public:
	Cliente() { metodo.codigo = " "; metodo.numero = " "; metodo.titular = " "; metodo.empresa = " "; metodo.vencimiento = " "; }

	tarjeta getMetodo() { return metodo; }
	void setMetodo(tarjeta _metodo) { metodo = _metodo; }

	bool pagar(string tipo, tarjeta tar);
	void mostrarTarjeta();
	void nuevaTarjeta();
};

bool Cliente::pagar(string tipo, tarjeta tar) {
	CuentaBancaria cuenta;
	tarjeta aux;
	aux = cuenta.pagar(tipo, tar); //Hace el pago y devuelve una tarjeta nueva o la predeterminada dependiendo si quiere guardar
	setMetodo(aux); //Por si devuelve una nueva la reescribe
	return (cuenta.getPagoRealizado()); //devuelvetrue si se concreta el pago
}

void Cliente::mostrarTarjeta() {
	CuentaBancaria cuenta;
	
	cuenta.mostrarTarjeta(metodo);
};

void Cliente::nuevaTarjeta() {
	CuentaBancaria cuenta;
	tarjeta aux = cuenta.nuevaTarjeta();
	tarjeta guardada = cuenta.guardarTarjeta(aux, metodo);
	setMetodo(guardada);
	
}
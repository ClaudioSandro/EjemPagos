#pragma once
#include "Recursos.h"
#include "MetodoPagos.h"
#include "Usuario.h"


class CuentaBancaria {
private:
	bool pagoRealizado = false;
public:
	void setPagoCompletado(bool _pagoRealizado) { pagoRealizado = _pagoRealizado; }
	bool getPagoRealizado() { return pagoRealizado; }

	int opcionPago(tarjeta metodo);
	tarjeta ingresarDatos(string tipo, tarjeta metodo);
	void mostrarTarjeta(tarjeta metodo);

	tarjeta pagar(string tipo, tarjeta metodo);
};

void CuentaBancaria::mostrarTarjeta(tarjeta metodo) {

	cout << "Tipo: " << metodo.empresa << endl;
	cout << "Numero de Tarjeta: " << metodo.numero << endl;
	cout << "Titular: " << metodo.titular << endl;
	cout << "Codigo: " << metodo.codigo << endl;
	cout << endl;

}

tarjeta CuentaBancaria::ingresarDatos(string tipo, tarjeta metodo) {
	tarjeta aux;
	MetodoPagos pago;
	
	int op;
	int op_metodo;

	//Obtener datos de nueva tarjeta en aux

	cout << "Ingresar nueva tarjeta: " << endl << endl;

	cout << "1.Visa" << endl;
	cout << "2.MasterCard" << endl << endl;

	cout << "Seleccione el tipo de la tarjeta: "; cin >> op_metodo; cout << endl;
	switch (op_metodo)
	{
	case 1: aux.empresa = "Visa"; break;
	case 2: aux.empresa = "MasterCard"; break;
	}

	cout << "Tipo: " << aux.empresa << endl;
	cout << "Numero de Tarjeta: "; cin >> aux.numero;
	cout << "Titular: "; cin >> aux.titular;
	cout << "Codigo: "; cin >> aux.codigo;
	cout << endl;

	//Proceso de guardar tarjeta en cuenta 

	cout << "Desea guardar la tarjeta? Si(1) No(2): "; cin >> op;

	if (op == 1) {

		cout << "Se guardaron los datos correctamente" << endl << endl;
		if (pago.validar(tipo, aux)) setPagoCompletado(true); //Si la validacion devuelve true entonces marca que el pago se realizo
		return aux; // Si desea guardar la tarjeta devuelve los datos de la tarjeta ingresada
	}
	else {
		cout << "No se guardaron datos de la tarjeta..." << endl << endl;
		if (pago.validar(tipo, aux)) setPagoCompletado(true); //Si la validacion devuelve true entonces marca que el pago se realizo
		return metodo; //Caso contrario devuelve la predeterminada
	}

		
	
};

int CuentaBancaria::opcionPago(tarjeta metodo) {
	int op;
	cout << "Desea usar la tarjeta guardada en su cuenta? Si(1) No(2)"; cin >> op; cout << endl;
	if (op == 1 && metodo.empresa == " ") { //Si no hay tarjeta guardada
		cout << "No existe tarjeta guardada... Redireccionado a ingreso de tarjeta..." << endl << endl;
		return 2; // Devuelve como si quisiera usar la guardada
	}
	else if (op == 2) { //Si no quiere usar tarjeta guardada
		return 2;
	}else
		return 1; // Si quiere usar tarjeta guardada
	
}

tarjeta CuentaBancaria::pagar(string tipo, tarjeta metodo) {
	
	tarjeta aux;

	int op = opcionPago(metodo); //Seleccion tarjeta guardada?

	if (op == 2) { //Si no se desea usar tarjeta guardada o no existe tarjeta guardada
		aux = ingresarDatos(tipo, metodo); //Obtener datos de nueva tarjeta
		return aux;
	}
	else { //Si se deseas usar tarjeta guardada
		MetodoPagos pago;
		mostrarTarjeta(metodo);
		if (pago.validar(tipo, metodo)) setPagoCompletado(true);
		return metodo;
		
	}
	
	
}
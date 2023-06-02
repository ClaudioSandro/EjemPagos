#pragma once
#include "Recursos.h"
#include "Tarjetas.h"

class MetodoPagos {

public:
	bool validar(string tipo, tarjeta x);
};

bool MetodoPagos::validar(string tipo, tarjeta x) {

	//Valida dependiendo del tipo de tarjeta

	if (tipo == "Visa") {
		Visa tarj;
		 return (tarj.validar(tipo, x));
	}
	if (tipo == "MasterCard") {
		MasterCard tarj;
		return (tarj.validar(tipo, x));
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void addServiceToGestor(gestor* gestor, servico* servico)
{
	addServicos(servico, gestor->listServicos);
}
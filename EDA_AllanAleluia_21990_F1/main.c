#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

	listServicos* listServico = makeServicosList();
	listUsers* listUser = makeUsersList();
	servico* servico = malloc(sizeof(servico));

	servico->id = 1;
	
	addServicos(servico, listServico);
	displayServicos(listServico);

	FILE* arquivo_servicos;

	arquivo_servicos = fopen("listaServicos.txt", "a");

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

/// <summary>
/// criação do método de estrutra do nó de serviço
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
servicoNode* createServicoNode(servico* data) {
	servicoNode* newNode = malloc(sizeof(servicoNode));
	if (!newNode) {
		return NULL;
	}
	newNode->servico = data;
	newNode->next = NULL;
	return newNode;
}

/// <summary>
/// método para criar lista de servicos
/// </summary>
/// <returns></returns>
listServicos* makeServicosList() {
	listServicos* list = malloc(sizeof(listServicos));
	if (!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

/// <summary>
/// metodo pra adicionar um servico a lista de servicos
/// </summary>
/// <param name="servico"></param>
/// <param name="list"></param>
void addServicos(servico* servico, listServicos* list)
{
	servicoNode* current = NULL;
	if (list->head == NULL) {
		list->head = createServicoNode(servico);
	}
	else {
		current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = createServicoNode(servico);
	}
}


/// <summary>
/// metodo para deletar um servico da lista
/// </summary>
/// <param name="servico_id"></param>
/// <param name="list"></param>
void deleteServico(int servico_id, listServicos* list) {
	servicoNode* current = list->head;
	servicoNode* previous = current;
	while (current != NULL) {
		if (current->servico->id == servico_id) {
			previous->next = current->next;
			if (current == list->head)
				list->head = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}
/// <summary>
/// metodo para imprimir a lista de servicos no console
/// </summary>
/// <param name="list"></param>
void displayServicos(listServicos* list) {
	servicoNode* current = list->head;
	if (list->head == NULL)
		return;

	for (; current != NULL; current = current->next) {
		printf("Servico ID: %d\n", current->servico->id);
	}
}

/// <summary>
/// salva o arquivo com o nome "listadeservicos" em ficheiro binário
/// </summary>
/// <param name="listadeservicos"></param>
/// <param name="h"></param>
/// <returns></returns>
bool ArmazenaListaBinario(char listadeservicos[], listServicos* h) {
	FILE* fp;
	if (h == NULL)
		return false;
	if ((fp = fopen(listadeservicos, "wb")) == NULL)
	{
		return false;
	}

	listServicos* current = h;
	while (current != NULL) {
		
		fwrite(&current->servico, sizeof(servico), 1, fp);
		current = current->next;
	}

	fclose(fp);
	return true;
}

/// <summary>
/// cria/altera um ficheiro para armazenamento das informacoes de servico
/// </summary>
/// <param name="h"></param>
/// <returns></returns>
bool PreservaInformacao(listServicos* h) {
	FILE* fp;
	if (h == NULL) {
		return false;
	}

	char fileName[] = "todososservicos.txt";  // Nome do arquivo a ser criado ou atualizado

	if ((fp = fopen(fileName, "w")) == NULL) {  // Abrir arquivo em modo escrita ("w")
		return false;
	}

	listServicos* current = h;
	while (current != NULL) {
		fprintf(fp, "%d %s %.2f\n", current->servico.id, current->servico.nome);
		current = current->next;
	}

	fclose(fp);
	return true;
}




#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/// <summary>
/// criação do método de estrutra do nó de usuario
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
userNode* createUserNode(user* data) {
	userNode* newNode = malloc(sizeof(userNode));
	if (!newNode) {
		return NULL;
	}
	newNode->user = data;
	newNode->next = NULL;
	return newNode;
}

/// <summary>
/// método para criar lista de usuarios
/// </summary>
/// <returns></returns>
listUsers* makeUsersList() {
	listUsers* list = malloc(sizeof(listUsers));
	if (!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

/// <summary>
/// metodo pra adicionar um user a lista de usuarios
/// </summary>
/// <param name="user"></param>
/// <param name="list"></param>
void addUsers(user* user, listUsers* list)
{
	userNode* current = NULL;
	if (list->head == NULL) {
		list->head = createUserNode(user);
	}
	else {
		current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = createUserNode(user);
	}
}


/// <summary>
/// metodo para deletar um usuario da lista
/// </summary>
/// <param name="servico_id"></param>
/// <param name="list"></param>
void deleteUser(int user_id, listUsers* list) {
	userNode* current = list->head;
	userNode* previous = current;
	while (current != NULL) {
		if (current->user->id == user_id) {
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
/// metodo para imprimir a lista de usuarios no console
/// </summary>
/// <param name="list"></param>
void displayUsers(listUsers* list) {
	userNode* current = list->head;
	if (list->head == NULL)
		return;

	for (; current != NULL; current = current->next) {
		printf("User ID: %d\n", current->user->id);
	}
}
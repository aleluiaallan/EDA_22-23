#include <stddef.h>
#include <stdio.h>


#pragma region VEICULOS
/// <summary>
/// enum dos tipos de veiculos
/// </summary>
typedef enum _tipos {
	trotinete = 1,
	bicicleta = 2
}tipos;

/// <summary>
/// nó de um veiculo
/// </summary>
typedef struct _veiculoNode {
	veiculo* veiculo;
	struct _veiculoNode* next;
}veiculoNode;

/// <summary>
/// struc de veiculo
/// </summary>
typedef struct _veiculo {
	long id;
	tipos* tipos;
}veiculo;

/// <summary>
/// lista de veiculos
/// </summary>
typedef struct _listVeiculos {
	veiculoNode* head;
}listVeiculos;
#pragma endregion


#pragma region USUARIO

/// <summary>
/// struct de morada
/// </summary>
typedef struct _adress {
	char* rua;
	int cp;
}adress;

/// <summary>
/// struc de usuario
/// </summary>
typedef struct _user {
	long id;
	char* nome;
	int nif;
	double saldo;
	adress* adress;
}user;

/// <summary>
/// Nó que guarda o ponteiro para mesmo tipo de estrutra(um nó)
/// </summary>
typedef struct _userNode {
	user* user;
	struct _userNode* next;
}userNode;

/// <summary>
/// lista de users
/// </summary>
typedef struct _listUsers {
	userNode* head;
}listUsers;

/// <summary>
/// função para criar nós do usuario
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
userNode* createUserNode(user* data);

/// <summary>
/// função para criar lista de usuarios
/// </summary>
/// <returns></returns>
listUsers* makeUsersList();

#pragma endregion


#pragma region SERVICOS

/// <summary>
/// enums de categorias de servicos
/// </summary>
typedef enum _categorias {
	carregar = 1,
	consertar = 2
}categorias;

/// <summary>
/// struct de servico
/// </summary>
typedef struct _servico {
	long id;
	char* nome;
	categorias* categorias;
}servico;

/// <summary>
/// struct do nó da lista de servico
/// </summary>
typedef struct _servicoNode {
	servico* servico;
	struct _servicoNode* next;
}servicoNode;

/// <summary>
/// nó de inicio da lista de servicos 
/// </summary>
typedef struct _listServicos {
	servicoNode* head;
}listServicos;

/// <summary>
/// proximo nó da lista de servicos
/// </summary>
typedef struct _listServicos {
	servico servico;
	struct servicoNode* next;
}listServicos;

/// <summary>
/// armazenamento da lista em ficheiro binário
/// </summary>
/// <param name="listadeservicos"></param>
/// <param name="h"></param>
/// <returns></returns>
bool ArmazenaListaBinario(char listadeservicos[], listServicos* h);

/// <summary>
/// cria/altera um ficheiro para armazenamento das informacoes de servico
/// </summary>
/// <param name="h"></param>
/// <returns></returns>
bool PreservaInformacao(listServicos* h);

/// imprime todas os serviços
void displayServicos(listServicos* list);

/// <summary>
/// Adicona um servico a um gestor
/// </summary>
/// <param name="gestor"></param>
/// <param name="servico"></param>
void addServiceToGestor(gestor* gestor, servico* servico);

/// <summary>
/// cria lista de servicos
/// </summary>
/// <returns></returns>
listServicos* makeServicosList();

/// <summary>
/// cria no na lista de servicos
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
servicoNode* createServicoNode(servico* data);

/// <summary>
/// adiciona um servico a lsita de servicos
/// </summary>
/// <param name="servico"></param>
/// <param name="list"></param>
void addServicos(servico* servico, listServicos* list);

/// <summary>
/// remove um servico da lista de servicos
/// </summary>
/// <param name="servico_id"></param>
/// <param name="list"></param>
void deleteServico(int servico_id, listServicos* list);

/// <summary>
/// Imprime uma lista de servicos
/// </summary>
/// <param name="list"></param>
void displayServicos(listServicos* list);

#pragma endregion


#pragma region GESTOR

/// <summary>
/// struc de um gestor
/// </summary>
typedef struct _gestor {
	long id;
	listServicos* listServicos;
}gestor;

/// <summary>
/// adicionar servicos a lista
/// </summary>
/// <param name="servico"></param>
/// <param name="list"></param>
void addServicos(servico* servico, listServicos* list);


/// <summary>
/// /// Remover servicos da lista
/// </summary>
///  <param name="id"></param>
///  <param name="list"></param>
void removeServicos(long id, listServicos* list);

/// <summary>/// /// </summary>/// <param name="id"></param>/// <param name="list"></param>
void changeServicos(long id, listServicos* list);

#pragma endregion
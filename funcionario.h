typedef struct funcionario Funcionario;

// Função para criar um novo nó de funcionário
Funcionario* criarNo();

// Função para adicionar informações a um novo funcionário
void adicionarFuncionario(Funcionario *novoNode);

// Função para inserir um novo funcionário no final da lista
Funcionario* inserirNoFinal(Funcionario *Lista);

// Função para imprimir todos os funcionários na lista
void imprimirLista(Funcionario* Lista);

// Função para remover um funcionário da lista pela matrícula
Funcionario* removerFuncionario(Funcionario* Lista, int matricula);

// Função para buscar e imprimir os dados de um funcionário pela matrícula
void buscarFuncionario(Funcionario* Lista, int matricula);

**LINKED LISTS**
-  **Abstract Data Types**
	-  representado por uma classe
	-  a classe inclui variáveis e funções que operam os dados

-  **Listas**
	-  sequência de itens do mesmo tipo
	-  uma lista vazia não tem elementos
	-  existem algumas operações básicas que é possível fazer com listas
		-  criar uma lista nova, vazia
		-  adicionar e remover elementos da lista
		-  encontrar a posição de um elemento da lista
		-  encontrar a length da lista
		-  concatenar duas listas
		-  apagar/destruir a lista, se estivesse alocada dinamicamente

-  **Implementar Listas**
	-  Linked List
		-  guardam elementos do mesmo tipo, tal como um vetor ou um array, mas conseguem crescer e diminuair de tamanho de forma mais eficiente
		-  numa singly linked list, os valores são guardados em nós, bem como a referência para a o nó que contém o seguinte valor da lista
		-  numa doubly linked list, cada nó contém referência para o valor seguinte e para o valor anterior


**LINKED LISTS, STACKS, DEQUES, QUEUES**
-  Circular Doubly Linked-List
	-  é uma linked List onde cada nó está conectado ao nó anterior e ao nó seguinte, e o último nó está conectado ao primeiro

-  Stack ADT
	-  uma stack é uma coleção cujos elementos são adicionados e removidos de uma ponta, chamada o topo da stack
	-  existem algumas opções básicas que não criar e destruir: push, pop, top, size, empty
	-  não dá para fazer sort, normalmente


**recomendado fazer como estudo para o teste:**
-  method in a linked list
-  vamos ter de adicionar um método ao código da singlylinkedlist utilizado nas aulas
-  exercícios recomendados: 20, 21, 22, 23, 24, 25
-  resumo de cada um dos exercícios (o que fiz em cada um)
	-  no 20 o objetivo era criar um get position
		-  defini o node atual como sendo o primeiro
		-  fiz um ciclo for para ir até ao nó correspondente à posição dada como argumento
		-  depois retornei o valor do nó correspondente àquela posição
	-  no 21 o objetivo era saber quantas vezes um valor v se repetia numa lista
		-  defini o nó atual como o primeiro
		-  defini um counter
		-  fiz um ciclo while que não parava até que o valor atual fosse igual a nullptr
		-  dentro do ciclo, corri as posições uma a uma
		-  se o valor do nó atual fosse igual ao valor passado como argumento, incrementava ao counter e, no fim, retornei o counter
	-  no 22 o objetivo era remover o nó correspondente a uma determinada posição
		-  defini o nó atual como o primeiro
		-  determinei que valores dados como posição eram válidos
		-  se a posição fosse igual a 0, chamava a função removeFirst e se fosse igual a length - 1, chamava o removeLast
		-  no caso de não ser, desloco-me até à posição anterior à desejada, defino o nó seguinte como a vítima, movo-me para o nó seguinte ao que vai ser apagado, apago a vítima e decremento ao comprimento da lista
	-  no 23 o objetivo era inserir um valor v numa determinada posição
		-  determinei limites blá blá blá igual aos outros todos
		-  fui até à posição anterior à dada como argumento
		-  criei um novo nó que tinha o valor dado como argumento e referência ao nó seguinte
		-  defini o nó seguinte ao que eu estava como o nó que tinha acabado de criar
		-  incrementei ao comprimento da lista
	-  no 24 o objetivo era duplicar todos os elementos da lista
		-  defini o nó seguinte como tendo valor igual ao nó atual e referência ao nó seguinte
		-  incrementei no comprimento
		-  andei duas posições para a frente, até que o valor do nó atual fosse nullptr
	-  no 25 o objetivo era remover todos os nós que tivessem valor igual ao valor passado como argumento
		-  ir andando e verificando de nó em nó
		-  se o valor fosse igual, apagar, se não fosse seguir para o próximo nó
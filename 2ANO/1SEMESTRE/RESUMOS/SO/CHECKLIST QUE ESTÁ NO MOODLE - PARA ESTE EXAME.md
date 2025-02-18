**GESTÃO DE MEMÓRIA**

-  Hierarquia de memória e latência
	> - registos do cpu - latência na ordem dos nanossegundos
	> - caches (l1, l2, l3) - memórias de pequena dimensão presentes no CPU, com latências crescentes pela ordem que as escrevi
	> - RAM - maior capacidade, latência de centenas de nanossegundos
	> - discos - grande capacidade, mas muitos mais lentod que o resto (latências de milissegundos para HDD's e microssegundos para SSD's)

-  Localidade Espacial e Temporal
	> - localidade espacial diz que dados próximos no espaço, com endereços contíguos ou juntos, têm maior probabilidade de serem acessados em seguida
	> - localidade temporal diz que dados acessados recentemente têm maior probabilidade de serem acessados novamente a curto prazo

-  Estrutura do Espaço e Endereçamento de um Processo
	> - espaço de endereçamento - organização dos endereços a que um processo pode aceder
	> - este espaço está dividido em regiões (código, stack e heap, por exemplo)

-  Limites do Espaço de Endereçamento em arquiteturas de 32 e 64 bits
	> - em sistemas de 32 bits o espaço de endereçamento é limitado a 4GB = 2^32 
	> - em sistemas de 64 bits o espaço de endereçamento é teoricamente de 16EB = 2^64 = (2^32)^2, apesar de que em sistemas mais recentes se praticam limites mais baixos

-  Endereços virtuais e físicos
	> - endereço virtual é utilizado por todo o tipo de programas e traduzido pelo sistema para aceder a memória real
	> - endereço físico corresponde a uma localização específica na ram

-  Memory management unit (MMU)
	> - esta unidade é responsável pela tradução de endereços virtuais em endereços físicos para que o sistema possa aceder a memória real

-  Técnica de segmentação
	> - para que seja possível perceber este tipo de conceito, é necessário ter em conta alguns conceitos base:
	> 	- temos como segmento uma divisão de memória em partes lógicas (como código e dados, por exemplo)
	> 	- uma tabela de segmentos contém todo o tipo de informações sobre os segmentos existentes (tamanho, ínicio e fim, etc)
	> 	- a tradução de endereços virtuais para endereços físicos é feita através do offset presente no segmento
	> 	- é também importante a proteção de memória para verificar acessos e prevenir violações

-  Técnica de paginação
	> - tal como a técnica anterior, esta também acenta em certos conceitos base:
	> 	- uma página consiste num bloco fixo de dados na memória virtual
	> 	- uma moldura é o bloco correspondente à página na memória física
	> 	- existe uma tabela de páginas que associa as páginas virtuais à molduras
	> 	- é feita uma tradução de endereços virtuais através da divisão do segmento do endereço em número de página e offset
	> 	- a proteção de memória é feita com base num conjunto de regras de acesso destinado a cada página

-  Tradução de endereços com Translation Lookaside Buffer (TLB)
	> - este TLB é, de forma simples, cache que armazena traduções recentes de endereços virtuais para físicos
	> - o TLB é importante no que toca a performance de processos, visto que reduz a latência associada à consulta de tabelas de páginas

-  Fragmentação interna e externa
	> - fragmentação interna é o espaço desperdiçado dentro de uma alocação
	> - fragmentação externa é o espaço desperdiçado entre alocações (fora delas)

-  Vantagens e desvantagens de segmentação e paginação
	> - segmentação:
	> 	- é flexível e mapeia regiões lógicas, mas é suscetível a fragmentação externa
	> - paginação:
	> 	- elimina a fragmentação externa, mas esta vantagem pode levar a geração de fragmentação interna

-  Memória virtual como extensão de memória física
	> - a memória virtual utiliza o disco como complemento da ram para armazenar dados de forma temporária

-  Vantagens da utilização de memória virtual
	> - permite que programs excedam o tamanho da ram, devido ao que referi anteriormente e permite o isolamento de processos

-  Operação de Swapping
	> - swapping consiste na movimentação de dados entre RAM  e disco

-  Ficheiros e partições de swap
	> - os ficheiros de swap são arquivos de sistema usados para swapping
	> - partições de swap são partes do disco dedicadas a esta atividade

-  Algoritmos de substituição de páginas
	> - LRU (LEAST RECENTLY USED) - remove a página que não é usada há mais tempo
	> - LFU (LEAST FREQUENTLY USED) - remove a página que é acedida de forma menos frequente



**SISTEMAS DE FICHEIROS**

-  Armazenamento Persistente de Informação
	> - permite a conservação de dados após desligar o sistema
	> - implementado por meio de sistemas de ficheiros que organizam e gerem o acesso aos dados armazenados em dispositivos persistentes, como HDD's e SSD's

-  Partição de discos
	> - no Linux:
	> 	- utiliza ferramentas como fdisk, parted e gparted para criar e gerir partições
	> 	- as partições comuns incluem ext4 e swap
	> - no Windows:
	> 	- utiliza o gerenciador de disco para criar e gerir partições, frequentemente em NTFS ou FAT/exFAT
	> - em Dual Boot:
	> 	- sistema configurado para inicializar com diferentes sistemas operativos que requer, geralmente:
	> 		- uma partição para cada sistema operativo
	> 		- um gestor de arranque onde selecionamos o sistema operativo com o qual queremos arrancar

-  Exemplos de Sistemas de ficheiros
	> - windows - tem NTFS, FAT e exFAT
	> - linux - ext4, xfs, zfs, btrfs, ISO9660 (para mídias óticas)
	> - macOS - APFS (Apple File System)
	> - outros - jfs (Journaling File System)

-  Interoperabilidade entre Sistemas de Ficheiros
	> - capacidade de diferentes sistemas operativos acederem a sistemas de ficheiros uns dos outros
	> 	- por exemplo, o linux pode ler/escrever em NTFS com o driver ntfs-3g
	> - montagem - processo de tornar um sistema de ficheiros acessível; em linux, é feito com o comando mount

-  Estrutura de um sistema de ficheiros
	> - boot control block:
	> 	- contém informações sobre os kernels inicializáveis e os respetivos 'boot loaders'
	> - volume control block:
	> 	- gerencia o espaço utilizado e o mapa de blocos livres
	> - directory structure:
	> 	- organiza os ficheiros em uma estrutura como um grafo dirigido acíclico (DAG - directed aciclic graph)
	> 	- suporte a links duros e simbólicos

-  File control block (FCB)
	> - contém informações como o nome do ficheiro, localização dos blocos de dados e permissões e metadados
	> - no UNIX, é organizado em estruturas de dados DAG para operações eficientes como busca

-  Kernel e suporte a múltiplos sistemas de ficheiros
	> - interoperabilidade consiste no uso de sistemas como o Virtual File System (VFS) para abstrair as diferenças entre sistemas de ficheiros
	> - estruturas de dados podem ser divididas em duas partes:
	> 	- system-wide open file table (SWOFT) - mantém a informação global dos ficheiros abertos
	> 	- per-process open file table (PPOFT) - mantém a informação dos ficheiros abertos por cada processo

-  Design de estruturas de dados
	> - existem alguns fatores importantes a ter em conta:
	> 	- distribuição de tamanhos de ficheiros
	> 	- tipo de acesso predominante (sequencial ou aleatório)
	> - em unix, a frequência é de ficheiros pequenos e o acesso é sequencial

-  Mapas de blocos usados por ficheiros
	> - blocos contíguos, que são rápidos para leitura sequencial mas tem fragmentação
	> - listas de blocos, que apresentam boa flexibilidade mas a leitura aleatória pode ser lenta
	> - listas em array (FAT), que é usado em FAT/exFAT e é eficiente para ficheiros pequenos
	> - indexação direta (UNIX Inode), que usa ponteiros diretos, indiretos, duplamente indiretos e triplamente indiretos

-  Limites de sistemas de ficheiros
	> - o número máximo de ficheiros é determinado pelo tamanho da tabela de inodes ou entrada equivalente
	> - o tamanho máximo dos ficheiros é limitado pelo esquema de endereçamento (ex: número de blocos e tamanho do bloco)

 - Performance Relativa
	> - diferentes estruturas de dados apresentam vantagens dependendo do caso:
	> 	- contígua - rápida para grandes ficheiros
	> 	- FAT - eficiente para dispositivos pequenos e acesso simples
	> 	- Inode - flexível para ficheiros de tamanhos variados



**TESTE MODELO - ANO PASSADO**

1 - a - a tabela interrupt vector é usada, depois do kernel receber um interrupt, para determinar a função a ser executada em resposta ao tipo de interrupt recebido
2 - c - blocos contíguos permitem acessos muito rápidos
3 - a - listas ligadas evitam fragmentação externa mas ficam suscetíveis a fragmentação interna
4 - a - o programa usa o execvp para executar o comando passado como argumento na execução do programa; argv[1] especifica que tem de começar a ler o comando a partir da segunda posição do comando de execução e o argv + 1 faz com que se leia até ao fim do comando
5 - a - como usa LFU, é necessário registar o número de acessos à página para saber qual é a página menos usada e, se necessário, fechá-la
6 - c - a função wait não garante nenhuma ordem em específico, para o término dos child processes, portanto ele espera pelo fim desses processos filhos por uma ordem qualquer
7 - a - erros de implicit declaration para funções que estão definidas em outras bibliotecas, significam que falta adicionar um ficheiro de cabeçalho correspondente a essa biblioteca
8 - b - em listas ligadas de blocos estas listas associadas aos ficheiros são codificadas num array
9 - c - o for dá print da posição 0 até à posição 2 do comando que é usado para executar o programa
10 - c - spooling é um processo em UNIX que consiste em manter fluxos de I/O de todos os processos separados em buffers
11 - a - o TLB, na MMU, permite que só seja necessárioconsultar a tabela de páginas para tradução de um endereço virtual no primeiro acesso à página
12 - b - ao utilizarmos paginação não há fragmentação externa, mas ficam suscetíveis a fragmentação interna
13 - c - o void handler não chega a ser chamado, então quando começamos a correr o programa principal com a flag igual a 1, dá print do start, entra no ciclo while e dá print do doing e o ciclo pausa, dando print do done a seguir
14 - c - DMA (direct memory access)
15 - a - o malloc é usado para alocar espaço na memória; se é necessário guardar duas strings, o espaço necessário para as duas strings é o do tamanho das duas strings mais um para o apontador de memória
16 - b - quando um ficheiro é acedido pela primeira vez com um open, a sua informação é mantida pelo kernel na SWOFT e na PPOFT do processo que executou o open
17 - b - começamos com 1 processo; damos fork aparece um processo filho e ficamos com dois; dentro do ciclo for fazemos 2 forks; o primeiro vai duplicar os processos e ficamos com 4 e o segundo vai duplicar novamente o número de processos e ficamos com 8
18 - a - a MMU traduz endereços virtuais gerados pelo processo em execução no CPU
19 - c - a partição swap do disco não possui nenhum sistema de ficheiros e é usada apenas para suportar a memória virtual
20 - a - o apontador está no mesmo sítio mas o valor de ambos os processos é diferente, o que significa que ambos os processos possuem endereços físicos diferentes mas o mesmo endereço virtual
21 - pipe() - comunicação unidirecional entre processos
	 fork() - criação de um processo
	 signal() - comportamento face à receção de um sinal
	 exec() - substituição de um programa
	 socketpair() - comunicação bidirecional entre processos
	 wait() - sicronização de processos
	 open() - operação de I/O sobre um processo
23 - b - não existe nenhum comando que trate da comunicação entre processos
24 - b - como as páginas são de maior dimensão, não é preciso dar swap tantas vezes então diminui a frequência deste tipo de operações
25 - b - espaço de endereçamento 17 e offset 255; nº da página = endereço/tamanho da página; offset = endereço % tamanho
26 - b - como o inode nos permite ir diretamente aos ficheiros, a complexidade do acesso a blocos pequenos de ficheiros é O(1)

**EXAME DE 22/23**

1 - A e C, uma instância de b pode existir sem uma instância de a e b é parte de a

2 - d, atributos atómicos possuem um domínio que contém especificamente valores atómicos e o atributo contém apenas um único valor desse domínio

3 - a, tem a ver com converter modelos concetuais para atender a certas exigências (nada demais)

4 - e, generalização faz-se quando a subclasse é membro da superclasse

5 - d, num UML de classes, um atributo derivado afeta a redundância porque atrivutos derivados são sempre redundantes

6 - c e d, ao converter uma relação muitos para um de um modelo concetual para um modelo relacional, adicionamos uma relação adicional com uma key do lado do muitos para aumentar a extensibilidade e o rigor do esquema

7 - a e b, temos uma extensão de person para os atributos musician, staff e audience member; o mais correto a fazer 
é adicionar um atributo id a cada uma das classes e nas classes derivadas de person tornar o id numa chave estrangeira que aponta para person; em alternativa, podemos sempre apagar a classe person e as classes que derivavam dela herdam os seus atributos

8 - a e b, como a pessoa possui um carro, no caso de haver uma chave estrangeira esta ficará sempre em carro; no caso de serem apenas duas relações, a chave estrangeira fica em carro, tal como disse; se tiver três relações, interpretamos da parte de poder existir uma relação muitos para 1 de carros para pessoa e adicionamos uma relação extra para adicionar estabilidade, que vai ter chaves estrangeiras a apontar para pessoa e carro, pessoa e carro são as duas relações que ficam sem chaves estrangeiras

9 - a e c, para converter um UML para uma relação que tem em conta generalização, usamos NULLs e E/R style

10 - b e c, mapear uma relação ternária e as classes que estão associadas a ela vai resultar sempre em 4 relações e o resultado do mapeamento é afetado pela multiplicidade das relações

11 - c e d, uma tabela na forma normal de boyce codd não assegura dependency preservation e pode sofrer de deletion anomalies

12 - A, F, G, D, E, C, closures são fáceis de fazer, nada demais

13 - a e b, qualquer coisa que esteja na forma normal de boyce codd está na terceira forma normal, a outra é só uma regra, se a junção natural de duas relações dá uma terceira relação, então r1 e r2 fazem uma decomposição de r3

14 - b, precisamos de A e de B para chegar a H

15 - a, uma superchave mínima é sempre uma chave candidata, é essa a definição

16 - a, temos um numérico e não sabe,os os seus atributos, tanto pode ser integer ou numeric

17 - a, update cascade serve específicamente para alterações em chaves estrangeiras, update propagate é mais geral

18 - d, é necessário referenciar qual é a primary key de forma clara e a parte do product(id) também é bastante importante

19 - e, a chave primária não pode ser constituída por quaisquer atributos únicos

20 - d, todas são classes e a multiplicidade entre as duas classes referenciadas é efetivamente muitos para muitos

21 - d, não sei explicar, vai por instinto

22 - e, já percebi como se faz aquele símbolo esquisito significa select

23 - c, inner join ignora os tuplos que não são iguais em ambas as relações

24 - a, natural join simplesmente junta todos os elementos de ambas as relações

25 - b, ele seleciona as tabelas que quer manter na nova cena e dá apply das alterações que fez





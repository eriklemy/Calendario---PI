# Orientações de desenvolvimento 
- ENGENHARIA DE COMPUTAÇÃO
- PROGRAMAÇÃO IMPERATIVA
- Prof. Dr. Henri Frederico Eberspacher

Trabalho 2 - Calendário em linha de comando
----------------------------------------------------
O trabalho possui duas entregas:

1. Fazer upload do arquivo calendario.c com a implementação do trabalho de pesquisa e implementação de um programa para ser chamado em linha de comando para impressão do calendário.

2. A gravação de pequeno vídeo explicando o código-fonte e ilustrando a execução do programa com suas funcionalidades.

Deixar evidente com comentários logo no início do programa (antes de #define):
- os nomes dos estudantes que compõem a equipe (dupla ou máximo trio) ou do estudante, caso individual;
- o endereço para acessar o vídeo no YouTube (pode deixar o vídeo como não listado, mas precisa deixar como público)
Especificação:
----------------

O programa para imprimir (e eventualmente gravar) o calendario conforme foi chamado em linha de comando (terminal):

Opções de chamada (exemplos), são três formas de chamar o programa: <br>
> calendario             => mostra o calendario do mes corrente       <br>
> calendario m 10    => mostra o calendario de outubro do ano corrente, sendo m para month e 10 o numero  <br>
> calendario y 2004  =>  calendario do ano inteiro (todos os meses), sendo y para year e 2004 o numero    <br>

Exibição exemplo:
- Chamada: calendario
- Mostra: calendário do mes corrente do ano corrente, novembro de 2020 

<pre>
Novembro - 2020 
 D    S    T    Q    Q    S    S  
 1    2    3    4    5    6    7  
 8    9    10   11   12   13   14 
15   16    17   18   19   20   21 
22   23    24   25   26   27   28 
29   30 
</pre>

BONUS (nota a mais), salvar o calendario em arquivo txt, idem as chamadas de base, mas com f (de file) e nome do arquivo texto de saida, exemplos <br>
> calendario f cal.txt <br>
> calendario m 10 f cal.txt <br> 
> calendario y 2004 f cal.txt <br>

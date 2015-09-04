#include<stdio.h>
#include<locale.h>

/////////////////////////////////////////////////////////////////////////////
/*  Problema:
    ------------------------------------------------------------------------------
    Formar uma matriz 10x10;
    -> Usu�rio deve informar um n�mero de 0 a 50;
    -> Preencher toda a matriz com n�meros aleat�rios;
    -> Informar o numero de vezes que o N�mero Informado foi apresentado na matriz

        Autor: Davi Nunes "aka" Ilunne || Ilune
        Faculdade Anhanguera
        PoBRE :: Portal Brasileiro de RomHack e Emula��o
        http://www.romhackers.org/modules/smartsection/item.php?itemid=15


    =>  ADICIONALMENTE, vou adicionar um MENU com as op��es:
        1: Mostrar a Matriz com os valores
        2: Mostrar quantas vezes o valor aparece na matriz
        3: Mostrar a Matriz apenas com o valor escolhido em suas posi��es
*/

/*  O que este problema quer ensinar?
    :: Percorrer uma Matriz
        Ent�o Veja que � necess�rio uma repeti��o composta para essa tarefa
    :: Gerar Valores Aleat�rios
        N�o se prenda a um �nico m�todo, o c�u � o limite!
    :: Contar valores dentro de uma Matriz
        Precisa s� saber incrementar uma vari�vel
*/

///Algoritmo para resolver o Problema:
/*
    1 - Criar uma Matriz
    2 - Percorrer todos os campos da Matriz atribuindo a cada um deles, valor aleat�rio
    3 - Pedir um Valor ao Usu�rio
    4 - Percorrer a Matriz, de novo, para comparar cada campo com o valor informado pelo usuario e contar quantos s�o
    5 - Mostrar pro usu�rio quantas vezes o valor que ele escolheu ocorre na Matriz
    6 - [OPCIONAL]  Enfeitar, deixar bem GAY.
*/

/*  Como gerar n�meros aleat�rios?
    -> Ou fazemos uma fun��o com uma conta macabra, tipo multiplicar pi pela soma do �ndice + 1 dividido pela raiz de 2
    -> Ou usamos as fun��es srand e rand, sendo que a primeira serve para alimentar a segunda
*/
/*  srand(time(NULL)) objetiva inicializar o gerador de n�meros aleat�rios
    com o valor da fun��o time(NULL). Este por sua vez, � calculado
    como sendo o total  de segundos passados desde 1 de janeiro de 1970
    at� a data atual.
    Desta forma, a cada execu��o o valor da "semente" ser� diferente.
*/
/////////////////////////////////////////////////////////////////////////////

void main()
{
    //Declarar vari�veis necess�rias para gerar a matriz:
    int matriz[10][10];                                     // Matriz propriamente dita
    int x,y;                                                // Coordenadas dos endere�os da Matriz

    //Declarar vari�veis para INTERA��O com operador:
    int numero=0;                                           // N�mero a ser pesquisado
    int contador=0;                                         // incrementar com a quantidade de repeti��es
    int menu;                                               // Servir� para o cara escolher a op��o no MENU
    //In�cio do c�digo, separado por bloco
    setlocale(LC_ALL,"Portuguese");                         // Corrigir acentua��o

    /*==================================*\
    ||      In�cio do Processamento     ||
    \|==================================*/

    {/// Gerar Matriz com 100 valores aleat�rios de 0 a 50
        //In�cio do Processamento 01:
        srand( (unsigned)time(NULL) );                      // usa a data atual para semear a fun��o rand
        for(x=0;x<10;x++)                                   // Para cada linha da Matriz:
        {                                                   //      Pausa para andar nas colunas desta linha...
            for(y=0;y<10;y++)                               // Para cada coluna dentro da linha atual:
            {                                               //      em cada campo dessa linha executar o procedimento:
                                                            // Tirar o m�dulo do numero aleat�rio por 50, assim o resultado estar� entre 0 e 50
                matriz[x][y] = rand() % 50;                 // Armazena o resultado na Matriz na posi��o atual
            }                                               // e imprime(ou n�o)  na tela, na posi��o especificada da matriz
                                                            // Salta uma linha antes de entrar na pr�xima linha da matriz
        }
    }   // Fim do processamento 01

    {/// Perguntar os dados ao Usu�rio (var numero)
        do{                                                 // perguntar o numero que o usu�rio quer pesquisar
                                                            // o "\t" serve para saltar uma tabula��o na linha
            printf("\n Uma Matriz 10x10 foi gerada e populada ");
            printf("\n com n�meros aleat�rios entre 0 e 50.");
            printf("\n Informe um n�mero entre 0 e 50 para ser pesquisado na Matriz:");
            scanf("%d",&numero);
            if (numero<0 || numero > 50)                    // se o cara informar um n�mero errado,
            {
                system("cls");                              // limpa a tela e repete a pergunta!
            }
        }while(numero<0 || numero > 50);
    }

    {/// Pesquisar na matriz (var contador)
            for (x=0;x<10;x++)                              // Para cada Linha
            {
                for(y=0;y<10;y++)                           // Para cada coluna dentro de cada linha
                {
                    if(matriz[x][y]==numero)                // Se nesta posi��o est� armazenado o n�mero que o user informou,
                    {contador++;}                           // Incrementa o contador
                }                                           // fim do PARA interno (que corre as colunas por linha)
            }                                               // fim do PARA externo (que corre as linhas)
    }

    {/// Exibir o MENU
        do{                                                 //Repita o Menu at� que usu�rio queira sair
        system("cls");                                      // Limpar a tela para exibir o MENU

        printf("\n Voc� escolheu pesquisar o valor: %d",numero);
        printf("\n Agora escolha uma op��o conforme o MENU:");
        printf("\n    1 -> Ver quantas vezes o valor se repete;");
        printf("\n    2 -> Ver a Matriz Preenchida;");
        printf("\n    3 -> Ver mapa de onde est� o n�mero na Matriz;");
        printf("\n    0 -> Sair\n\n");
        scanf("%i",&menu);

        switch(menu)
            {
            case 1:                                         // Ver Somente a Quantidade
                {///Informar ao Usu�rio a quantidade de repeti��es
                system("cls");
                printf("\n O n�mero %d aparece na Matriz %d vezes\n",numero,contador);
                system("pause > nul");                      // pausa para o usu�rio ver a mensagem
                };
                break;
            case 2:                                         // Ver a Matriz Preenchida
                {///Escrever na Tela a Matriz toda Preenchida
                    system("cls");
                    for (x=0;x<10;x++)                      // Para cada Linha
                    {
                        for(y=0;y<10;y++)                   // Para cada coluna dentro de cada linha
                        {
                            printf("%d\t",matriz[x][y]);    // D� um TAB, mostra o valor
                        }
                        printf("\n");                       // Salta uma linha ap�s percorrer as colunas
                    }
                system("pause > nul");                      // pausa para o usu�rio ver a mensagem
                };
                break;
            case 3:                                         //Ver mapa de onde est� o n�mero na Matriz
                {///Escrever na Tela a Matriz Apenas com o Valor
                    system("cls");
                    for (x=0;x<10;x++)                      // Para cada Linha
                    {
                        for(y=0;y<10;y++)                   // Para cada coluna dentro de cada linha
                        {
                            if(matriz[x][y]==numero){       // Veja se o valor � o que procuro!
                            printf("%d\t",matriz[x][y]);    // D� um TAB, mostra o valor
                            }else{
                            printf(".\t");                  // D� um TAB, mostra um ponto
                            }
                        }
                        printf("\n");                       // Salta uma linha ap�s percorrer as colunas
                    }
                system("pause > nul");                      // pausa para o usu�rio ver a mensagem
                };
                break;
            default:                                        // Fazer nada, Sair
                break;
            }
        }while(menu != 0);                                  // Quando for 0, sai do MENU
    }                                                       // Fim do Menu e tudo dentro dele!
}                                                           // Fim da fun��o Principal

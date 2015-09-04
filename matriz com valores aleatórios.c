#include<stdio.h>
#include<locale.h>

/////////////////////////////////////////////////////////////////////////////
/*  Problema:
    ------------------------------------------------------------------------------
    Formar uma matriz 10x10;
    -> Usuário deve informar um número de 0 a 50;
    -> Preencher toda a matriz com números aleatórios;
    -> Informar o numero de vezes que o Número Informado foi apresentado na matriz

        Autor: Davi Nunes "aka" Ilunne || Ilune
        Faculdade Anhanguera
        PoBRE :: Portal Brasileiro de RomHack e Emulação
        http://www.romhackers.org/modules/smartsection/item.php?itemid=15


    =>  ADICIONALMENTE, vou adicionar um MENU com as opções:
        1: Mostrar a Matriz com os valores
        2: Mostrar quantas vezes o valor aparece na matriz
        3: Mostrar a Matriz apenas com o valor escolhido em suas posições
*/

/*  O que este problema quer ensinar?
    :: Percorrer uma Matriz
        Então Veja que é necessário uma repetição composta para essa tarefa
    :: Gerar Valores Aleatórios
        Não se prenda a um único método, o céu é o limite!
    :: Contar valores dentro de uma Matriz
        Precisa só saber incrementar uma variável
*/

///Algoritmo para resolver o Problema:
/*
    1 - Criar uma Matriz
    2 - Percorrer todos os campos da Matriz atribuindo a cada um deles, valor aleatório
    3 - Pedir um Valor ao Usuário
    4 - Percorrer a Matriz, de novo, para comparar cada campo com o valor informado pelo usuario e contar quantos são
    5 - Mostrar pro usuário quantas vezes o valor que ele escolheu ocorre na Matriz
    6 - [OPCIONAL]  Enfeitar, deixar bem GAY.
*/

/*  Como gerar números aleatórios?
    -> Ou fazemos uma função com uma conta macabra, tipo multiplicar pi pela soma do índice + 1 dividido pela raiz de 2
    -> Ou usamos as funções srand e rand, sendo que a primeira serve para alimentar a segunda
*/
/*  srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total  de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
*/
/////////////////////////////////////////////////////////////////////////////

void main()
{
    //Declarar variáveis necessárias para gerar a matriz:
    int matriz[10][10];                                     // Matriz propriamente dita
    int x,y;                                                // Coordenadas dos endereços da Matriz

    //Declarar variáveis para INTERAÇÃO com operador:
    int numero=0;                                           // Número a ser pesquisado
    int contador=0;                                         // incrementar com a quantidade de repetições
    int menu;                                               // Servirá para o cara escolher a opção no MENU
    //Início do código, separado por bloco
    setlocale(LC_ALL,"Portuguese");                         // Corrigir acentuação

    /*==================================*\
    ||      Início do Processamento     ||
    \|==================================*/

    {/// Gerar Matriz com 100 valores aleatórios de 0 a 50
        //Início do Processamento 01:
        srand( (unsigned)time(NULL) );                      // usa a data atual para semear a função rand
        for(x=0;x<10;x++)                                   // Para cada linha da Matriz:
        {                                                   //      Pausa para andar nas colunas desta linha...
            for(y=0;y<10;y++)                               // Para cada coluna dentro da linha atual:
            {                                               //      em cada campo dessa linha executar o procedimento:
                                                            // Tirar o módulo do numero aleatório por 50, assim o resultado estará entre 0 e 50
                matriz[x][y] = rand() % 50;                 // Armazena o resultado na Matriz na posição atual
            }                                               // e imprime(ou não)  na tela, na posição especificada da matriz
                                                            // Salta uma linha antes de entrar na próxima linha da matriz
        }
    }   // Fim do processamento 01

    {/// Perguntar os dados ao Usuário (var numero)
        do{                                                 // perguntar o numero que o usuário quer pesquisar
                                                            // o "\t" serve para saltar uma tabulação na linha
            printf("\n Uma Matriz 10x10 foi gerada e populada ");
            printf("\n com números aleatórios entre 0 e 50.");
            printf("\n Informe um número entre 0 e 50 para ser pesquisado na Matriz:");
            scanf("%d",&numero);
            if (numero<0 || numero > 50)                    // se o cara informar um número errado,
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
                    if(matriz[x][y]==numero)                // Se nesta posição está armazenado o número que o user informou,
                    {contador++;}                           // Incrementa o contador
                }                                           // fim do PARA interno (que corre as colunas por linha)
            }                                               // fim do PARA externo (que corre as linhas)
    }

    {/// Exibir o MENU
        do{                                                 //Repita o Menu até que usuário queira sair
        system("cls");                                      // Limpar a tela para exibir o MENU

        printf("\n Você escolheu pesquisar o valor: %d",numero);
        printf("\n Agora escolha uma opção conforme o MENU:");
        printf("\n    1 -> Ver quantas vezes o valor se repete;");
        printf("\n    2 -> Ver a Matriz Preenchida;");
        printf("\n    3 -> Ver mapa de onde está o número na Matriz;");
        printf("\n    0 -> Sair\n\n");
        scanf("%i",&menu);

        switch(menu)
            {
            case 1:                                         // Ver Somente a Quantidade
                {///Informar ao Usuário a quantidade de repetições
                system("cls");
                printf("\n O número %d aparece na Matriz %d vezes\n",numero,contador);
                system("pause > nul");                      // pausa para o usuário ver a mensagem
                };
                break;
            case 2:                                         // Ver a Matriz Preenchida
                {///Escrever na Tela a Matriz toda Preenchida
                    system("cls");
                    for (x=0;x<10;x++)                      // Para cada Linha
                    {
                        for(y=0;y<10;y++)                   // Para cada coluna dentro de cada linha
                        {
                            printf("%d\t",matriz[x][y]);    // Dá um TAB, mostra o valor
                        }
                        printf("\n");                       // Salta uma linha após percorrer as colunas
                    }
                system("pause > nul");                      // pausa para o usuário ver a mensagem
                };
                break;
            case 3:                                         //Ver mapa de onde está o número na Matriz
                {///Escrever na Tela a Matriz Apenas com o Valor
                    system("cls");
                    for (x=0;x<10;x++)                      // Para cada Linha
                    {
                        for(y=0;y<10;y++)                   // Para cada coluna dentro de cada linha
                        {
                            if(matriz[x][y]==numero){       // Veja se o valor é o que procuro!
                            printf("%d\t",matriz[x][y]);    // Dá um TAB, mostra o valor
                            }else{
                            printf(".\t");                  // Dá um TAB, mostra um ponto
                            }
                        }
                        printf("\n");                       // Salta uma linha após percorrer as colunas
                    }
                system("pause > nul");                      // pausa para o usuário ver a mensagem
                };
                break;
            default:                                        // Fazer nada, Sair
                break;
            }
        }while(menu != 0);                                  // Quando for 0, sai do MENU
    }                                                       // Fim do Menu e tudo dentro dele!
}                                                           // Fim da função Principal

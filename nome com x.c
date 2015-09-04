#include<stdio.h>
#include<locale.h>
#include<windows.h>

/*  Problema:
    ------------------------------------------------------------------------------
    Escrever na tela um nome fornecido pelo usuário, em forma de gráfico contendo a letra x;

    Exemplo:

    XX     X   X X  X
    X  X  X X  X X
    X  X  XXX  X X  X
    X  X  X X  X X  X
    XX    X X   X   X
*/

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*\
||      Autor: Davi Nunes "aka" Ilunne || Ilune                             ||
||      e-mail: davi.nunes@gmail.com                                        ||
||      Faculdade Anhanguera :: FACNET                                                 ||
||      PoBRE :: Portal Brasileiro de RomHack e Emulação                    ||
||      http://www.romhackers.org/modules/smartsection/item.php?itemid=15   ||
\*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

/*   Análise dos fatos:
    - Cada Letra deve ser formada por uma matriz 5x6
        (sendo a ultima coluna reservada para espaço entre letras).
        cada uma delas deve ser concatenada para formar a palavra
    - Formar um padrão para calcular cada letra do alfabeto
        Definir comparações para cada uma das 27 letras do alfabeto
    - Conseguir escrever letra por letra em uma matriz pré-definida
        Para isso vamos contar a quantidade de letras da string e multiplicar por um fator
    - Como o computador vai saber onde escrever?
        Serão Usados três laços encadeados, um para acessar a posição inicial da área da Letra,
        depois acessar a miniMatriz, depois preencher a miniMatriz
    - Como o computador vai organizar as letras?
        Através de 3 laços encadeados
    - É possível criar uma matriz de tamanho dinâmico?
        Sim, passando como parâmetro para uma função que gera a matriz local
    - Tive uma idéia de fazer com concatenação de strings, mais simples.
        Mas vou manter o caminho da Matriz dinâmica

*/

/*  O que este problema quer ensinar?
    :: Percorrer uma Matriz
        Então Veja que é necessário uma repetição composta para essa tarefa
    :: Trabalhar em uma área específica em uma matriz
        Pra isso tem que relacionar as coordenadas
    :: Segmentar uma Matriz e trabalhar em partes por vez
    :: Definir relações entre as ordenadas para formar desenhos
*/

///Roteiro para resolver o problema:

/*  1 - Usuário informa a Palavra e a Letra usada para formar a Palavra
    2 - Computador conta quantas letras tem a Palavra
    3 - Multiplica a qde de letras por 6 para definir o tamanho do quadro
    4 - Defini uma Matriz de 5 linhas e colunas de tamanho dinamico
    5 - Encadeia uma laço triplo para:
        acessar área de cada letra, na horizontal, no quadro principal;
            Este laço deve ter dupla inicialização e duplo incremento:
                -iniciar o contador de grupo de colunas, incrementado em 6
                -iniciar o contador de letras, que deslocará o "ponteiro" na string, incrementado em 1
        acessar linha por linha de cada área no quadro
        acessar coluna por coluna de cada linha de cada área limitada
    6 - Em cada célula, acionar um Escolha - Caso para escolher a letra da vez
        Definir relações de desenho para cada letra dentre as 27
        Para cada relação verdadeira, escrever 1 no campo correspodente
    7 - Ececutar uma repetição composta para ler a matriz final e
        para cada compo com int 1, escrever na tela a letra informada pelo usuário e
        cada campo com int 0, escrever na tela um espaço
    8 - Enfeitar a vontade
*/


void rendLetra(int largura, char nome[],char pixel)
{   /*  Esta função está separada pois preciso saber a largura
        da coluna antes de criar a Matriz, então a largura, após calculada,
        é passada como parâmetro para a função

        Parâmetros:
        largura: determina a largura da matriz que formará a palavra
        nome: importa a palavra digitada pelo usuário
        pixel: importa a letra escolhida pelo usuário

        Favor ver a Função MAIN primeiro! */

    ///Declaração de Variáveis internas
    int x,y;    // Corrdenadas Matriz Externa
    int casa=0; // Servirá de indice da palavra
    int z;      // Coordenada da Matriz Interna, eixo vertical
    int matriz[5][largura]; // Matriz declarada dinamicamente

    ///Inicializar Variáveis necessárias:
    // Preenche todos os campos da Matriz com o numero 0
    for(x=0;x<5;x++){
        for(y=0;y<largura;y++){
            matriz[x][y]=0;
        }
    }

    ///Imprime a Matriz na tela, como está
    for(x=0;x<5;x++){
        for(y=0;y<largura;y++){
            printf("%d",matriz[x][y]);
        }
        printf("\n");
    }
    getchar();

    ///Desenha as letras na Matriz
    for(y=0,casa=0;y<largura;y+=6,casa++){  //Em cada Bloco de Letra na Matriz Principal(de 6 em 6 colunas) já deslocando o ponteiro da string;
        for(x=0;x<5;x++){                   //Em cada Linha de uma parcela 6x5 desta Matriz(a ultima coluna do bloco é em branco mesmo);
            for(z=y;z<y+5;z++){             //Em cada campo dentro da linha desta Letra;
            { ///Aqui começa Uma Seleção das Letras, Cada uma Vai determinar como a palavra será "pintada" na tela;
                switch(nome[casa])
                    {
                    case 'a': if((z==y || x==2 ||  x==0 || z==y+4) && !(x==0 && z==y) && !(x==0 && z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'b': if((z==y || x==0 ||  x==4 || x==2 || z==y+4) && !(x==2 && z==y+1) && !(x==0 && z==y+4) && !(x==4&&z==y+4) && !(x==2&&z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'c': if((z==y || x==0 || x==4) && !(x==0 && z==y) && !(x==4 && z==y) )
                        matriz[x][z]=1;
                        break;
                    case 'd': if((z==y || x==0 || x==4 || z==y+4) && !(x==0 && z==y+4) && !(x==4 && z==y+4) )
                        matriz[x][z]=1;
                        break;
                    case 'e': if((z==y || x==0 || x==4 || x==2) && !(x==2 && z==y+4) )
                        matriz[x][z]=1;
                        break;
                    case 'f': if((z==y || x==0 || x==2) && !(x==2 && z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'g': if(z==y || x==0 || x==4 || (x==3&&z==y+4) || (x==2 &&(z==y+2||z==y+3)))
                        matriz[x][z]=1;
                        break;
                    case 'h': if(z==y || z==y+4 || x==2)
                        matriz[x][z]=1;
                        break;
                    case 'i': if(z==y+2 && x!=1)
                        matriz[x][z]=1;
                        break;
                    case 'j': if((x==4||z==y+4||(x==3&&z==y))&& !(x==4&&z==y))
                        matriz[x][z]=1;
                        break;
                    case 'k': if(z==y||(x==2&&(z==y+1||z==y+2))||((x==0||x==4)&&z==y+4)||((x==1||x==3)&&z==y+3))
                        matriz[x][z]=1;
                        break;
                    case 'l': if(z==y || x==4 )
                        matriz[x][z]=1;
                        break;
                    case 'm': if(z==y||z==y+4||(x==1&&(z==y+1||z==y+3))||(x==2&&z==y+2))
                        matriz[x][z]=1;
                        break;
                    case 'n': if(z==y || z==y+4 || (x==1 && z==y+1) || (x==2 && z==y+2) || (x==3 && z==y+3) )
                        matriz[x][z]=1;
                        break;
                    case 'o': if((x==0||x==4||z==y||z==y+4)&&!((x==0||x==4)&&(z==y||z==y+4)))
                        matriz[x][z]=1;
                        break;
                    case 'p': if((z==y||(x==0&&z!=y+4))||(x==2&&!(z==y+1||z==y+4))||(x==1&&z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'q': if((z==y||z==y+4||x==0||x==4)&&!(((z==y)&&(x==0||x==4))||(z==y+4&&(x==0||x==3))||(x==4&&z==y+3))||(x==3&&z==y+3)||(x==2&&z==y+2))
                        matriz[x][z]=1;
                        break;
                    case 'r': if((z==y||(x==0&&z!=y+4))||(x==2&&!(z==y+1||z==y+4))||(x==2&&z==y+1)||(x==1&&z==y+4)||(x==3&&z==y+2)||(x==4&&(z==y+4||z==y+3)))
                        matriz[x][z]=1;
                        break;
                    case 's': if((x==0&&z!=y)||(x==4&&z!=y+4)||(x==2&&!(z==y||z==y+4))||(x==1&&z==y)||(x==3&&z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 't': if(x==0||z==y+2)
                        matriz[x][z]=1;
                        break;
                    case 'u': if((z==y || z==y+4 || x==4) && !(x==4 && z==y) && !(x==4 && z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'v': if((z==y || z==y+4 || (x==3 && (z==y+1||z==y+3)) || (x==4 && z==y+2) ) && !(x>2 && z==y) && !(x>2 && z==y+4))
                        matriz[x][z]=1;
                        break;
                    case 'w': if(z==y||z==y+4||(x==3&&(z==y+1||z==y+3))||(x==2&&z==y+2))
                        matriz[x][z]=1;
                        break;
                    case 'x': if(x==z-y||x+z-y==4)
                        matriz[x][z]=1;
                        break;
                    case 'y': if((x==0&&(z==y||z==y+4))||(x==1&&(z==y+1||z==y+3))||(z==y+2&&!(x==0||x==1)))
                        matriz[x][z]=1;
                        break;
                    case 'z': if(x==0||x==4||x+z-y==4)
                        matriz[x][z]=1;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    ///Imprime a Matriz binária na Tela
    printf("\nAté agora a Matriz Binária está assim:\n\n");
    for(x=0;x<5;x++){
        for(y=0;y<largura;y++){
            printf("%d",matriz[x][y]);
        }
        printf("\n");
    }
    getchar();
    system("cls && color e"); // limpa a tela e muda cor do prompt

    ///Imprime o Nome
    printf("\n\nEis a palavra impressa:\n\n");
    for(x=0;x<5;x++){
        for(y=0;y<largura;y++){
            if(matriz[x][y]==1){
            printf("%c",pixel);
            }else{
            printf(" ");}
        }
        printf("\n");
    }
}

void main()
{
    //Declarar variáveis necessárias:
    char nome[100];
    int *prototipo;
    int i,comprimento,c=0;
    char pixel;

    //Inicializar variáveis que precisam ser iniciadas:

    //Início do Processamento:
    setlocale(LC_ALL,"Portuguese");
    ///Informações e Solicitar dados ao usuário
    printf("ESTE PROGRAMA DESENHA UMA PALAVRA NA TELA\n");
    printf("    USANDO UM CARACTERE ESPECIFICO\n\n");

    printf("Informe a PALAVRA que quer escrever:\n");
    printf("  (Por favor, informe apenas letras minusculas sem acento!)\n");

    //scanf(%s,&nome);
    gets(nome);
   // printf(nome);


    printf("\nInforme o caractere que sera usado para desenhar:\n");
    pixel=getchar();


    //Contar quantas letras tem o nome
    for(i=0;nome[i]!='\0';i++){//Definir o Tamanho da String
        c++;
    }

    // Determinar o Tamanho necessário para escrever o nome considerando 6 colunas por letra
    comprimento = c*6;

    system("cls");
    printf("A palavra \"%s\" tem %d elementos, e \nserão necessários %d colunas para escrever.\n\n",nome,c,comprimento);
    rendLetra( comprimento , nome, pixel );
    // Todo o resto ocorre dentro da função acima
    // Aqui termina o processo, então Pausa pro Usuário apreciar a Obra...
    getchar();

}

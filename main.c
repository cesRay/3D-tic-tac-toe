#include <stdio.h>
#define CRUZ 'X'
#define CIRCULO 'O'
char TicTacToe[3][3][3] ={{{'.','.','.'},{'.','.','.'},{'.','.','.'}},
                        {{'.','.','.'},{'.','.','.'},{'.','.','.'}},
                        {{'.','.','.'},{'.','.','.'},{'.','.','.'}}};       //matriz tridimencional
char nombreJugador1[15], nombreJugador2[15];                               //nombres de jugadores

int humanoVsHumano2();                                                    //prototipo de funcion
int HvCPUfacil();
int HvCPUnormal();
int TaparJugada();


void Reinicializar(){
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                    TicTacToe[i][j][k]='.';
            }
        }
    }
}

void bienvenidaHumano(){
    printf("\t\t\t  ====TIC TAC TOE 3D====\n\n");
    printf("Jugador 1, inserte su nombre: ");
    scanf("%s",&nombreJugador1);
    printf("\nJugador 2, inserte su nombre: ");
    scanf("%s",&nombreJugador2);
    system("cls");
}                                                           //definicion de funcion de bienvenida



void ImprimeTablero(){
    int i,j;
    printf("\t\t\t  ====TIC TAC TOE 3D====\n\n");
    for(i=0;i<3;i++){
        printf("\n\t\t\t\t  ");
        for(j=0;j<3;j++){
            printf("%c ",TicTacToe[i][j][0]);
        }
    }
    printf("\n\n\t\t\t\t  altura 0\n\n");
    for(i=0;i<3;i++){
        printf("\n\t\t\t\t  ");
        for(j=0;j<3;j++){
            printf("%c ", TicTacToe[i][j][1]);
        }
    }
    printf("\n\n\t\t\t\t  altura 1\n\n");
    for(i=0;i<3;i++){
        printf("\n\t\t\t\t  ");
        for(j=0;j<3;j++){
            printf("%c ",TicTacToe[i][j][2]);
        }
    }
    printf("\n\n\t\t\t\t  altura 2\n\n");
}                                                   //definicion de funcion de interfaz de matriz



int ganar(int *turno){
    int x,y,contador=0;

    for(y=0;y<3;y++)
    {
        for(x=0;x<3;x++)
        {
                if(TicTacToe[0][x][y]==TicTacToe[1][x][y]&&TicTacToe[0][x][y]==TicTacToe[2][x][y]&&TicTacToe[0][x][y]==CRUZ)
                    contador++;
                else if (TicTacToe[x][0][y]==TicTacToe[x][1][y]&&TicTacToe[x][0][y]==TicTacToe[x][2][y]&&TicTacToe[x][0][y]==CRUZ)
                    contador++;
                else if (TicTacToe[x][y][0]==TicTacToe[x][y][1]&&TicTacToe[x][y][0]==TicTacToe[x][y][2]&&TicTacToe[x][y][0]==CRUZ)
                    contador++;
                else if (TicTacToe[y][x][x]==TicTacToe[y][x+1][x+1]&&TicTacToe[y][x][x]==TicTacToe[y][x+2][x+2]&&TicTacToe[y][x][x]==CRUZ)
                    contador++;
                else if (TicTacToe[x][y][x]==TicTacToe[x+1][y][x+1]&&TicTacToe[x][y][x]==TicTacToe[x+2][y][x+2]&&TicTacToe[x][y][x]==CRUZ)
                    contador++;
                else if (TicTacToe[x][x][y]==TicTacToe[x+1][x+1][y]&&TicTacToe[x][x][y]==TicTacToe[x+2][x+2][y]&&TicTacToe[x][x][y]==CRUZ)
                    contador++;
                else if(TicTacToe[x][x][x]==TicTacToe[x+1][x+1][x+1]&&TicTacToe[x][x][x]==TicTacToe[x+2][x+2][x+2]&&TicTacToe[x][x][x]==CRUZ)
                    contador++;
                else if(TicTacToe[x][x+2][x]==TicTacToe[x+1][x+1][x+1]&& TicTacToe[x][x+2][x]==TicTacToe[x+2][x][x+2]&&TicTacToe[x][x+2][x]==CRUZ)
                    contador++;
                else if(TicTacToe[x][x+2][y]==TicTacToe[x+1][x+1][y]&& TicTacToe[x][x+2][y]==TicTacToe[x+2][x][y]&&TicTacToe[x][x+2][y]==CRUZ)
                    contador++;
                else if(TicTacToe[x][x+2][x]==TicTacToe[x][x+1][x+1]&& TicTacToe[x][x+2][x]==TicTacToe[x][x][x+2]&&TicTacToe[x][x+2][x]==CRUZ)
                    contador++;
                else if(TicTacToe[x+2][x][x]==TicTacToe[x+1][x][x+1]&& TicTacToe[x+2][x][x]==TicTacToe[x][x][x+2]&&TicTacToe[x+2][x][x]==CRUZ)
                    contador++;
                else if(TicTacToe[0][x][y]==TicTacToe[1][x][y]&&TicTacToe[0][x][y]==TicTacToe[2][x][y]&&TicTacToe[0][x][y]==CIRCULO)
                    contador+=2;
                else if (TicTacToe[x][0][y]==TicTacToe[x][1][y]&&TicTacToe[x][0][y]==TicTacToe[x][2][y]&&TicTacToe[x][0][y]==CIRCULO)
                    contador+=2;
                else if (TicTacToe[x][y][0]==TicTacToe[x][y][1]&&TicTacToe[x][y][0]==TicTacToe[x][y][2]&&TicTacToe[x][y][0]==CIRCULO)
                    contador+=2;
                else if (TicTacToe[y][x][x]==TicTacToe[y][x+1][x+1]&&TicTacToe[y][x][x]==TicTacToe[y][x+2][x+2]&&TicTacToe[y][x][x]==CIRCULO)
                    contador+=2;
                else if (TicTacToe[x][y][x]==TicTacToe[x+1][y][x+1]&&TicTacToe[x][y][x]==TicTacToe[x+2][y][x+2]&&TicTacToe[x][y][x]==CIRCULO)
                    contador+=2;
                else if (TicTacToe[x][x][y]==TicTacToe[x+1][x+1][y]&&TicTacToe[x][x][y]==TicTacToe[x+2][x+2][y]&&TicTacToe[x][x][y]==CIRCULO)
                    contador+=2;
                else if(TicTacToe[x][x][x]==TicTacToe[x+1][x+1][x+1]&&TicTacToe[x][x][x]==TicTacToe[x+2][x+2][x+2]&&TicTacToe[x][x][x]==CIRCULO)
                    contador+=2;
                else if(TicTacToe[x][x+2][x]==TicTacToe[x+1][x+1][x+1]&& TicTacToe[x][x+2][x]==TicTacToe[x+2][x][x+2]&&TicTacToe[x][x+2][x]==CIRCULO)
                    contador+=2;
                else if(TicTacToe[x][x+2][y]==TicTacToe[x+1][x+1][y]&& TicTacToe[x][x+2][y]==TicTacToe[x+2][x][y]&&TicTacToe[x][x+2][y]==CIRCULO)
                    contador+=2;
                else if(TicTacToe[x][x+2][x]==TicTacToe[x][x+1][x+1]&& TicTacToe[x][x+2][x]==TicTacToe[x][x][x+2]&&TicTacToe[x][x+2][x]==CIRCULO)
                    contador+=2;
                else if(TicTacToe[x+2][x][x]==TicTacToe[x+1][x][x+1]&& TicTacToe[x+2][x][x]==TicTacToe[x][x][x+2]&&TicTacToe[x+2][x][x]==CIRCULO)
                    contador+=2;
                else if (*turno==26)
                    contador+=3;
            switch (contador) {
                       case 0:
                           break;
                       case 1:
                           printf("GANA %s!\n\n",nombreJugador1);
                           return 1;
                           break;
                       case 2:
                           printf("GANA %s!\n\n",nombreJugador2);
                           return 1;
                           break;
                       case 3:
                           printf("ES UN EMPATE!\n\n");
                           return 1;
                       }
        }
    }                                       //definicion de funcion de configuraciones para ganar

    return 0;
}



int main(){
    system("color a");
    int op;
    printf("\t\t\t  ====TIC TAC TOE 3D====\n\n");
    printf("MENU\n");
    printf("1.  Humano Vs Humano \n\n2.  Humano Vs Computadoras\n\n3.  Huir\n");
    scanf("%i",&op);
    switch (op) {
    case 1:
        humanoVsHumano2();
        break;
    case 2:
        printf("\t\t\t  ===HUMANO VS COMPUTADORA===\n\n");
        int op2;
        printf("Elije la dificultad\n\n");
        printf("1.  Facil\n\n2.  Normal\n");
        scanf("%i",&op2);
        switch (op2) {
        case 1:
            HvCPUfacil();
            break;
        case 2:
            HvCPUnormal();
            break;
        }

        break;
    case 3:
        printf("HASTA LA PROXIMA, HUMANO\n");
        break;
    }
    return 0;
}                                          //definicion de funcion principal



int humanoVsHumano2(){
    Reinicializar();
    bienvenidaHumano();
    int turno = 0;
    int a,b,c,player=1;
    ImprimeTablero();
    while(turno<27){
        if(player == 1)
        {
            printf("\nTurno de %s\n", nombreJugador1);
            printf("Elije una fila\n");
            scanf("%i",&a);
            printf("Elije una columna\n");
            scanf("%i",&b);
            printf("Elije una altura\n");
            scanf("%i",&c);
            if(TicTacToe[a][b][c]=='.'){
                TicTacToe[a][b][c]=CRUZ;
                player++;
                turno++;
                system("cls");
                ImprimeTablero();
                if (ganar(&turno)==1)
                    return 0;
            }
            else
                printf("\nCASILLA OCUPADA!\n");
        }
        else if(player==2){
            printf("\nTurno de %s\n", nombreJugador2);
            printf("Elije una fila\n");
            scanf("%i",&a);
            printf("Elije una columna\n");
            scanf("%i",&b);
            printf("Elije una altura\n");
            scanf("%i",&c);
            if(TicTacToe[a][b][c]=='.'){
                TicTacToe[a][b][c]=CIRCULO;
                player--;
                turno++;
                system("cls");
                ImprimeTablero();
                if (ganar(&turno)==1)
                    return 0;
            }
            else
                printf("\nCASILLA OCUPADA!\n");
        }
        ganar(&turno);
    }
    return 0;
}                                               //definicion de funcion de modalidad jugador v jugador



int HvCPUfacil(){
    printf("Escribe tu nombre, humano\n");
    scanf("%s",&nombreJugador1);
    printf("Elije el nombre de tu adversario\n");
    scanf("%s",&nombreJugador2);
    int turno =0;
    int a,b,c;
    system("cls");
    ImprimeTablero();
    while(turno < 27){
            printf("Elije una fila, humano\n");
            scanf("%i",&a);
            printf("Elije una columna, humano\n");
            scanf("%i",&b);
            printf("Elije una altura, humano\n");
            scanf("%i",&c);
            if(TicTacToe[a][b][c]=='.'){
                TicTacToe[a][b][c]=CRUZ;
                turno++;
                srand(time(NULL));
                do{
                    a=rand()%2;
                    b=rand()%2;
                    c=rand()%2;
                }while(TicTacToe[a][b][c]!='.');
                TicTacToe[a][b][c]=CIRCULO;
                turno++;
                system("cls");
                ImprimeTablero();
                if (ganar(&turno)==1)
                    return 0;
            }
            else
                printf("\nCASILLA OCUPADA!\n");

        ganar(&turno);
    }
    return 0;
}



int TaparJugada(){
    int x, y;
    for(y =0;y<3;y++){
        for(x=0;x<3;x++){
            if(TicTacToe[0][x][y]==TicTacToe[1][x][y] && TicTacToe[0][x][y]==CRUZ){
                if(TicTacToe[2][x][y]=='.'){
                    TicTacToe[2][x][y]=CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[0][x][y]==TicTacToe[2][x][y]&& TicTacToe[0][x][y]==CRUZ){
                if(TicTacToe[1][x][y]=='.'){
                    TicTacToe[1][x][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[1][x][y]==TicTacToe[2][x][y]&& TicTacToe[1][x][y]==CRUZ){
                if(TicTacToe[0][x][y]=='.'){
                    TicTacToe[0][x][y] = CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][0][y]==TicTacToe[x][1][y]&& TicTacToe[x][0][y]==CRUZ){
                if(TicTacToe[x][2][y]=='.'){
                    TicTacToe[x][2][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][0][y]==TicTacToe[x][2][y]&& TicTacToe[x][0][y]==CRUZ){
                if(TicTacToe[x][1][y]=='.'){
                    TicTacToe[x][1][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][1][y]==TicTacToe[x][2][y]&& TicTacToe[x][1][y]==CRUZ){
                if(TicTacToe[x][0][y]=='.'){
                    TicTacToe[x][0][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][y][0]==TicTacToe[x][y][1]&& TicTacToe[x][y][0]==CRUZ){
                if(TicTacToe[x][y][2]=='.'){
                    TicTacToe[x][y][2]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][y][0]==TicTacToe[x][y][2]&& TicTacToe[x][y][0]==CRUZ){
                if(TicTacToe[x][y][1]=='.'){
                    TicTacToe[x][y][1]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][y][1]==TicTacToe[x][y][2]&& TicTacToe[x][y][1]==CRUZ){
                if(TicTacToe[x][y][0]=='.'){
                    TicTacToe[x][y][0]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[y][x][x]==TicTacToe[y][x+1][x+1]&& TicTacToe[y][x][x]==CRUZ){
                if(TicTacToe[y][x+2][x+2]=='.'){
                    TicTacToe[y][x+2][x+2]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[y][x][x]==TicTacToe[y][x+2][x+2]&& TicTacToe[y][x][x]==CRUZ){
                if(TicTacToe[y][x+1][x+1]=='.'){
                    TicTacToe[y][x+1][x+1]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[y][x+1][x+1]==TicTacToe[y][x+2][x+2]&& TicTacToe[y][x+1][x+1]==CRUZ){
                if(TicTacToe[y][x][x]=='.'){
                    TicTacToe[y][x][x]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][y][x]==TicTacToe[x+1][y][x+1]&& TicTacToe[x][y][x]==CRUZ){
                if(TicTacToe[x+2][y][x+2]=='.'){
                    TicTacToe[x+2][y][x+2]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][y][x]==TicTacToe[x+2][y][x+2]&& TicTacToe[x][y][x]==CRUZ){
                if(TicTacToe[x+1][y][x+1]=='.'){
                    TicTacToe[x+1][y][x+1]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x+1][y][x+1]==TicTacToe[x+2][y][x+2]&& TicTacToe[x+1][y][x+1]==CRUZ){
                if(TicTacToe[x][y][x]=='.'){
                    TicTacToe[x][y][x]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][x][y]==TicTacToe[x+1][x+1][y]&& TicTacToe[x][x][y]==CRUZ){
                if(TicTacToe[x+2][x+2][y]=='.'){
                    TicTacToe[x+2][x+2][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][x][y]==TicTacToe[x+2][x+2][y]&& TicTacToe[x][x][y]==CRUZ){
                if(TicTacToe[x+1][x+1][y]=='.'){
                    TicTacToe[x+1][x+1][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x+1][x+1][y]==TicTacToe[x+2][x+2][y]&& TicTacToe[x+1][x+1][y]==CRUZ){
                if(TicTacToe[x][x][y]=='.'){
                    TicTacToe[x][x][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[0][x][y]==TicTacToe[1][x][y]&& TicTacToe[0][x][y]==CRUZ){
                if(TicTacToe[2][x][y]=='.'){
                    TicTacToe[2][x][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[0][x][y]==TicTacToe[2][x][y]&& TicTacToe[0][x][y]==CRUZ){
                if(TicTacToe[1][x][y]=='.'){
                    TicTacToe[1][x][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[1][x][y]==TicTacToe[2][x][y]&& TicTacToe[1][x][y]==CRUZ){
                if(TicTacToe[0][x][y]=='.'){
                    TicTacToe[0][x][y]= CIRCULO;
                    return 1;
                }
            }
            else if(TicTacToe[x][x][x]==TicTacToe[x+1][x+1][x+1]&& TicTacToe[x][x][x]==CRUZ)
                if(TicTacToe[x+2][x+2][x+2]=='.'){
                    TicTacToe[x+2][x+2][x+2]= CIRCULO;
                    return 1;
            }
            else if(TicTacToe[x][x][x]==TicTacToe[x+2][x+2][x+2]&& TicTacToe[x][x][x]==CRUZ)
                 if(TicTacToe[x+1][x+1][x+1]=='.'){
                    TicTacToe[x+1][x+1][x+1]= CIRCULO;
                    return 1;
            }
             else if(TicTacToe[x+1][x+1][x+1]==TicTacToe[x+2][x+2][x+2]&& TicTacToe[x+1][x+1][x+1]==CRUZ)
                  if(TicTacToe[x][x][x]=='.'){
                     TicTacToe[x][x][x]= CIRCULO;
                     return 1;
             }
              else if(TicTacToe[x][x+2][x]==TicTacToe[x+1][x+1][x+1]&& TicTacToe[x][x+2][x]==CRUZ)
                  if(TicTacToe[x+2][x][x+2]=='.'){
                     TicTacToe[x+2][x][x+2]= CIRCULO;
                     return 1;
             }
              else if(TicTacToe[x][x+2][x]==TicTacToe[x+2][x][x+2]&& TicTacToe[x][x+2][x]==CRUZ)
                   if(TicTacToe[x+1][x+1][x+1]=='.'){
                      TicTacToe[x+1][x+1][x+1]= CIRCULO;
                      return 1;
             }
               else if(TicTacToe[x+1][x+1][x+1]==TicTacToe[x+2][x][x+2]&& TicTacToe[x+1][x+1][x+1]==CRUZ)
                    if(TicTacToe[x][x+2][x]=='.'){
                       TicTacToe[x][x+2][x]= CIRCULO;
                       return 1;
             }
                else if(TicTacToe[x][x+2][y]==TicTacToe[x+1][x+1][y]&& TicTacToe[x][x+2][y]==CRUZ)
                     if(TicTacToe[x+2][x][y]=='.'){
                        TicTacToe[x+2][x][y]= CIRCULO;
                        return 1;
              }
             else if(TicTacToe[x][x+2][y]==TicTacToe[x+2][x][y]&& TicTacToe[x][x+2][y]==CRUZ)
                  if(TicTacToe[x+1][x+1][y]=='.'){
                     TicTacToe[x+1][x+1][y]= CIRCULO;
                     return 1;
              }
              else if(TicTacToe[x+1][x+1][y]==TicTacToe[x+2][x][y]&& TicTacToe[x+1][x+1][y]==CRUZ)
                   if(TicTacToe[x][x+2][y]=='.'){
                      TicTacToe[x][x+2][y]= CIRCULO;
                      return 1;
              }
               else if(TicTacToe[x][x+2][x]==TicTacToe[x][x+1][x+1]&& TicTacToe[x][x+2][x]==CRUZ)
                    if(TicTacToe[x][x][x+2]=='.'){
                       TicTacToe[x][x][x+2]= CIRCULO;
                       return 1;
              }
                else if(TicTacToe[x][x+2][x]==TicTacToe[x][x][x+2]&& TicTacToe[x][x+2][x]==CRUZ)
                     if(TicTacToe[x][x+1][x+1]=='.'){
                        TicTacToe[x][x+1][x+1]= CIRCULO;
                        return 1;
              }
             else if(TicTacToe[x][x+1][x+1]==TicTacToe[x][x][x+2]&& TicTacToe[x][x+1][x+1]==CRUZ)
                  if(TicTacToe[x][x+2][x]=='.'){
                     TicTacToe[x][x+2][x]= CIRCULO;
                     return 1;
           }
              else if(TicTacToe[x+2][x][x]==TicTacToe[x+1][x][x+1]&& TicTacToe[x+2][x][x]==CRUZ)
                   if(TicTacToe[x][x][x+2]=='.'){
                      TicTacToe[x][x][x+2]= CIRCULO;
                      return 1;
            }
           else if(TicTacToe[x+2][x][x]==TicTacToe[x][x][x+2]&& TicTacToe[x+2][x][x]==CRUZ)
                if(TicTacToe[x+1][x][x+1]=='.'){
                   TicTacToe[x+1][x][x+1]= CIRCULO;
                   return 1;
         }
            else if(TicTacToe[x+1][x][x+1]==TicTacToe[x][x][x+2]&& TicTacToe[x+1][x][x+1]==CRUZ)
                if(TicTacToe[x+2][x][x]=='.'){
                   TicTacToe[x+2][x][x]= CIRCULO;
                   return 1;
         }

    }
}
    return 0;
}


int HvCPUnormal(){
    printf("Escribe tu nombre, humano\n");
    scanf("%s",nombreJugador1);
    printf("Elije el nombre de tu adversario\n");
    scanf("%s",&nombreJugador2);
    int turno =0;
    int a,b,c;
    system("cls");
    ImprimeTablero();
    while(turno < 27){
            printf("Elije una fila, humano\n");
            scanf("%i",&a);
            printf("Elije una columna, humano\n");
            scanf("%i",&b);
            printf("Elije una altura, humano\n");
            scanf("%i",&c);
            if(TicTacToe[a][b][c]=='.'){
                TicTacToe[a][b][c]=CRUZ;
                turno++;
                if (ganar(&turno)==1)
                    return 0;
                if(TaparJugada()==1){
                    TaparJugada();
                    turno++;
                    if (ganar(&turno)==1)
                        return 0;
                }
                else{
                    srand(time(NULL));
                    do{
                        a=rand()%2;
                        b=rand()%2;
                        c=rand()%2;
                    }while(TicTacToe[a][b][c]!='.');
                    TicTacToe[a][b][c]=CIRCULO;
                    turno++;
                    if (ganar(&turno)==1)
                        return 0;
                }
                system("cls");
                ImprimeTablero();
            }
            else
                printf("\nCASILLA OCUPADA!\n");
            }
    ganar(&turno);
    return 0;
}



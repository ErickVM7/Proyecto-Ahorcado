//juego ahorcado

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Se define para ciclos de los menu
#define TRUE 1
#define FALSE 0

// Funciones principales del menu
void menuPrincipal();  //Menu principal del juego
void menuNuevojuego(); //Entramos a jugar
void menuRankings();   //Ver la tabla de records
void menuReglas();     //Ver las reglas

// Funciones del submenú del nuevo juego
void juego(char palabras[][15],char nombre[]); //Codigo y ejecucion del juego
void categorias(); //Categoria de la plabra
void categoriaingresada(int opcion); //Lista de palabras y categoría seleccionada
void fallos(int intentos); //Dibujo e intentos del jugador

// Funciones del submenú de rankigs
void records(); //Buscar los records registrados

//Funciones del submenú de reglas
void reglas(); //Imprime las reglas en pantalla

//Funcion main y llama al menu principal
int main()
{
    menuPrincipal();
    return 0;
}    

// Funcion principal del menu

void menuPrincipal() //imprime el menu principal y recibe una opcion del jugador
{
    int opcionPrin;
    char repetir = TRUE;

    do
    {
        system("clear");
        printf("\n\n\t\t\tAhorcado\n");
        printf("\t\t\t********\n");
        printf("\n\t1. Nueva partida\n");
        printf("\t2. Reglas\n");
        printf("\t3. Rankings\n");
        printf("\t0. SALIR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcionPrin);

        switch (opcionPrin)
        {
        case 1:
            menuNuevojuego();
            break;

        case 2:
            menuReglas();
            break;
        
        case 3:
            menuRankings();
            break;

        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

// Definiciones de las funciones

void menuNuevojuego() //llama al juego
{ 
  categorias();
  system("pause");
  
}

void menuReglas() //reglas sobre el funcionamiento del juego
{ 
  int opcion;
  char repetir = TRUE;
  do
  {
   system("clear");
   printf("\n\n\t\t\tReglas\n");
   printf("\t\t\t------\n");
   printf("\tLas reglas son las siguientes: \n1. La opción de “Nueva Partida” permite al jugador ingresar un nombre, elegir una categoría de palabras e iniciar el juego de ahorcado. \n2. La opción de “Ranking” permite observar las posiciones actuales de las mejores puntuaciones y su usuario correspondiente. \n3. Después de cada juego, la cantidad de puntos que obtuvo el jugador al final se guarda automáticamente en el sistema. \n4. Si el nombre ingresado ya está registrado en el sistema, se le agregara un número al final del nombre según la cantidad de veces que haya sido ingresado. \n5. La partida se inicia con 500 puntos, cada intento fallido de ingresar una letra implica una pérdida de 100 puntos. \n6. El juego se pierde si el jugador no logra encontrar la palabra en menos de 5 intentos o llega a 0 puntos, lo que suceda primero. En caso de perder, saldrá la frase “Ahorcado” y juntos con dos opciones: “Volver al Menú” (pantalla inicial) o “Salir” (el cual permite finalizar el juego). \n7. Si el jugador gana, saldrá la frase “FELICIDADES, LOGRÓ COMPLETAR LA PALABRA”, y se guardará la puntuación. \n8. Debera colocar la letra en minuscula");

   printf("\n\nIngrese un número para regresar al menú: ");
   scanf("%d", &opcion);

 switch (opcion)
        {
           default: 
              repetir = FALSE;
              break;
             
        }
    
  } while (repetir);
}

void menuRankings() //funcion de los records
{ 
  int main ();
  int opcion;
  char repetir = TRUE;
  do{
   printf("\n\n\t\t\tRankings\n");
   printf("\t\t\t--------\n");
   FILE * flujo=fopen("record.txt","r"); //abrimos el archivo de txt en modo read
      if (flujo==NULL) 
        perror("Error al abrir el archivo");
      char caracter;
      while(feof(flujo)==0){  
        caracter = fgetc(flujo);
        printf("%c",caracter);
      }
      fclose(flujo);
   printf("\n\nIngrese un número para regresar al menú: ");
   scanf("%d", &opcion);         
  
 switch (opcion)
        {
           default: 
              repetir = FALSE;
              break;
             
        }
    
  }while (repetir);

  
}

void categorias() //menu de categorias para que el usuario elija y escriba su nombr
{
  
  printf("\n\n\t\t\tNUEVO JUEGO\n");
  printf("\t\t\t-----------\n");
 
  int op;
  system("clear");
  printf("Categorías \n\n");
  printf(" 1. Países\n");
  printf(" 2. Frutas\n");
  printf(" 3. Animales\n");
  printf(" 4. Deportes\n");
  printf(" 5. Salir\n");
  printf("Selecione una categoría: \n");
  scanf("%i",&op);
  

  if (op==1) categoriaingresada(op);
  if (op==2) categoriaingresada(op);
  if (op==3) categoriaingresada(op);
  if (op==4) categoriaingresada(op); // selecionar categoría  
  if (op==5) menuPrincipal();
  else
     categorias();
  

}

void categoriaingresada(int op){ //Lista de palabras de cada categoría
  char nombredecategoria[4][15]={"Paises","Frutas","Animales","Deportes"};
  char Paises [5][15]={"usa","francia","japon","italia","mexico"};
  char Frutas [5][15]={"manzana","melocoton","uva","naranja","pera"};
  char Animales [5][15]={"tigre","conejo","caballo","rinoceronte","cerdo"};
  char Deportes [5][15]={"futbol","natacion","baloncesto","boxeo","tenis"};

  switch(op){
    case 1:
      juego(Paises,nombredecategoria[op-1]);
      break;
    case 2:
      juego(Frutas,nombredecategoria[op-1]);
      break;
    case 3:
      juego(Animales,nombredecategoria[op-1]);
      break;
    case 4:
      juego(Deportes,nombredecategoria[op-1]);
      break;

  }
}
void juego(char palabras[][15],char nombre[]) { //recibe la opcion y el nombre de la categoria para esocger de manera aleatoria una palabara de esa categoria
  char nombrejugador[100];
  printf("\n\n Digite su nombre: \n\n");
  scanf("%s",nombrejugador);
  int opcion,i,j,k,longitud,espacios,puntos=600;//variables que se usaran
  int otravez;
  char letra;
  int aciertos = 0;
  int intentos = 0;
  int ganar = 0;
  srand(time(NULL));

  opcion = rand() % 5; //Numero aleatorio entre 0 y 4 para escojer la palabra
  longitud = strlen(palabras[opcion]); //se almacena la longitud de la palarba
  char frase[longitud];

  for(i=0; i<longitud;i++){ //se colocan la cantidad de guiones bajos
    frase[i]= '_';
  }

  do{ //ciclo del juego
    aciertos = 0;
    system("clear");
    printf("\n\t\t\t\tEL AHORCADO\n\n");
    printf(" CATEGORIA: %s\n\n",nombre);
    printf(" Intentos: %i\t\t\t\tPuntuacion: %i\n\n",7-intentos,puntos);
    fallos(intentos);

    printf("\n\n\n"); //imprime los guiones bajos
    for (i=0;i<longitud;i++){
      printf("%c ",frase[i]);
    }

    
   if (intentos==7){ //verifica si todavia tiene intentos
     printf("\n\n PERDISTE!! :C ");
     printf("La solucion era; %s \n\n",palabras[opcion]);
     printf("\n\n Puntuacion final: %d \n\n",puntos);
      FILE * flujo = fopen("record.txt","a"); //abre el archivo y guarda el puntuaje
     if (flujo==NULL){
       perror("Error al abrir el archivo\n\n");
     } else{
       fputs(" ",flujo);
       fputs(" ",flujo);
       fputs(nombrejugador,flujo);
       fputs(" ",flujo);
       fputs(" ",flujo);
       fputs(",",flujo);
       fputs(" ",flujo);
       fputs(" ",flujo);
       fprintf(flujo,"%d",puntos);
       fputs("\n",flujo);
     }
     fflush(flujo);
     fclose(flujo);


     printf("Presione 1 para volver a jugar o 5 para salir...");
     scanf(" %i",&otravez);
      switch(otravez){
      case 1:
        categorias();  
      case 5:   
        menuPrincipal();
      default: 
        printf("\n\n Tecla no valida \n\n");          
      }

   }
   
   //verificar si adivino la palabra
   espacios=0; 
		
	 for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		
	 if (espacios == 0){
			printf("\n\n FELICIDADES GANASTE!! :) \n\n");
      printf("\n\n Puntuacion final: %d \n\n",puntos);
      FILE * flujo = fopen("record.txt","a"); //abre el arhcivo de txt y guarda el puntuaje
     if (flujo==NULL){
       perror("Error al abrir el archivo\n\n");
     } else{
       fputs(" ",flujo);
       fputs(" ",flujo);
       fputs(nombrejugador,flujo);
       fputs(" ",flujo);
       fputs(" ",flujo);
       fputs(",",flujo);
       fputs(" ",flujo);
       fputs(" ",flujo);
       fprintf(flujo,"%d",puntos);
       fputs("\n",flujo);
     }
     fflush(flujo);
     fclose(flujo);

			printf(" Presione 1 para volver a jugar o 5 para salir... ");
      scanf(" %i",&otravez);
      switch(otravez){
      case 1:
        categorias();  
      case 5:   
        menuPrincipal();
      default: 
        printf("\n\n Tecla no valida \n\n");          
      }
		}
		
   printf("\n\n Escoja una letra: "); //recibe la letra del jugador
   scanf(" %c",&letra);

   //verificar si la letra ingresada se encuentra en la palabra 
   for (j=0;j<longitud;j++){ 
      if (j==longitud && aciertos==0){
        intentos ++;
        puntos -= 100;
      }
      if (letra == palabras[opcion][j]){
        frase[j] = letra;
        aciertos ++;
      } 
   } 

   if (aciertos==0){
      intentos ++;
      puntos -= 100;
   }

  }while(intentos != 8);
  printf("\n\n");

    
}


//dibujo del ahorcado. Cada vez que el jugador falla una letra, se va formando el dibujo, cuando se completa entonces el jugador pierde y se finaliza el juego.
void fallos(int intentos) { 
	switch (intentos) {
	case 0:
		puts("Comienza el juego, exitos! ^_^");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |    ");
		puts(" |   ");
		puts(" |    ");
		puts("_|_  ");
		break;
	case 1:
		puts(" Oh no letra incorrecta! ");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |    ");
		puts(" |   ");
		puts(" |    ");
		puts("_|_  ");
		break;
	case 2:
    puts("  Otra incorrecta noooo ");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |   ");
		puts(" |    ");
		puts("_|_  ");
		break;
	case 3:
    puts("  Le quedan 4 vidas! ");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |  /  ");
		puts(" |    ");
		puts("_|_  ");
		break;
	case 4:
    puts("  3 vidas restantes :O ");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |  / \\ ");
		puts(" |    ");
		puts("_|_  ");
		break;
	case 5:
    puts("  2 vidas le quedan :( ");  
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |  / \\ ");
		puts(" |   | ");
		puts("_|_  ");
		break;
	case 6:
    puts(" Un fallo mas y se acaba la partida :( ");
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |  / \\ ");
		puts(" |   | ");
		puts("_|_ /  ");
		break;
	case 7:
		puts("  _ _ ");
		puts(" |   | ");
		puts(" |   O ");
		puts(" |  / \\ ");
		puts(" |   | ");
		puts("_|_ / \\ ");
		break;
	default: puts("Fin del juego, gracias por jugar!!!");
	}
}




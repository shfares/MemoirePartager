//Serveur responsable d'ecriture
#include <sys.ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include "defs.h"


main()
{
  int *tab_int;   //pointeur vers un tableau d'entier 
  int shmid;    //Identificateur de memoire partagee
  int i;      //Idice  de boucle
  int ret;   //code de retour du system call
  char n[100];
  printf("veuillez s'il vous plait saisir du text");
  fflush(stdout);
  scanf("%s",n[]);
  //Ecriture dans la zone memoire en utilisant le pointeur tab_int
  Srand(getpid());
  for(i = 1;i <= NB_VAL; i++){
    tab_int[i] =rand();
    printf("tab_int[%d]=%d\n",i,tab_int[i]);
    //detachement de la zone de memoire partagee
    ret=shmdt(tab_int);
    //Verification le detachement de la zone memoire du pointeur 
    if(ret == -1){
    perror("SHMDT");
    exit(3);
  }
  }
    
}

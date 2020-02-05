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
  
  //Creation d'un acces a une zone de memoire partagee
  shmid=shmget((key_t)SHM, NB_VAL*sizeof(int), IPC_Creat | S_IRUSR | S_IWUSR);  //shmget(identifiant, la taille de la memoire, option)
 //Verification de la creation de la zone memoire
 if(shmid == -1) {
    perror("SHMGET");
    exit(1);
    }
  //Attachement du pointeur a la memoire partager 
  tab_int=(int *)shmat(shmid,null,0); //shmat(shmid = Identifiant , Null = Lancement au moment de la creation de l'espace memoire, 0 = Ne prend pas d'option)
  //Verification de la creation du pointeur 
  if(tab_int == (int *)-1){
    perror("SHMAT");
    exit(2);
  }
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

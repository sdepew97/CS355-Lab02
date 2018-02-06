#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _REENTRANT
#define _REENTRANT
#endif

//method declarations
void *thread_function(void *string);

int main(int argc, char *argv[]) {
 
  //array of pthreads 
  pthread_t *threads[argc-1];
  //pthread_t *threads = (pthread_t *) malloc( argc * sizeof(pthread_t) )
  
    for(int i=0; i<argc; i++) {
      //create thread
      pthread_create(&(threads[i]), 0, thread_function, argv[i]);

      //link thread
      pthread_join(threads[i], 0);
    }
  
  return 0; 
}

void *thread_function(void *string){
  int seed_value = 0;
  int random_times = rand_r(&seed_value)%10 + 1; //number between 1 and 10
  
  printf("%s will print %d times", string, random_times); 
  for(int i=0; i<random_times; i++) {
      printf("%s", string); 
  }
  printf("\n"); 
}

#include<semaphore.h>
#include<bits/stdc++.h>
#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>

#define UNLOCKED 0
#define LOCKED 1
#define UNASSIGNED_OWNER 0


sem_t s;

void handler(int signal) {
  sem_post(&s);
}

void *singsong(void *param) {
  sem_wait(&s);
  printf("Waiting until a signal releases...\n");
}

int main() {
  int ok = sem_init(&s, 0, 0);
  if (ok == -1) {
    perror("Could not create unnamed semaphore");
    return 1;
  }
  signal(SIGINT, handler); 

  pthread_t tid;
  pthread_create(&tid, NULL, singsong, NULL);
  pthread_exit(NULL); 
}

//--------------------First the data structure and initialization code.
typedef struct mutex_{
  atomic_int_least8_t lock;
  pthread_t owner;
} mutex;


int mutex_init(mutex* mtx){
  if(!mtx){
    return 0;
  }
  atomic_init(&mtx->lock, UNLOCKED);
  mtx->owner = UNASSIGNED_OWNER;
  return 1;
}

//------------This is the initialization code, nothing fancy here. We set the state of the mutex to unlocked and set the owner to locked.-----------
//It initializes a variable that we will keep as the unlocked state.
int mutex_lock(mutex* mtx){
  int_least8_t zero = UNLOCKED;
  while(!atomic_compare_exchange_weak_explicit
  (&mtx->lock,
  &zero,
  LOCKED,
  memory_order_seq_cst,
  memory_order_seq_cst)){
    zero = UNLOCKED;
    sched_yield(); 
  }
  mtx->owner = pthread_self();
  return 1;
}

// instruction supported by most modern architectures (on x86 it’s lock cmpxchg). The pseudocode for this operation looks like this below,
int atomic_compare_exchange_pseudo(int* addr1, int* addr2, int val){
  if(*addr1 == *addr2){
    *addr1 = val;
    return 1;
  }else{
    *addr2 = *addr1;
    return 0;
  }
}


//-------------------------------------------------------------------


int mutex_unlock(mutex* mtx){
  if(unlikely(pthread_self() != mtx->owner)){
    return 0; 
  }
  int_least8_t one = 1;
  mtx->owner = UNASSIGNED_OWNER;
  if(!atomic_compare_exchange_strong_explicit(
  &mtx->lock,
  &one,
  UNLOCKED,
  memory_order_seq_cst,
  memory_order_seq_cst)){
    return 0;
  }
  return 1;
}

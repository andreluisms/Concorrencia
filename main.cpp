#include "DinPhilosMonitor.h"
#include <thread>
#include<unistd.h>
#include <stdlib.h>  
#include <time.h> 
const int TIMELIMIT=500;
DinPhilosMonitor din;

void comendopensando(int i){
  int iSecret;
  int count = 0;
  while (count < TIMELIMIT){
     // inicializa a semente
     srand (time(NULL));
//     sleep(1);
     // numero aleatorio entre 1 e 3
     iSecret = rand() % 4 + 1;
     count += iSecret;
     din.log("[Phil " + to_string(i) + "] Thinking for " + to_string(iSecret) + " secs.");
     sleep(iSecret);
     din.log("[Phil " + to_string(i) + "] Hungry... ");
     din.pickup(i);
     din.putdown(i);
  }   
}

int main(){
  thread* threads[5];
  for (int i =0; i < 5; i++){
     threads[i] = new thread(comendopensando, i);  
  }

  for (int i =0; i < 5; i++){
     threads[i]->join();  
  }
  return 0;
}
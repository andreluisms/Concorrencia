#include "DinPhilosMonitor.h"

DinPhilosMonitor::DinPhilosMonitor(){
   for (int i = 0; i< 5; i++){
      state[i] = THINKING;
      self[i].unlock();
   }
   print.unlock();
   log("[MON] Monitor created");
}

DinPhilosMonitor::~DinPhilosMonitor(){
   DinPhilosMonitor::log("[Mon] Monitor destroyed");
}

void DinPhilosMonitor::pickup(int i){
   state[i] = HUNGRY;
   test(i);
   if (state[i] != EATING){
      log("[Phil " + to_string(i) + "] *****************Blocking...");
      self[i].lock();
            log("[Phil " + to_string(i) + "] ************Unblocking...");
   }
   log("[Phil " + to_string(i) + "] Eating...");
}

void DinPhilosMonitor::putdown(int i){
   state[i] = THINKING;
   test((i+4)%5);
   test((i+1)%5);
}

void DinPhilosMonitor::test(int i){
   if((state[(i+4)%5]!=EATING) &&
      (state[i]==HUNGRY)&&
      (state[(i+1)%5]!=EATING)){
          state[i] = EATING;
          self[i].unlock();
    }
}

void DinPhilosMonitor::log(string str){
   print.lock();
   cout << str << endl;
   print.unlock();
}
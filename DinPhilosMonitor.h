#ifndef DINPHILOSMONITOR_H
#define DINPHILOSMONITOR_H
#include<mutex>
#include<iostream>
#include<string>

using namespace std;
class DinPhilosMonitor{
   private:
      mutex print;
      const int THINKING = 0;
      const int HUNGRY = 1;
      const int EATING = 2;
      int state[5];
      mutex self[5];
      void test(int i);
   
   public:
      DinPhilosMonitor();
      ~DinPhilosMonitor();
      void pickup(int i);
      void putdown(int i);
      void log(string str);
};

#endif
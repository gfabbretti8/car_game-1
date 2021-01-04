#include "src/road.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "src/utilities.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(){

  initTermios(); //setup of the terminal
  srand( (unsigned) time(0));

  Road road;
  unsigned int time = 100000; // 1/10 of a sec

  while(1){
    road.move();
    road.print();
    road.car.move();
    road.car_consume_fuel();
    road.car_add_fuel();
    road.car_consume_life();
    road.car.print();
    road.reposition_cursor();
    usleep(time);
  }
}

#include "car.h"

class Road{

protected:
  static const int n_rows = 30;
  static const int n_cols = 80;
  char matrix[n_rows][n_cols];

public:

  Car car;
  Road();
  inline void print(){ print_map(); print_info(); }
  void reposition_cursor();
  void car_consume_fuel();
  void move();
  char spawn_obj();
  void print_map();
  void print_info();

};

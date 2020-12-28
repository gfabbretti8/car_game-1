class Car{
 protected:
  int position_x[3];
  int position_y[3];
  int bound_y;
  int fuel;

 public:
  Car(int x, int y);
  inline void consume_fuel(){ fuel--; }
  inline int get_fuel_level(){ return fuel;}
  void print();
  void move();

};

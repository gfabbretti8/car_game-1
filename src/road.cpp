#include "road.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */

using namespace std;

Road::Road() :car(n_rows, n_cols){

  for(int i=0; i<n_rows; i++){
    for(int j=0; j<n_cols; j++){
      matrix[i][j] = ' ';
    }
  }
  car = Car(n_rows, n_cols);
}

void Road::reposition_cursor(){
  cout << "\033[" + to_string(n_rows+2) + ";0H";
  cout.flush();
  cin.clear();
  cout.clear();
}

void Road::move(){

  for(int i=n_rows-1; i>0; i--){
    for(int j=0; j<n_cols; j++){
      matrix[i][j] = matrix[i-1][j];
    }
  }

  for(int i=0; i<n_cols; i++){
    matrix[0][i] = spawn_obj();
  }

}

char Road::spawn_obj(){

  int rand_number = rand()%1000;

  if(rand_number < 1){
    return 'G';
  } else {
    return ' ';
  }
}

void Road::print_map(){
  cout << "\033[0;0H";

  for(int i=0; i<n_rows; i++){
    cout<<"#";
    for(int j=0; j<n_cols; j++){
        cout<<matrix[i][j];
    }
    cout<<"#\n";
  }
}

void Road::print_info(){
  cout << "\033[0;" + to_string(n_cols+5) + "H";
  cout<<" Fuel level: "<< car.get_fuel_level() << "\033[K";
}

void Road::car_consume_fuel(){
  car.consume_fuel();
  if(car.get_fuel_level() == 0){
    cout << "YOU LOST!\n";
  }
}

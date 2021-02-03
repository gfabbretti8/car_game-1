#include "road.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */

using namespace std;

Road::Road() :car(n_rows, n_cols){ //Constructor

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

  if(rand_number == 0){
    return 'G';
  } else if(rand_number == 1){
    return 'N';
  } else {
    return ' ';
  }
}

void Road::print_map(){
  cout << "\033[0;0H"; // character that position cursor at row 0 col 0

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
  cout << " Fuel level: "<< car.get_fuel_level() << "\033[K"; //delete the rest of the line
  cout << " Life:"<< car.get_life() <<"\033[K";
}

void Road::car_consume_fuel(){
  car.consume_fuel();
  if(car.get_fuel_level() == 0){
    cout << "YOU LOST!\n";
    exit(1);
  }
}


void Road::car_add_fuel(){ // sono palesemente sbagliate 
  //  for(int i=0; i<n_rows; i++){
  //   for(int j=0; j<n_cols; j++){
  //    if (if car_positon == 'G'){
  //       car.add_fuel();
  //     } 
  //   }
  //  }
  
  // ALGO:
  //  1. Get car_position
  //  2. Get G_positions
  //  3. If car_position in G_positions
  //       then carr.add_fuel()

  int car_position_x = car.get_position_x();
  int car_position_y = car.get_position_y();
  
  for(int i=car_position_x; i<car_position_x+3; i++){
    if (matrix[car_position_x][car_position_y] == 'G'){
        car.add_fuel();
    } 
  }
}


void Road::car_consume_life(){  // Not Working
  int car_position_x = car.get_position_x();
  int car_position_y = car.get_position_y();
  
  for(int i=car_position_x; i<car_position_x+3; i++){
    if (matrix[car_position_x][car_position_y] == 'N'){
        car.consume_life();
    }
    if (car.get_life() == 0){
      cout << "Life Finished - Game Over!!";
    }
  }
}
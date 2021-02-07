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

void Road::init_game(){
  points = 0;
  level = 1;
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

  bool appears_G = (rand() % 10000) < 4;
  bool appears_N = (rand() % 10000) < level*2; // Each level increase probability a Nail appears 
  
  if(appears_G){
    return 'G';
  } else if(appears_N){
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
  cout << " Life: " << car.get_life() << "\033[K";
  cout << " Points: " << points << "\033[K"; 
  cout << " Level: " << level << "\033[K";
}

void Road::car_consume_fuel(){
  car.consume_fuel();
  if(car.get_fuel_level() == 0){
    cout << " | No Fuel --> YOU LOST!\n";
    game_over();
  }
}

void Road::add_level(){
  if (points%100 == 0){
    level += 1;
    cout << "New Level!!\n";
  }
}


void Road::car_add_fuel(){  
  int car_position_x = car.get_position_x();
  int car_position_y = car.get_position_y();

  for(int pos_y=car_position_y; pos_y<car_position_y+3; pos_y++){
    if (matrix[car_position_x][pos_y] == 'G'){
      car.add_fuel();
    }
  } 
  
}


void Road::car_consume_life(){ 
  int car_position_x = car.get_position_x();
  int car_position_y = car.get_position_y();
  
  for(int pos_y=car_position_y; pos_y<car_position_y+3; pos_y++){
    if (matrix[car_position_x][pos_y] == 'N'){
        car.consume_life();
    }
    if (car.get_life() == 0){
      cout << "Life Finished - Game Over!!";
      game_over();
    }
  }
}

void Road::game_over(){
  exit(1);
}

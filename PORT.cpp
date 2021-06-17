#include "PORT.hpp"

/*

PORT parent class method definitions. There is no default constructor

*/


//setter functions

void PORT::set_type(int type){

  this->type = type;
}

void PORT::set_owner(COMPONENT* owner){

  this->owner = owner;
}

void PORT::set_name(std::string name){

  this->name = name;
}


//getter functions

int PORT::get_type(){

  return type;
}


COMPONENT* PORT::get_owner(){

  return owner;
}

std::string PORT::get_name(){

  return name;
}





/*

INPUT_PORT class methods

*/

//constructor

INPUT_PORT::INPUT_PORT(){

  //default constructor, set type to 0
  this->type = 0;
}


//connectivity functions

void INPUT_PORT::connect(OUTPUT_PORT &output_port){

  //store addresses passed as parameter as input address
  this->input_address = &output_port;
  //store current port address in parameter por fanout address vector
  output_port.add_fanout_address(this);

}


//getter functions

OUTPUT_PORT* INPUT_PORT::get_input_address(){

  //return OUTPUT_PORT address stored at input_address variable
  return input_address;

}


//external getter functions

bool INPUT_PORT::get_input(){

  return (*input_address).get_state();
}






/*

OUTPUT_PORT class methods

*/

//constructor

OUTPUT_PORT::OUTPUT_PORT(){

  //default constructor, set type to 1
  this->type = 1;
  //initialise state to 0
  this->state = 0;
}


//connectivity functions

void OUTPUT_PORT::add_fanout_address(INPUT_PORT *input_port){

  //Add input port to fanout address list
  fanout_addresses.push_back(input_port);
}


//getter functions

INPUT_PORT* OUTPUT_PORT::get_fanout_address(int i){

  //return INPUT_PORT address indexed with int i
  return fanout_addresses[i];
}

int OUTPUT_PORT::get_fanout_size(){

  return fanout_addresses.size();
}

bool OUTPUT_PORT::get_state(){

  return state;
}


//setter functions

void OUTPUT_PORT::set_state(bool state){

  this->state = state;
}

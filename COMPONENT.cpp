#include "COMPONENT.hpp"

/*

COMPONENT parent class method definitions. There is no default constructor*

*/


//Constructor

COMPONENT::COMPONENT(){

  this->initialisation_flag = 0;
}


//setter functions

void COMPONENT::set_ID(int id){

  this->id = id;
}

void COMPONENT::set_name(std::string name){

  this->name = name;
}

void COMPONENT::set_owner(COMPONENT* owner){

  this->owner = owner;
}


//getter functions


std::string COMPONENT::get_type(){

  return type;
}

int COMPONENT::get_ID(){

  return id;
}

std::string COMPONENT::get_name(){

  return name;
}

COMPONENT* COMPONENT::get_owner(){

  return owner;
}

void COMPONENT::update_output(std::queue<COMPONENT*> &update_queue){

  //does nothing, only to be overridden
  std::cout << "Component paretn class method called" << std::endl;
}



/*

AND class methods

*/

//constructor


AND::AND(){

  //set port parameters, connections only defined for higher level components

  //port type
  // A.set_type(0);
  // B.set_type(0);
  // C.set_type(1);

  //ownership to current object, using "this" pointer
  A.set_owner(this);
  B.set_owner(this);
  C.set_owner(this);

  //port port_name
  A.set_name("INPUT_A");
  B.set_name("INPUT_B");
  C.set_name("OUTPUT_C");

}


//update function

void AND::update_output(std::queue<COMPONENT*> &update_queue){

  //store previous state

  bool prev_state = C.get_state();

  /*

  A.get_input() returns the state of the output port connected to A.
  B.get_input() returns the state of the output port connected to B.

  C.set_state(bool paramter) updates C state to bool parameter.

  */

  C.set_state(A.get_input() && B.get_input());


  //push component fanout addresses to update_queue

  if (prev_state != C.get_state() || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < C.get_fanout_size(); i++){

      update_queue.push((*(C.get_fanout_address(i))).get_owner());
    }
  }

}



/*

NOT class methods

*/

//Constructor

NOT::NOT(){

  //set port parameters, connections only defined for higher level components

  //port type
  // A.set_type(0);
  // B.set_type(1);

  //ownership to current object, using "this" pointer
  A.set_owner(this);
  B.set_owner(this);

  //port port_name
  A.set_name("INPUT_A");
  B.set_name("OUTPUT_B");

}

//update function

void NOT::update_output(std::queue<COMPONENT*> &update_queue){

  //store previous state

  bool prev_state = B.get_state();

  /*

  A.get_input() returns the state of the output port connected to A.

  B.set_state(bool paramter) updates B state to bool parameter.

  */

  B.set_state(!(A.get_input()));

  //push component fanout addresses to update_queue

  if (prev_state != B.get_state() || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < B.get_fanout_size(); i++){

      update_queue.push((*(B.get_fanout_address(i))).get_owner());
    }
  }
}


/*

BUFFER class methods

*/

//Constructor

BUFFER::BUFFER(){

  //ownership to current object, using "this" pointer
  A.set_owner(this);
  B.set_owner(this);

  //port port_name
  A.set_name("INPUT_A");
  B.set_name("OUTPUT_B");

}

//update function

void BUFFER::update_output(std::queue<COMPONENT*> &update_queue){

  //store previous state

  bool prev_state = B.get_state();

  /*

  A.get_input() returns the state of the output port connected to A.

  B.set_state(bool paramter) updates B state to bool parameter.

  */

  B.set_state(A.get_input());

  //push component fanout addresses to update_queue

  if (prev_state != B.get_state() || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < B.get_fanout_size(); i++){

      update_queue.push((*(B.get_fanout_address(i))).get_owner());
    }
  }
}

/*

I_BUFFER class methods

*/

//Constructor

I_BUFFER::I_BUFFER(){

  //ownership to current object, using "this" pointer
  A.set_owner(this);
  B.set_owner(this);

  //port port_name
  A.set_name("INPUT_A");
  B.set_name("OUTPUT_B");

}




//ownership
void I_BUFFER::set_owner(COMPONENT* owner){

  this->owner = owner;
  //ports owner by buffer owner
  A.set_owner(owner);
  B.set_owner(owner);

}


/*

TRI_BUFFER class methods

*/

//Constructor

TRI_BUFFER::TRI_BUFFER(){

  //ownership to current object, using "this" pointer
  A.set_owner(this);
  B.set_owner(this);
  ENABLE.set_owner(this);

  //port port_name
  A.set_name("INPUT_A");
  B.set_name("OUTPUT_B");
  ENABLE.set_name("ENABLE");

}

//update function

void TRI_BUFFER::update_output(std::queue<COMPONENT*> &update_queue){

  //store previous state

  bool prev_state = B.get_state();

  /*

  A.get_input() returns the state of the output port connected to A.

  B.set_state(bool paramter) updates B state to bool parameter.

  */

  B.set_state(A.get_input());


  //push component fanout addresses to update_queue

  if (ENABLE.get_input()){

    if (prev_state != B.get_state() || !(this->initialisation_flag)){

      this->initialisation_flag = 1;

      for (int i = 0; i < B.get_fanout_size(); i++){

        update_queue.push((*(B.get_fanout_address(i))).get_owner());
      }
    }

  }

}

#include "FULL_ADDER.hpp"
#include <iostream>
#include <vector>


/*

FULL_ADDER class methods

*/

//constructor


FULL_ADDER::FULL_ADDER(){



  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_A.set_owner(this);
  INPUT_BUFFER_B.set_owner(this);
  INPUT_BUFFER_CARRY_IN.set_owner(this);

  //outputs
  OUTPUT_BUFFER_CARRY.set_owner(this);
  OUTPUT_BUFFER_SUM.set_owner(this);

  //internal component
  HALF_ADDER_1.set_owner(this);
  HALF_ADDER_2.set_owner(this);
  OR_1.set_owner(this);


  //names


  //inputs
  INPUT_BUFFER_A.set_name("INPUT_A");
  INPUT_BUFFER_B.set_name("INPUT_B");
  INPUT_BUFFER_CARRY_IN.set_name("CARRY_IN");

  //outputs
  OUTPUT_BUFFER_CARRY.set_name("OUTPUT_CARRY");
  OUTPUT_BUFFER_SUM.set_name("OUTPUT_SUM");





  /*

  Define internal component connections

  */

  //HALF_ADDER_1
  HALF_ADDER_1.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A.B);
  HALF_ADDER_1.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B.B);

  //HALF_ADDER_2
  HALF_ADDER_2.INPUT_BUFFER_A.A.connect(HALF_ADDER_1.OUTPUT_BUFFER_SUM.B);
  HALF_ADDER_2.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_CARRY_IN.B);

  //OR_1
  OR_1.INPUT_BUFFER_A.A.connect(HALF_ADDER_2.OUTPUT_BUFFER_CARRY.B);
  OR_1.INPUT_BUFFER_B.A.connect(HALF_ADDER_1.OUTPUT_BUFFER_CARRY.B);

  //OUTPUT_BUFFER_SUM
  OUTPUT_BUFFER_SUM.A.connect(HALF_ADDER_2.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_CARRY
  OUTPUT_BUFFER_CARRY.A.connect(OR_1.OUTPUT_BUFFER_C.B);



}

//update function

void FULL_ADDER::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;

  prev_state.push_back(OUTPUT_BUFFER_CARRY.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM.B.get_state());

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_A.update_output(internal_update_queue);
  INPUT_BUFFER_B.update_output(internal_update_queue);
  INPUT_BUFFER_CARRY_IN.update_output(internal_update_queue);

  while(!internal_update_queue.empty()){

    if ((*(internal_update_queue.front())).get_owner() == this){

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();
    }

    else {

      internal_update_queue.pop();
    }

  }


  if (prev_state[0] != OUTPUT_BUFFER_CARRY.B.get_state() || prev_state[1] != OUTPUT_BUFFER_SUM.B.get_state() || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM.B.get_fanout_address(i))).get_owner());
    }

  }


}

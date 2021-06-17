#include "HALF_ADDER.hpp"
#include <iostream>
#include <vector>


/*

HALF_ADDER class methods

*/

//constructor


HALF_ADDER::HALF_ADDER(){



  //set buffer ownership, using "this" pointer
  INPUT_BUFFER_A.set_owner(this);
  INPUT_BUFFER_B.set_owner(this);
  OUTPUT_BUFFER_CARRY.set_owner(this);
  OUTPUT_BUFFER_SUM.set_owner(this);

  //buffer name
  INPUT_BUFFER_A.set_name("INPUT_A");
  INPUT_BUFFER_B.set_name("INPUT_B");
  OUTPUT_BUFFER_CARRY.set_name("OUTPUT_CARRY");
  OUTPUT_BUFFER_SUM.set_name("OUTPUT_SUM");
  //set internal component ownership
  AND_1.set_owner(this);
  XOR_1.set_owner(this);

  /*

  Define internal component connections

  */

  AND_1.A.connect(INPUT_BUFFER_A.B);
  AND_1.B.connect(INPUT_BUFFER_B.B);

  XOR_1.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A.B);
  XOR_1.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B.B);

  OUTPUT_BUFFER_CARRY.A.connect(AND_1.C);
  OUTPUT_BUFFER_SUM.A.connect(XOR_1.OUTPUT_BUFFER_C.B);


}


//update function

void HALF_ADDER::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;

  prev_state.push_back(OUTPUT_BUFFER_CARRY.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM.B.get_state());

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_A.update_output(internal_update_queue);
  INPUT_BUFFER_B.update_output(internal_update_queue);

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

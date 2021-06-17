#include "NAND.hpp"
#include <iostream>


/*

NAND class methods

*/

//constructor


NAND::NAND(){



  //set buffer ownership, using "this" pointer
  INPUT_BUFFER_A.set_owner(this);
  INPUT_BUFFER_B.set_owner(this);
  OUTPUT_BUFFER_C.set_owner(this);

  //buffer name
  INPUT_BUFFER_A.set_name("INPUT_A");
  INPUT_BUFFER_B.set_name("INPUT_B");
  OUTPUT_BUFFER_C.set_name("OUTPUT_C");

  //set internal component ownership
  AND_1.set_owner(this);
  NOT_1.set_owner(this);

  /*

  Define internal component connections

  */

  //AND_1 input port A connected to NAND interface port A
  AND_1.A.connect(INPUT_BUFFER_A.B);

  //AND_1 input port B connected to NAND interface port B
  AND_1.B.connect(INPUT_BUFFER_B.B);

  //NOT_1 input port A connected to AND_1 output port C
  NOT_1.A.connect(AND_1.C);

  //NAND interface port C connected to NOT_1 output port B
  OUTPUT_BUFFER_C.A.connect(NOT_1.B);

}

//update function

void NAND::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  bool prev_state = OUTPUT_BUFFER_C.B.get_state();
  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_A.update_output(internal_update_queue);
  INPUT_BUFFER_B.update_output(internal_update_queue);

  //std::cout << INPUT_BUFFER_A.B.get_state() << std::endl;

  while(!internal_update_queue.empty()){

    if ((*(internal_update_queue.front())).get_owner() != this){
      
      break;
    }

    (*(internal_update_queue.front())).update_output(internal_update_queue);
    internal_update_queue.pop();

    //std::cout << " run " << std::endl;
  }

  if (prev_state != OUTPUT_BUFFER_C.B.get_state() || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < OUTPUT_BUFFER_C.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_C.B.get_fanout_address(i))).get_owner());
    }

  }


  //add functionality to avoid leaks beforehand
}

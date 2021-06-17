#include "SR_LATCH.hpp"
#include <iostream>
#include <vector>


/*

SR_LATCH class methods

*/

//constructor


SR_LATCH::SR_LATCH(){

  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_SET.set_owner(this);
  INPUT_BUFFER_RESET.set_owner(this);

  //outputs
  OUTPUT_BUFFER_Q.set_owner(this);
  OUTPUT_BUFFER_Q_NOT.set_owner(this);

  //internal logic
  NAND_1.set_owner(this);
  NAND_2.set_owner(this);


  /*

  Define internal component connections

  */

  //NAND_1
  NAND_1.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_RESET.B);
  NAND_1.INPUT_BUFFER_B.A.connect(NAND_2.OUTPUT_BUFFER_C.B);

  //NAND_2
  NAND_2.INPUT_BUFFER_A.A.connect(NAND_1.OUTPUT_BUFFER_C.B);
  NAND_2.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_SET.B);

  //OUTPUT_BUFFER_Q
  OUTPUT_BUFFER_Q.A.connect(NAND_1.OUTPUT_BUFFER_C.B);

  //OUTPUT_BUFFER_Q
  OUTPUT_BUFFER_Q_NOT.A.connect(NAND_2.OUTPUT_BUFFER_C.B);

}

//update function

void SR_LATCH::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;

  prev_state.push_back(OUTPUT_BUFFER_Q.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_Q_NOT.B.get_state());

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_SET.update_output(internal_update_queue);
  INPUT_BUFFER_RESET.update_output(internal_update_queue);

  while(!internal_update_queue.empty()){

    if ((*(internal_update_queue.front())).get_owner() == this){

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();
    }

    else {

      internal_update_queue.pop();
    }

  }


  if (prev_state[0] != OUTPUT_BUFFER_Q.B.get_state()  || !(this->initialisation_flag)){

    this->initialisation_flag = 1;

    for (int i = 0; i < OUTPUT_BUFFER_Q.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_Q.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_Q_NOT.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_Q_NOT.B.get_fanout_address(i))).get_owner());
    }

  }


}

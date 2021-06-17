#include "D_LATCH_LOAD.hpp"
#include <iostream>
#include <vector>


/*

D_LATCH_LOAD class methods

*/

//constructor


D_LATCH_LOAD::D_LATCH_LOAD(){

  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_DATA.set_owner(this);
  INPUT_BUFFER_CLK.set_owner(this);
  INPUT_BUFFER_LOAD.set_owner(this);

  //outputs
  OUTPUT_BUFFER_Q.set_owner(this);
  OUTPUT_BUFFER_Q_NOT.set_owner(this);

  //memory
  D_LATCH_1.set_owner(this);

  //internal logic
  AND_1.set_owner(this);
  AND_2.set_owner(this);
  OR_1.set_owner(this);
  NOT_1.set_owner(this);

  /*

  Define internal component connections

  */

  //NOT_1
  NOT_1.A.connect(INPUT_BUFFER_LOAD.B);

  //AND_1
  AND_1.A.connect(INPUT_BUFFER_LOAD.B);
  AND_1.B.connect(INPUT_BUFFER_DATA.B);

  //AND_2
  AND_2.A.connect(D_LATCH_1.OUTPUT_BUFFER_Q.B);
  AND_2.B.connect(NOT_1.B);

  //OR_1
  OR_1.INPUT_BUFFER_A.A.connect(AND_2.C);
  OR_1.INPUT_BUFFER_B.A.connect(AND_1.C);

  //D_LATCH_1
  D_LATCH_1.INPUT_BUFFER_DATA.A.connect(OR_1.OUTPUT_BUFFER_C.B);
  D_LATCH_1.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);

  //OUTPUT_BUFFER_Q
  OUTPUT_BUFFER_Q.A.connect(D_LATCH_1.OUTPUT_BUFFER_Q.B);
  OUTPUT_BUFFER_Q_NOT.A.connect(D_LATCH_1.OUTPUT_BUFFER_Q_NOT.B);


}

//update function

void D_LATCH_LOAD::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;

  prev_state.push_back(OUTPUT_BUFFER_Q.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_Q_NOT.B.get_state());

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_CLK.update_output(internal_update_queue);
  INPUT_BUFFER_DATA.update_output(internal_update_queue);
  INPUT_BUFFER_LOAD.update_output(internal_update_queue);


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

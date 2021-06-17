#include "XOR.hpp"
#include <iostream>


/*

XOR class methods

*/

//constructor


XOR::XOR(){



  //set buffer ownership, using "this" pointer
  INPUT_BUFFER_A.set_owner(this);
  INPUT_BUFFER_B.set_owner(this);
  OUTPUT_BUFFER_C.set_owner(this);

  //buffer name
  INPUT_BUFFER_A.set_name("INPUT_A");
  INPUT_BUFFER_B.set_name("INPUT_B");
  OUTPUT_BUFFER_C.set_name("OUTPUT_C");

  //set internal component ownership
  NAND_1.set_owner(this);
  NAND_2.set_owner(this);
  NAND_3.set_owner(this);
  NAND_4.set_owner(this);

  /*

  Define internal component connections

  */

  NAND_1.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A.B);
  NAND_1.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B.B);

  NAND_2.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A.B);
  NAND_2.INPUT_BUFFER_B.A.connect(NAND_1.OUTPUT_BUFFER_C.B);

  NAND_3.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_B.B);
  NAND_3.INPUT_BUFFER_B.A.connect(NAND_1.OUTPUT_BUFFER_C.B);

  NAND_4.INPUT_BUFFER_A.A.connect(NAND_2.OUTPUT_BUFFER_C.B);
  NAND_4.INPUT_BUFFER_B.A.connect(NAND_3.OUTPUT_BUFFER_C.B);

  OUTPUT_BUFFER_C.A.connect(NAND_4.OUTPUT_BUFFER_C.B);

}
//update function

  void XOR::update_output(std::queue<COMPONENT*> &external_update_queue){

    //store previous state
    bool prev_state = OUTPUT_BUFFER_C.B.get_state();
    //internal update queue
    std::queue<COMPONENT*> internal_update_queue;

    INPUT_BUFFER_A.update_output(internal_update_queue);
    INPUT_BUFFER_B.update_output(internal_update_queue);

    //std::cout << internal. << std::endl;


    while(!internal_update_queue.empty()){

      if ((*(internal_update_queue.front())).get_owner() != this){

        break;
      }

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();

    }

    if (prev_state != OUTPUT_BUFFER_C.B.get_state() || !(this->initialisation_flag)){

      this->initialisation_flag = 1;

      for (int i = 0; i < OUTPUT_BUFFER_C.B.get_fanout_size(); i++ ){

        external_update_queue.push((*(OUTPUT_BUFFER_C.B.get_fanout_address(i))).get_owner());
      }

    }


    //add functionality to avoid leaks beforehand
  }

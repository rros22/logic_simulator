#include "ADDER_8.hpp"
#include <iostream>
#include <vector>


/*

ADDER_8 class methods

*/

//constructor


ADDER_8::ADDER_8(){


  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_A0.set_owner(this);
  INPUT_BUFFER_A1.set_owner(this);
  INPUT_BUFFER_A2.set_owner(this);
  INPUT_BUFFER_A3.set_owner(this);
  INPUT_BUFFER_A4.set_owner(this);
  INPUT_BUFFER_A5.set_owner(this);
  INPUT_BUFFER_A6.set_owner(this);
  INPUT_BUFFER_A7.set_owner(this);

  INPUT_BUFFER_B0.set_owner(this);
  INPUT_BUFFER_B1.set_owner(this);
  INPUT_BUFFER_B2.set_owner(this);
  INPUT_BUFFER_B3.set_owner(this);
  INPUT_BUFFER_B4.set_owner(this);
  INPUT_BUFFER_B5.set_owner(this);
  INPUT_BUFFER_B6.set_owner(this);
  INPUT_BUFFER_B7.set_owner(this);

  //outputs
  OUTPUT_BUFFER_SUM_0.set_owner(this);
  OUTPUT_BUFFER_SUM_1.set_owner(this);
  OUTPUT_BUFFER_SUM_2.set_owner(this);
  OUTPUT_BUFFER_SUM_3.set_owner(this);
  OUTPUT_BUFFER_SUM_4.set_owner(this);
  OUTPUT_BUFFER_SUM_5.set_owner(this);
  OUTPUT_BUFFER_SUM_6.set_owner(this);
  OUTPUT_BUFFER_SUM_7.set_owner(this);

  OUTPUT_BUFFER_CARRY.set_owner(this);

  //internal logic
  FULL_ADDER_1.set_owner(this);
  FULL_ADDER_2.set_owner(this);
  FULL_ADDER_3.set_owner(this);
  FULL_ADDER_4.set_owner(this);
  FULL_ADDER_5.set_owner(this);
  FULL_ADDER_6.set_owner(this);
  FULL_ADDER_7.set_owner(this);
  FULL_ADDER_8.set_owner(this);



  /*

  Define internal component connections

  */

  //FULL_ADDER_1
  FULL_ADDER_1.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A0.B);
  FULL_ADDER_1.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B0.B);
  FULL_ADDER_1.INPUT_BUFFER_CARRY_IN.A.connect(INPUT_BUFFER_CARRY_IN.B);

  //FULL_ADDER_2
  FULL_ADDER_2.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A1.B);
  FULL_ADDER_2.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B1.B);
  FULL_ADDER_2.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_1.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_3.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A2.B);
  FULL_ADDER_3.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B2.B);
  FULL_ADDER_3.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_2.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_4.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A3.B);
  FULL_ADDER_4.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B3.B);
  FULL_ADDER_4.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_3.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_5.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A4.B);
  FULL_ADDER_5.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B4.B);
  FULL_ADDER_5.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_4.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_6.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A5.B);
  FULL_ADDER_6.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B5.B);
  FULL_ADDER_6.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_5.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_7.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A6.B);
  FULL_ADDER_7.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B6.B);
  FULL_ADDER_7.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_6.OUTPUT_BUFFER_CARRY.B);

  //FULL_ADDER_1
  FULL_ADDER_8.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_A7.B);
  FULL_ADDER_8.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_B7.B);
  FULL_ADDER_8.INPUT_BUFFER_CARRY_IN.A.connect(FULL_ADDER_7.OUTPUT_BUFFER_CARRY.B);





  //OUTPUT_BUFFER_SUM_0
  OUTPUT_BUFFER_SUM_0.A.connect(FULL_ADDER_1.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_1
  OUTPUT_BUFFER_SUM_1.A.connect(FULL_ADDER_2.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_2
  OUTPUT_BUFFER_SUM_2.A.connect(FULL_ADDER_3.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_3
  OUTPUT_BUFFER_SUM_3.A.connect(FULL_ADDER_4.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_4
  OUTPUT_BUFFER_SUM_4.A.connect(FULL_ADDER_5.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_5
  OUTPUT_BUFFER_SUM_5.A.connect(FULL_ADDER_6.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_6
  OUTPUT_BUFFER_SUM_6.A.connect(FULL_ADDER_7.OUTPUT_BUFFER_SUM.B);

  //OUTPUT_BUFFER_SUM_7
  OUTPUT_BUFFER_SUM_7.A.connect(FULL_ADDER_8.OUTPUT_BUFFER_SUM.B);



  //external carry bit
  OUTPUT_BUFFER_CARRY.A.connect(FULL_ADDER_8.OUTPUT_BUFFER_CARRY.B);



  //output list definition
  output_list.push_back(&OUTPUT_BUFFER_SUM_0);
  output_list.push_back(&OUTPUT_BUFFER_SUM_1);
  output_list.push_back(&OUTPUT_BUFFER_SUM_2);
  output_list.push_back(&OUTPUT_BUFFER_SUM_3);
  output_list.push_back(&OUTPUT_BUFFER_SUM_4);
  output_list.push_back(&OUTPUT_BUFFER_SUM_5);
  output_list.push_back(&OUTPUT_BUFFER_SUM_6);
  output_list.push_back(&OUTPUT_BUFFER_SUM_7);


}


// //add to output output_list
//
// void ADDER_8::add_output(BUFFER &B0){
//
//   output_list.push_back(&B0);
// }


//update function

void ADDER_8::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;
  bool prev_state_carry;

  prev_state.push_back(OUTPUT_BUFFER_SUM_0.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_1.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_2.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_3.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_4.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_5.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_6.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_SUM_7.B.get_state());

  prev_state_carry = OUTPUT_BUFFER_CARRY.B.get_state();

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_A0.update_output(internal_update_queue);
  INPUT_BUFFER_A1.update_output(internal_update_queue);
  INPUT_BUFFER_A2.update_output(internal_update_queue);
  INPUT_BUFFER_A3.update_output(internal_update_queue);
  INPUT_BUFFER_A4.update_output(internal_update_queue);
  INPUT_BUFFER_A5.update_output(internal_update_queue);
  INPUT_BUFFER_A6.update_output(internal_update_queue);
  INPUT_BUFFER_A7.update_output(internal_update_queue);

  INPUT_BUFFER_B0.update_output(internal_update_queue);
  INPUT_BUFFER_B1.update_output(internal_update_queue);
  INPUT_BUFFER_B2.update_output(internal_update_queue);
  INPUT_BUFFER_B3.update_output(internal_update_queue);
  INPUT_BUFFER_B4.update_output(internal_update_queue);
  INPUT_BUFFER_B5.update_output(internal_update_queue);
  INPUT_BUFFER_B6.update_output(internal_update_queue);
  INPUT_BUFFER_B7.update_output(internal_update_queue);

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

  //initialisation forced run

  if (!(this->initialisation_flag)){

    this->initialisation_flag = 1;


    for (int i = 0; i < OUTPUT_BUFFER_SUM_0.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_0.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_1.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_1.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_2.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_2.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_3.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_3.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_4.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_4.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_5.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_5.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_6.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_6.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_SUM_7.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_SUM_7.B.get_fanout_address(i))).get_owner());
    }

    for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
    }



  }


  //normal update cycle

  for (int i = 0; i < output_list.size(); i++){

    if (prev_state[i] != (*(output_list[i])).B.get_state()){

      for (int i = 0; i < (*(output_list[i])).B.get_fanout_size(); i++ ){

        external_update_queue.push((*((*(output_list[i])).B.get_fanout_address(i))).get_owner());
      }
    }
  }


  if (prev_state_carry != OUTPUT_BUFFER_CARRY.B.get_state()){

    for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){

      external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
    }
  }

}

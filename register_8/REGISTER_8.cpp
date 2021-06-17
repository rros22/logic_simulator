#include "REGISTER_8.hpp"
#include <iostream>
#include <vector>


/*

REGISTER_8 class methods

*/

//constructor


REGISTER_8::REGISTER_8(){

  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_DATA_IN0.set_owner(this);
  INPUT_BUFFER_DATA_IN1.set_owner(this);
  INPUT_BUFFER_DATA_IN2.set_owner(this);
  INPUT_BUFFER_DATA_IN3.set_owner(this);
  INPUT_BUFFER_DATA_IN4.set_owner(this);
  INPUT_BUFFER_DATA_IN5.set_owner(this);
  INPUT_BUFFER_DATA_IN6.set_owner(this);
  INPUT_BUFFER_DATA_IN7.set_owner(this);

  INPUT_BUFFER_CLK.set_owner(this);

  INPUT_BUFFER_LOAD.set_owner(this);

  //outputs
  OUTPUT_BUFFER_DATA_OUT0.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT1.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT2.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT3.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT4.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT5.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT6.set_owner(this);
  OUTPUT_BUFFER_DATA_OUT7.set_owner(this);

  //memory
  D_LATCH_0.set_owner(this);
  D_LATCH_1.set_owner(this);
  D_LATCH_2.set_owner(this);
  D_LATCH_3.set_owner(this);
  D_LATCH_4.set_owner(this);
  D_LATCH_5.set_owner(this);
  D_LATCH_6.set_owner(this);
  D_LATCH_7.set_owner(this);



  /*

  Define internal component connections

  */

  //memory

  //D_LATCH_0
  D_LATCH_0.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN0.B);
  D_LATCH_0.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_0.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_1
  D_LATCH_1.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN1.B);
  D_LATCH_1.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_1.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_2
  D_LATCH_2.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN2.B);
  D_LATCH_2.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_2.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_3
  D_LATCH_3.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN3.B);
  D_LATCH_3.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_3.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_4
  D_LATCH_4.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN4.B);
  D_LATCH_4.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_4.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_5
  D_LATCH_5.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN5.B);
  D_LATCH_5.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_5.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_6
  D_LATCH_6.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN6.B);
  D_LATCH_6.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_6.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);

  //D_LATCH_7
  D_LATCH_7.INPUT_BUFFER_DATA.A.connect(INPUT_BUFFER_DATA_IN7.B);
  D_LATCH_7.INPUT_BUFFER_CLK.A.connect(INPUT_BUFFER_CLK.B);
  D_LATCH_7.INPUT_BUFFER_LOAD.A.connect(INPUT_BUFFER_LOAD.B);



  //output ports

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT0.A.connect(D_LATCH_0.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT1.A.connect(D_LATCH_1.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT2.A.connect(D_LATCH_2.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT3.A.connect(D_LATCH_3.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT4.A.connect(D_LATCH_4.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT5.A.connect(D_LATCH_5.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT6.A.connect(D_LATCH_6.OUTPUT_BUFFER_Q.B);

  //OUTPUT_BUFFER_DATA_OUT0
  OUTPUT_BUFFER_DATA_OUT7.A.connect(D_LATCH_7.OUTPUT_BUFFER_Q.B);





  //add outputs to output_list
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT0);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT1);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT2);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT3);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT4);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT5);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT6);
  output_list.push_back(&OUTPUT_BUFFER_DATA_OUT7);



}


//update function

void REGISTER_8::update_output(std::queue<COMPONENT*> &external_update_queue){

  //store previous state
  std::vector<bool> prev_state;

  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT0.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT1.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT2.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT3.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT4.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT5.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT6.B.get_state());
  prev_state.push_back(OUTPUT_BUFFER_DATA_OUT7.B.get_state());


  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_CLK.update_output(internal_update_queue);
  INPUT_BUFFER_LOAD.update_output(internal_update_queue);

  INPUT_BUFFER_DATA_IN0.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN1.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN2.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN3.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN4.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN5.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN6.update_output(internal_update_queue);
  INPUT_BUFFER_DATA_IN7.update_output(internal_update_queue);


  while(!internal_update_queue.empty()){

     if ((*(internal_update_queue.front())).get_owner() == this){

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();
     }

     else {

       internal_update_queue.pop();
     }


  }

  // //initialisation
  //
  // for (int i = 0; i < output_list.size(); i++){
  //
  //   if (!(this->initialisation_flag)){
  //
  //     for (int i = 0; i < (*(output_list[i])).B.get_fanout_size(); i++ ){
  //
  //       external_update_queue.push((*((*(output_list[i])).B.get_fanout_address(i))).get_owner());
  //     }
  //   }
  // }
  //
  // this->initialisation_flag = 1;
  //
  //
  //
  // //normal update cycle
  //
  // for (int i = 0; i < output_list.size(); i++){
  //
  //   if (prev_state[i] != (*(output_list[i])).B.get_state()){
  //
  //     for (int i = 0; i < (*(output_list[i])).B.get_fanout_size(); i++ ){
  //
  //       external_update_queue.push((*((*(output_list[i])).B.get_fanout_address(i))).get_owner());
  //     }
  //   }
  // }


}

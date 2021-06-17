#include "MULTIPLIER_4.hpp"
#include <iostream>
#include <vector>





MULTIPLIER_4::MULTIPLIER_4(){

  PORT_1.set_state(1);

  //inputs
  INPUT_BUFFER_X0.set_owner(this);
  INPUT_BUFFER_X1.set_owner(this);
  INPUT_BUFFER_X2.set_owner(this);
  INPUT_BUFFER_X3.set_owner(this);
  INPUT_BUFFER_Y0.set_owner(this);
  INPUT_BUFFER_Y1.set_owner(this);
  INPUT_BUFFER_Y2.set_owner(this);
  INPUT_BUFFER_Y3.set_owner(this);

  //outputs
  OUTPUT_BUFFER_Z0.set_owner(this);
  OUTPUT_BUFFER_Z1.set_owner(this);
  OUTPUT_BUFFER_Z2.set_owner(this);
  OUTPUT_BUFFER_Z3.set_owner(this);
  OUTPUT_BUFFER_Z4.set_owner(this);
  OUTPUT_BUFFER_Z5.set_owner(this);
  OUTPUT_BUFFER_Z6.set_owner(this);
  OUTPUT_BUFFER_Z7.set_owner(this);

  //adders
  HA_0.set_owner(this);
  FA_1.set_owner(this);
  FA_2.set_owner(this);
  FA_3.set_owner(this);

  HA_4.set_owner(this);
  FA_5.set_owner(this);
  FA_6.set_owner(this);
  FA_7.set_owner(this);

  HA_8.set_owner(this);
  FA_9.set_owner(this);
  FA_10.set_owner(this);
  FA_11.set_owner(this);
  HA_12.set_owner(this);

  //gates
  AND_0.set_owner(this);
  AND_1.set_owner(this);
  AND_2.set_owner(this);
  NAND_3.set_owner(this);

  AND_4.set_owner(this);
  AND_5.set_owner(this);
  AND_6.set_owner(this);
  NAND_7.set_owner(this);

  AND_8.set_owner(this);
  AND_9.set_owner(this);
  AND_10.set_owner(this);
  NAND_11.set_owner(this);

  NAND_12.set_owner(this);
  NAND_13.set_owner(this);
  NAND_14.set_owner(this);
  AND_15.set_owner(this);

  /*

  Define connectivity

  */

  //gates

  //layer 0
  AND_0.A.connect(INPUT_BUFFER_X0.B);
  AND_0.B.connect(INPUT_BUFFER_Y0.B);

  AND_1.A.connect(INPUT_BUFFER_X1.B);
  AND_1.B.connect(INPUT_BUFFER_Y0.B);

  AND_2.A.connect(INPUT_BUFFER_X2.B);
  AND_2.B.connect(INPUT_BUFFER_Y0.B);

  NAND_3.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X3.B);
  NAND_3.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y0.B);



  //layer 1
  AND_4.A.connect(INPUT_BUFFER_X0.B);
  AND_4.B.connect(INPUT_BUFFER_Y1.B);

  AND_5.A.connect(INPUT_BUFFER_X1.B);
  AND_5.B.connect(INPUT_BUFFER_Y1.B);

  AND_6.A.connect(INPUT_BUFFER_X2.B);
  AND_6.B.connect(INPUT_BUFFER_Y1.B);

  NAND_7.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X3.B);
  NAND_7.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y1.B);



  //layer 2
  AND_8.A.connect(INPUT_BUFFER_X0.B);
  AND_8.B.connect(INPUT_BUFFER_Y2.B);

  AND_9.A.connect(INPUT_BUFFER_X1.B);
  AND_9.B.connect(INPUT_BUFFER_Y2.B);

  AND_10.A.connect(INPUT_BUFFER_X2.B);
  AND_10.B.connect(INPUT_BUFFER_Y2.B);

  NAND_11.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X3.B);
  NAND_11.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y2.B);



  //layer 3
  NAND_12.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X0.B);
  NAND_12.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y3.B);

  NAND_13.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X1.B);
  NAND_13.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y3.B);

  NAND_14.INPUT_BUFFER_A.A.connect(INPUT_BUFFER_X2.B);
  NAND_14.INPUT_BUFFER_B.A.connect(INPUT_BUFFER_Y3.B);

  AND_15.A.connect(INPUT_BUFFER_X3.B);
  AND_15.B.connect(INPUT_BUFFER_Y3.B);



  //Adders

  //layer 1
  HA_0.INPUT_BUFFER_A.A.connect(AND_4.C);
  HA_0.INPUT_BUFFER_B.A.connect(AND_1.C);

  FA_1.INPUT_BUFFER_A.A.connect(AND_5.C);
  FA_1.INPUT_BUFFER_B.A.connect(AND_2.C);
  FA_1.INPUT_BUFFER_CARRY_IN.A.connect(HA_0.OUTPUT_BUFFER_CARRY.B);

  FA_2.INPUT_BUFFER_A.A.connect(AND_6.C);
  FA_2.INPUT_BUFFER_B.A.connect(NAND_3.OUTPUT_BUFFER_C.B);
  FA_2.INPUT_BUFFER_CARRY_IN.A.connect(FA_1.OUTPUT_BUFFER_CARRY.B);

  FA_3.INPUT_BUFFER_A.A.connect(NAND_7.OUTPUT_BUFFER_C.B);
  FA_3.INPUT_BUFFER_B.A.connect(PORT_1);
  FA_3.INPUT_BUFFER_CARRY_IN.A.connect(FA_2.OUTPUT_BUFFER_CARRY.B);



  //layer 2
  HA_4.INPUT_BUFFER_A.A.connect(AND_8.C);
  HA_4.INPUT_BUFFER_B.A.connect(FA_1.OUTPUT_BUFFER_SUM.B);

  FA_5.INPUT_BUFFER_A.A.connect(AND_9.C);
  FA_5.INPUT_BUFFER_B.A.connect(FA_2.OUTPUT_BUFFER_SUM.B);
  FA_5.INPUT_BUFFER_CARRY_IN.A.connect(HA_4.OUTPUT_BUFFER_CARRY.B);

  FA_6.INPUT_BUFFER_A.A.connect(AND_10.C);
  FA_6.INPUT_BUFFER_B.A.connect(FA_3.OUTPUT_BUFFER_SUM.B);
  FA_6.INPUT_BUFFER_CARRY_IN.A.connect(FA_5.OUTPUT_BUFFER_CARRY.B);

  FA_7.INPUT_BUFFER_A.A.connect(NAND_11.OUTPUT_BUFFER_C.B);
  FA_7.INPUT_BUFFER_B.A.connect(FA_3.OUTPUT_BUFFER_CARRY.B);
  FA_7.INPUT_BUFFER_CARRY_IN.A.connect(FA_6.OUTPUT_BUFFER_CARRY.B);



  //layer 3
  HA_8.INPUT_BUFFER_A.A.connect(NAND_12.OUTPUT_BUFFER_C.B);
  HA_8.INPUT_BUFFER_B.A.connect(FA_5.OUTPUT_BUFFER_SUM.B);

  FA_9.INPUT_BUFFER_A.A.connect(NAND_13.OUTPUT_BUFFER_C.B);
  FA_9.INPUT_BUFFER_B.A.connect(FA_6.OUTPUT_BUFFER_SUM.B);
  FA_9.INPUT_BUFFER_CARRY_IN.A.connect(HA_8.OUTPUT_BUFFER_CARRY.B);

  FA_10.INPUT_BUFFER_A.A.connect(NAND_14.OUTPUT_BUFFER_C.B);
  FA_10.INPUT_BUFFER_B.A.connect(FA_7.OUTPUT_BUFFER_SUM.B);
  FA_10.INPUT_BUFFER_CARRY_IN.A.connect(FA_9.OUTPUT_BUFFER_CARRY.B);

  FA_11.INPUT_BUFFER_A.A.connect(AND_15.C);
  FA_11.INPUT_BUFFER_B.A.connect(FA_7.OUTPUT_BUFFER_CARRY.B);
  FA_11.INPUT_BUFFER_CARRY_IN.A.connect(FA_10.OUTPUT_BUFFER_CARRY.B);

  HA_12.INPUT_BUFFER_A.A.connect(PORT_1);
  HA_12.INPUT_BUFFER_B.A.connect(FA_11.OUTPUT_BUFFER_CARRY.B);



  //outputs
  OUTPUT_BUFFER_Z0.A.connect(AND_0.C);
  OUTPUT_BUFFER_Z1.A.connect(HA_0.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z2.A.connect(HA_4.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z3.A.connect(HA_8.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z4.A.connect(FA_9.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z5.A.connect(FA_10.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z6.A.connect(FA_11.OUTPUT_BUFFER_SUM.B);
  OUTPUT_BUFFER_Z7.A.connect(HA_12.OUTPUT_BUFFER_SUM.B);


  //output list
  output_list.push_back(&OUTPUT_BUFFER_Z0);
  output_list.push_back(&OUTPUT_BUFFER_Z1);
  output_list.push_back(&OUTPUT_BUFFER_Z2);
  output_list.push_back(&OUTPUT_BUFFER_Z3);
  output_list.push_back(&OUTPUT_BUFFER_Z4);
  output_list.push_back(&OUTPUT_BUFFER_Z5);
  output_list.push_back(&OUTPUT_BUFFER_Z6);
  output_list.push_back(&OUTPUT_BUFFER_Z7);



}


//update function
void MULTIPLIER_4::update_output(std::queue<COMPONENT*> &external_update_queue){

  // //store previous state
  // std::vector<bool> prev_state;
  // bool prev_state_carry;

  // prev_state.push_back(OUTPUT_BUFFER_SUM_0.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_1.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_2.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_3.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_4.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_5.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_6.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_7.B.get_state());
  //
  // prev_state_carry = OUTPUT_BUFFER_CARRY.B.get_state();

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_X0.update_output(internal_update_queue);
  INPUT_BUFFER_X1.update_output(internal_update_queue);
  INPUT_BUFFER_X2.update_output(internal_update_queue);
  INPUT_BUFFER_X3.update_output(internal_update_queue);


  INPUT_BUFFER_Y0.update_output(internal_update_queue);
  INPUT_BUFFER_Y1.update_output(internal_update_queue);
  INPUT_BUFFER_Y2.update_output(internal_update_queue);
  INPUT_BUFFER_Y3.update_output(internal_update_queue);


  // INPUT_BUFFER_CARRY_IN.update_output(internal_update_queue);

  while(!internal_update_queue.empty()){

    // if ((*(internal_update_queue.front())).get_owner() == this){

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();
    // }

    // else {
    //
    //   internal_update_queue.pop();
    // }

  }

  // //initialisation forced run
  //
  // if (!(this->initialisation_flag)){
  //
  //   this->initialisation_flag = 1;
  //
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_0.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_0.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_1.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_1.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_2.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_2.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_3.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_3.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_4.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_4.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_5.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_5.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_6.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_6.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_7.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_7.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //
  //
  // }
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
  //
  //
  // if (prev_state_carry != OUTPUT_BUFFER_CARRY.B.get_state()){
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
  //   }
  // }

}

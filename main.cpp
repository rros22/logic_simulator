//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp tests/connectivity.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp tests/nand_test/nand_test.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp half_adder/HALF_ADDER.cpp half_adder/half_adder_test/half_adder_test.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp half_adder/HALF_ADDER.cpp full_adder/FULL_ADDER.cpp full_adder/full_adder_test/full_adder_test.cpp

//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp half_adder/HALF_ADDER.cpp full_adder/FULL_ADDER.cpp  adder_8/ADDER_8.cpp multiplier_4/MULTIPLIER_4.cpp

//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp half_adder/HALF_ADDER.cpp full_adder/FULL_ADDER.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp half_adder/HALF_ADDER.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp XOR.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp



//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp OR.cpp sr_latch/SR_LATCH.cpp d_latch/D_LATCH.cpp d_latch_load/D_LATCH_LOAD.cpp register_8/REGISTER_8.cpp



//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp sr_latch/SR_LATCH.cpp d_latch/D_LATCH.cpp

//c++ main.cpp PORT.cpp COMPONENT.cpp NAND.cpp
//c++ main.cpp PORT.cpp COMPONENT.cpp


#include "PORT.hpp"
#include "COMPONENT.hpp"
#include "NAND.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "half_adder/HALF_ADDER.hpp"
#include "full_adder/FULL_ADDER.hpp"
#include "sr_latch/SR_LATCH.hpp"
#include "d_latch/D_LATCH.hpp"
#include "adder_8/ADDER_8.hpp"
#include "multiplier_4/MULTIPLIER_4.hpp"
#include "d_latch_load/D_LATCH_LOAD.hpp"

#include "register_8/REGISTER_8.hpp"


int main(){

  OUTPUT_PORT DATA;

  OUTPUT_PORT CLK;
  OUTPUT_PORT LOAD;

  BUFFER CLK_IN;
  BUFFER LOAD_IN;
  BUFFER DATA_IN;

  D_LATCH_LOAD BIT;

  CLK_IN.A.connect(CLK);
  LOAD_IN.A.connect(LOAD);
  DATA_IN.A.connect(DATA);

  BIT.INPUT_BUFFER_CLK.A.connect(CLK_IN.B);
  BIT.INPUT_BUFFER_LOAD.A.connect(LOAD_IN.B);
  BIT.INPUT_BUFFER_DATA.A.connect(DATA_IN.B);

  std::queue<COMPONENT*> update_queue;



  //input
  CLK.set_state(1);
  LOAD.set_state(1);
  DATA.set_state(1);

  CLK_IN.update_output(update_queue);
  LOAD_IN.update_output(update_queue);
  DATA_IN.update_output(update_queue);


  while(!update_queue.empty()){

    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << CLK.get_state() << " " << LOAD.get_state() << " " << BIT.OUTPUT_BUFFER_Q.B.get_state() << std::endl;


  //input
  CLK.set_state(1);
  LOAD.set_state(1);
  DATA.set_state(1);


  while(!update_queue.empty()){

    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << CLK.get_state() << " " << LOAD.get_state() << " " << BIT.OUTPUT_BUFFER_Q.B.get_state() << std::endl;





  // OUTPUT_PORT DATA_IN0;
  // OUTPUT_PORT DATA_IN1;
  // OUTPUT_PORT DATA_IN2;
  // OUTPUT_PORT DATA_IN3;
  // OUTPUT_PORT DATA_IN4;
  // OUTPUT_PORT DATA_IN5;
  // OUTPUT_PORT DATA_IN6;
  // OUTPUT_PORT DATA_IN7;
  //
  // OUTPUT_PORT CLK;
  // OUTPUT_PORT LOAD;
  //
  // REGISTER_8 WORD_0;
  //
  // //set port output
  // CLK.set_state(1);
  // LOAD.set_state(1);
  //
  // DATA_IN0.set_state(1);
  // DATA_IN1.set_state(1);
  // DATA_IN2.set_state(1);
  // DATA_IN3.set_state(1);
  // DATA_IN4.set_state(1);
  // DATA_IN5.set_state(1);
  // DATA_IN6.set_state(1);
  // DATA_IN7.set_state(1);
  //
  // //conncectivity
  // WORD_0.INPUT_BUFFER_DATA_IN0.A.connect(DATA_IN0);
  // WORD_0.INPUT_BUFFER_DATA_IN1.A.connect(DATA_IN1);
  // WORD_0.INPUT_BUFFER_DATA_IN2.A.connect(DATA_IN2);
  // WORD_0.INPUT_BUFFER_DATA_IN3.A.connect(DATA_IN3);
  // WORD_0.INPUT_BUFFER_DATA_IN4.A.connect(DATA_IN4);
  // WORD_0.INPUT_BUFFER_DATA_IN5.A.connect(DATA_IN5);
  // WORD_0.INPUT_BUFFER_DATA_IN6.A.connect(DATA_IN6);
  // WORD_0.INPUT_BUFFER_DATA_IN7.A.connect(DATA_IN7);
  //
  // WORD_0.INPUT_BUFFER_CLK.A.connect(CLK);
  // WORD_0.INPUT_BUFFER_LOAD.A.connect(LOAD);
  //
  // std::queue<COMPONENT*> update_queue;
  //
  // WORD_0.update_output(update_queue);
  //
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  //
  // CLK.set_state(1);
  // LOAD.set_state(0);
  //
  // DATA_IN0.set_state(1);
  // DATA_IN1.set_state(1);
  // DATA_IN2.set_state(1);
  // DATA_IN3.set_state(1);
  // DATA_IN4.set_state(1);
  // DATA_IN5.set_state(0);
  // DATA_IN6.set_state(1);
  // DATA_IN7.set_state(1);
  //
  //
  // WORD_0.update_output(update_queue);
  //
  //
  //
  // for (int i = 0; i < WORD_0.output_list.size(); i++){
  //
  //   std::cout << (*(WORD_0.output_list[WORD_0.output_list.size()-1-i])).B.get_state() << " ";
  // }
  //
  //
  //
  // std::cout << std::endl;


  // //change
  // CLK.set_state(1);
  // LOAD.set_state(0);
  //
  // DATA_IN0.set_state(1);
  // DATA_IN1.set_state(1);
  // DATA_IN2.set_state(1);
  // DATA_IN3.set_state(1);
  // DATA_IN4.set_state(1);
  // DATA_IN5.set_state(0);
  // DATA_IN6.set_state(1);
  // DATA_IN7.set_state(1);
  //
  // WORD_0.update_output(update_queue);
  //
  //
  //
  // for (int i = 0; i < WORD_0.output_list.size(); i++){
  //
  //   std::cout << (*(WORD_0.output_list[WORD_0.output_list.size()-1-i])).B.get_state() << " ";
  // }
  //
  //
  //
  // std::cout << std::endl;






  return 0;
}

#include "full_adder_test.hpp"


void full_adder_test(){

  FULL_ADDER FA1;

  OUTPUT_PORT O1;
  OUTPUT_PORT O2;
  OUTPUT_PORT O3;


  FA1.INPUT_BUFFER_A.A.connect(O1);
  FA1.INPUT_BUFFER_B.A.connect(O2);
  FA1.INPUT_BUFFER_CARRY_IN.A.connect(O3);


  //print internal components initalisation flags
  std::cout << "Input A initialisation:      " << FA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:      " << FA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "Input CARRY initialisation:  " << FA1.INPUT_BUFFER_CARRY_IN.get_initialisation_flag() << std::endl;
  std::cout << "HALF_ADDER_1 initialisation: " << FA1.HALF_ADDER_1.get_initialisation_flag() << std::endl;
  std::cout << "HALF_ADDER_2 initialisation: " << FA1.HALF_ADDER_2.get_initialisation_flag() << std::endl;
  std::cout << "OR_1 initialisation:         " << FA1.OR_1.get_initialisation_flag() << std::endl;
  std::cout << "Output CARRY initalisation:  " << FA1.OUTPUT_BUFFER_CARRY.get_initialisation_flag() << std::endl;
  std::cout << "Output SUM initialisation:   " << FA1.OUTPUT_BUFFER_SUM.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  std::queue<COMPONENT*> update_queue;

  FA1.update_output(update_queue);

  //print internal components initalisation flags
  std::cout << "Input A initialisation:      " << FA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:      " << FA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "Input CARRY initialisation:  " << FA1.INPUT_BUFFER_CARRY_IN.get_initialisation_flag() << std::endl;
  std::cout << "HALF_ADDER_1 initialisation: " << FA1.HALF_ADDER_1.get_initialisation_flag() << std::endl;
  std::cout << "HALF_ADDER_2 initialisation: " << FA1.HALF_ADDER_2.get_initialisation_flag() << std::endl;
  std::cout << "OR_1 initialisation:         " << FA1.OR_1.get_initialisation_flag() << std::endl;
  std::cout << "Output CARRY initalisation:  " << FA1.OUTPUT_BUFFER_CARRY.get_initialisation_flag() << std::endl;
  std::cout << "Output SUM initialisation:   " << FA1.OUTPUT_BUFFER_SUM.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  //000
  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //001
  O1.set_state(0);
  O2.set_state(0);
  O3.set_state(1);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //010
  O1.set_state(0);
  O2.set_state(1);
  O3.set_state(0);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //011
  O1.set_state(0);
  O2.set_state(1);
  O3.set_state(1);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //100
  O1.set_state(1);
  O2.set_state(0);
  O3.set_state(0);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //101
  O1.set_state(1);
  O2.set_state(0);
  O3.set_state(1);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //110
  O1.set_state(1);
  O2.set_state(1);
  O3.set_state(0);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

  //111
  O1.set_state(1);
  O2.set_state(1);
  O3.set_state(1);

  FA1.update_output(update_queue);

  std::cout << FA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << FA1.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

  std::cout << std::endl;

}

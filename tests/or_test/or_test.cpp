#include "or_test.hpp"


void or_test(){


  OR OR1;

  OUTPUT_PORT O1;
  OUTPUT_PORT O2;

  OR1.INPUT_BUFFER_A.A.connect(O1);
  OR1.INPUT_BUFFER_B.A.connect(O2);




  //print internal components initalisation flags
  std::cout << "Input A initialisation:  " << OR1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:  " << OR1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "NAND_1 initialisation:   " << OR1.NAND_1.get_initialisation_flag() << std::endl;
  std::cout << "NAND_2 initialisation:   " << OR1.NAND_2.get_initialisation_flag() << std::endl;
  std::cout << "NAND_3 initialisation:   " << OR1.NAND_3.get_initialisation_flag() << std::endl;
  std::cout << "Output C initialisation: " << OR1.OUTPUT_BUFFER_C.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  std::queue<COMPONENT*> update_queue;

  OR1.update_output(update_queue);

  std::cout << "Input A initialisation:  " << OR1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:  " << OR1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "NAND_1 initialisation:   " << OR1.NAND_1.get_initialisation_flag() << std::endl;
  std::cout << "NAND_2 initialisation:   " << OR1.NAND_2.get_initialisation_flag() << std::endl;
  std::cout << "NAND_3 initialisation:   " << OR1.NAND_3.get_initialisation_flag() << std::endl;
  std::cout << "Output C initialisation: " << OR1.OUTPUT_BUFFER_C.get_initialisation_flag() << std::endl;

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(1);
  O2.set_state(0);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(0);
  O2.set_state(1);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(1);
  O2.set_state(1);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  OR1.update_output(update_queue);

  std::cout << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;
}

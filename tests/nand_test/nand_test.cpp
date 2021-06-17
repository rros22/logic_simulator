#include "nand_test.hpp"


void nand_test(){

  std::cout << std::endl;

  std::cout << "NAND gate test running: " << std::endl;

  std::cout << std::endl;


  //create information source
  OUTPUT_PORT O1;
  OUTPUT_PORT O2;

  //create sample nand gate
  NAND NA1;

  //connect NA1 to O1,O2
  NA1.INPUT_BUFFER_A.A.connect(O1);
  NA1.INPUT_BUFFER_B.A.connect(O2);

  //set source states (should be 0 by definition)
  O1.set_state(0);
  O2.set_state(0);

  //create main update queue for simulation
  std::queue<COMPONENT*> update_queue;

  //connectivity test
  std::cout << "NAND connectivity: " << std::endl;

  std::cout << std::endl;

  std::cout << "NA1 address: " << &NA1  << std::endl;
  std::cout << "AND owner:   " << NA1.AND_1.get_owner()  << std::endl;
  std::cout << "NOT owner:   " << NA1.NOT_1.get_owner()  << std::endl;
  std::cout << "A owner:     " << NA1.INPUT_BUFFER_A.get_owner()  << std::endl;
  std::cout << "B owner:     " << NA1.INPUT_BUFFER_B.get_owner()  << std::endl;
  std::cout << "C owner:     " << NA1.OUTPUT_BUFFER_C.get_owner()  << std::endl;

  std::cout << std::endl;

  std::cout << "Address of NAND PORT A is:  "  << &(NA1.INPUT_BUFFER_A.B) << std::endl;
  std::cout << "Input of AND_1 PORT A is:   "  << NA1.AND_1.A.get_input_address() << std::endl;

  std::cout << std::endl;

  std::cout << "Address of NAND PORT B is:  "  << &(NA1.INPUT_BUFFER_B.B) << std::endl;
  std::cout << "Input of AND_1 PORT B is:   "  << NA1.AND_1.B.get_input_address() << std::endl;

  std::cout << std::endl;

  std::cout << "Address of AND_1 PORT C is: "  << &(NA1.AND_1.C) << std::endl;
  std::cout << "Input of NOT_1 PORT A is:   "  << NA1.NOT_1.A.get_input_address() << std::endl;

  std::cout << std::endl;

  std::cout << "Address of NOT_1 PORT B is: "  << &(NA1.NOT_1.B) << std::endl;
  std::cout << "Input of NAND PORT C is:    "  << NA1.OUTPUT_BUFFER_C.A.get_input_address() << std::endl;

  std::cout << std::endl;

  std::cout << "Signal propagation tests running" << std::endl;

  std::cout <<  std::endl;


  //print NA1 initialisation flag
  std::cout << "NA1 initialisation:      " << NA1.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  //print internal components initalisation flags
  std::cout << "Input A initialisation:  " << NA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:  " << NA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "AND_1 initialisation:    " << NA1.AND_1.get_initialisation_flag() << std::endl;
  std::cout << "NOT_1 initialisation:    " << NA1.NOT_1.get_initialisation_flag() << std::endl;
  std::cout << "Output C initialisation: " << NA1.OUTPUT_BUFFER_C.get_initialisation_flag() << std::endl;



  std::cout << std::endl;

  //print NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;


  //call update output to initialise components
  NA1.update_output(update_queue);

  //print again NA1 initialisation flag
  std::cout << "NA1 initialisation:     " << NA1.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  //print again internal components initalisation flags
  std::cout << "Input A initialisation:  " << NA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:  " << NA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "AND_1 initialisation:    " << NA1.AND_1.get_initialisation_flag() << std::endl;
  std::cout << "NOT_1 initialisation:    " << NA1.NOT_1.get_initialisation_flag() << std::endl;
  std::cout << "Output C initialisation: " << NA1.OUTPUT_BUFFER_C.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  //print again NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print again NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;

  /*

  Battery of tests, truth table check, internal component behaviour

  */

  //O1 = 1, O2 = 1
  std::cout << "Test O1 = 1, O2 = 1; expected 0 " << std::endl;

  O1.set_state(1);
  O2.set_state(1);

  //call update output
  NA1.update_output(update_queue);

  //print again NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print again NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;



  //O1 = 0, O2 = 1
  std::cout << "Test O1 = 0, O2 = 1; expected 1 " << std::endl;

  O1.set_state(0);
  O2.set_state(1);

  //call update output
  NA1.update_output(update_queue);

  //print again NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print again NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;



  //O1 = 1, O2 = 0; expected 1
  std::cout << "Test O1 = 1, O2 = 0; expected 1 " << std::endl;

  O1.set_state(1);
  O2.set_state(0);

  //call update output
  NA1.update_output(update_queue);

  //print again NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print again NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;



  //O1 = 0, O2 = 0; expected 1
  std::cout << "Test O1 = 0, O2 = 0; expected 1 " << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  //call update output
  NA1.update_output(update_queue);

  //print again NA1 inputs and output
  std::cout << "NA1 input A:           " << NA1.INPUT_BUFFER_A.B.get_state() << std::endl;
  std::cout << "NA1 input B:           " << NA1.INPUT_BUFFER_B.B.get_state() << std::endl;
  std::cout << "NA1 output:            " << NA1.OUTPUT_BUFFER_C.B.get_state() << std::endl;

  std::cout << std::endl;

  //print again NA1 internals
  std::cout << "NA1 AND_1 output:      " << NA1.AND_1.C.get_state() << std::endl;
  std::cout << "NA1 NOT_1 output:      " << NA1.NOT_1.B.get_state() << std::endl;

  std::cout << std::endl;
}

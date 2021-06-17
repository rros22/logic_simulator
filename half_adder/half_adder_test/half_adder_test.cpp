#include "half_adder_test.hpp"


void half_adder_test(){

  OUTPUT_PORT O1;
  OUTPUT_PORT O2;

  HALF_ADDER HA1;
  OR OR1;
  NOT N1;

  HA1.INPUT_BUFFER_A.A.connect(O1);
  HA1.INPUT_BUFFER_B.A.connect(O2);

  OR1.INPUT_BUFFER_A.A.connect(HA1.OUTPUT_BUFFER_CARRY.B);
  OR1.INPUT_BUFFER_B.A.connect(HA1.OUTPUT_BUFFER_SUM.B);

  N1.A.connect(HA1.OUTPUT_BUFFER_CARRY.B);

  //print internal components initalisation flags
  std::cout << "Input A initialisation:     " << HA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:     " << HA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "AND_1 initialisation:       " << HA1.AND_1.get_initialisation_flag() << std::endl;
  std::cout << "XOR_1 initialisation:       " << HA1.XOR_1.get_initialisation_flag() << std::endl;
  std::cout << "Output CARRY initalisation: " << HA1.OUTPUT_BUFFER_CARRY.get_initialisation_flag() << std::endl;
  std::cout << "Output SUM initialisation:  " << HA1.OUTPUT_BUFFER_SUM.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  std::queue<COMPONENT*> update_queue;

  HA1.update_output(update_queue);

  //print internal components initalisation flags
  std::cout << "Input A initialisation:     " << HA1.INPUT_BUFFER_A.get_initialisation_flag() << std::endl;
  std::cout << "Input B initialisation:     " << HA1.INPUT_BUFFER_B.get_initialisation_flag() << std::endl;
  std::cout << "AND_1 initialisation:       " << HA1.AND_1.get_initialisation_flag() << std::endl;
  std::cout << "XOR_1 initialisation:       " << HA1.XOR_1.get_initialisation_flag() << std::endl;
  std::cout << "Output CARRY initalisation: " << HA1.OUTPUT_BUFFER_CARRY.get_initialisation_flag() << std::endl;
  std::cout << "Output SUM initialisation:  " << HA1.OUTPUT_BUFFER_SUM.get_initialisation_flag() << std::endl;

  std::cout << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  HA1.update_output(update_queue);

  while(!update_queue.empty()){


    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << HA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << HA1.OUTPUT_BUFFER_CARRY.B.get_state();
  std::cout << "  " << N1.B.get_state();
  std::cout << "  " << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;
  std::cout << std::endl;

  O1.set_state(1);
  O2.set_state(0);

  HA1.update_output(update_queue);

  while(!update_queue.empty()){


    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << HA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << HA1.OUTPUT_BUFFER_CARRY.B.get_state();
  std::cout << "  " << N1.B.get_state();
  std::cout << "  " << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;
  std::cout << std::endl;

  O1.set_state(1);
  O2.set_state(1);

  HA1.update_output(update_queue);

  while(!update_queue.empty()){


    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << HA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << HA1.OUTPUT_BUFFER_CARRY.B.get_state();
  std::cout << "  " << N1.B.get_state();
  std::cout << "  " << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;
  std::cout << std::endl;

  O1.set_state(0);
  O2.set_state(0);

  HA1.update_output(update_queue);

  while(!update_queue.empty()){


    (*(update_queue.front())).update_output(update_queue);
    update_queue.pop();

  }

  std::cout << HA1.OUTPUT_BUFFER_SUM.B.get_state();
  std::cout << HA1.OUTPUT_BUFFER_CARRY.B.get_state();
  std::cout << "  " << N1.B.get_state();
  std::cout << "  " << OR1.OUTPUT_BUFFER_C.B.get_state() << std::endl;
  std::cout << std::endl;

}

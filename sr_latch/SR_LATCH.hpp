#ifndef SR_LATCH_HPP
#define SR_LATCH_HPP

#include "../NAND.hpp"


class SR_LATCH: public COMPONENT{

public:

  //inputs
  I_BUFFER INPUT_BUFFER_RESET;
  I_BUFFER INPUT_BUFFER_SET;
  
  //outputs
  BUFFER OUTPUT_BUFFER_Q;
  BUFFER OUTPUT_BUFFER_Q_NOT;

  //internal logic
  NAND NAND_1;
  NAND NAND_2;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  SR_LATCH();

};


#endif

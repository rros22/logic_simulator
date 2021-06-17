#ifndef D_LATCH_HPP
#define D_LATCH_HPP

#include "../sr_latch/SR_LATCH.hpp"


class D_LATCH: public COMPONENT{

public:

  //inputs
  I_BUFFER INPUT_BUFFER_DATA;
  I_BUFFER INPUT_BUFFER_CLK;

  //outputs
  BUFFER OUTPUT_BUFFER_Q;
  BUFFER OUTPUT_BUFFER_Q_NOT;

  //logic
  SR_LATCH SR_LATCH_1;

  NAND NAND_1;
  NAND NAND_2;

  NOT NOT_1;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  D_LATCH();


};






#endif

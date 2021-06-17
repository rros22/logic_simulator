#ifndef D_LATCH_LOAD_HPP
#define D_LATCH_LOAD_HPP

#include "../d_latch/D_LATCH.hpp"
#include "../OR.hpp"

class D_LATCH_LOAD: public COMPONENT{

public:

  //inputs
  I_BUFFER INPUT_BUFFER_DATA;
  I_BUFFER INPUT_BUFFER_CLK;
  I_BUFFER INPUT_BUFFER_LOAD;

  //outputs
  BUFFER OUTPUT_BUFFER_Q;
  BUFFER OUTPUT_BUFFER_Q_NOT;

  //memory
  D_LATCH D_LATCH_1;

  //load logic
  AND AND_1;
  AND AND_2;
  OR OR_1;
  NOT NOT_1;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  D_LATCH_LOAD();



};

#endif

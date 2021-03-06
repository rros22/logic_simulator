#ifndef REGISTER_8_HPP
#define REGISTER_8_HPP

#include "../d_latch_load/D_LATCH_LOAD.hpp"
#include <vector>

class REGISTER_8: public COMPONENT{

public:

  //output list for update purposes
  std::vector<BUFFER*> output_list;

  //inputs
  I_BUFFER INPUT_BUFFER_DATA_IN0;
  I_BUFFER INPUT_BUFFER_DATA_IN1;
  I_BUFFER INPUT_BUFFER_DATA_IN2;
  I_BUFFER INPUT_BUFFER_DATA_IN3;
  I_BUFFER INPUT_BUFFER_DATA_IN4;
  I_BUFFER INPUT_BUFFER_DATA_IN5;
  I_BUFFER INPUT_BUFFER_DATA_IN6;
  I_BUFFER INPUT_BUFFER_DATA_IN7;

  //control inputs
  I_BUFFER INPUT_BUFFER_CLK;

  I_BUFFER INPUT_BUFFER_LOAD;

  //outputs
  BUFFER OUTPUT_BUFFER_DATA_OUT0;
  BUFFER OUTPUT_BUFFER_DATA_OUT1;
  BUFFER OUTPUT_BUFFER_DATA_OUT2;
  BUFFER OUTPUT_BUFFER_DATA_OUT3;
  BUFFER OUTPUT_BUFFER_DATA_OUT4;
  BUFFER OUTPUT_BUFFER_DATA_OUT5;
  BUFFER OUTPUT_BUFFER_DATA_OUT6;
  BUFFER OUTPUT_BUFFER_DATA_OUT7;

  //memory
  D_LATCH_LOAD D_LATCH_0;
  D_LATCH_LOAD D_LATCH_1;
  D_LATCH_LOAD D_LATCH_2;
  D_LATCH_LOAD D_LATCH_3;
  D_LATCH_LOAD D_LATCH_4;
  D_LATCH_LOAD D_LATCH_5;
  D_LATCH_LOAD D_LATCH_6;
  D_LATCH_LOAD D_LATCH_7;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  REGISTER_8();


};



#endif

#ifndef HALF_ADDDER_HPP
#define HALF_ADDDER_HPP

#include "../XOR.hpp"
#include <queue>

class HALF_ADDER: public COMPONENT{

public:

  I_BUFFER INPUT_BUFFER_A;
  I_BUFFER INPUT_BUFFER_B;

  BUFFER OUTPUT_BUFFER_CARRY;
  BUFFER OUTPUT_BUFFER_SUM;

  AND AND_1;
  XOR XOR_1;

  void update_output(std::queue<COMPONENT*> &external_update_queue);

  HALF_ADDER();


};





#endif

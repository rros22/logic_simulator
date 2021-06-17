#ifndef FULL_ADDER_HPP
#define FULL_ADDER_HPP



#include "../OR.hpp"
#include "../half_adder/HALF_ADDER.hpp"

class FULL_ADDER: public COMPONENT{

public:

  //inputs
  I_BUFFER INPUT_BUFFER_A;
  I_BUFFER INPUT_BUFFER_B;
  I_BUFFER INPUT_BUFFER_CARRY_IN;

  //outputs
  BUFFER OUTPUT_BUFFER_SUM;
  BUFFER OUTPUT_BUFFER_CARRY;

  //internal logic
  HALF_ADDER HALF_ADDER_1;
  HALF_ADDER HALF_ADDER_2;
  OR OR_1;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  FULL_ADDER();

};

#endif

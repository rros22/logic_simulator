#ifndef XOR_HPP
#define XOR_HPP

#include "COMPONENT.hpp"
#include "NAND.hpp"
#include <queue>



class XOR: public COMPONENT{

public:


  I_BUFFER INPUT_BUFFER_A;
  I_BUFFER INPUT_BUFFER_B;
  BUFFER OUTPUT_BUFFER_C;

  NAND NAND_1, NAND_2, NAND_3, NAND_4;

  void update_output(std::queue<COMPONENT*> &external_update_queue);

  XOR();

};


#endif

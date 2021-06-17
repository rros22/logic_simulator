#ifndef OR_HPP
#define OR_HPP

#include "COMPONENT.hpp"
#include "NAND.hpp"
#include <queue>

class OR: public COMPONENT{

public:
  /*

  OR gate comprised of three interface buffers, forwarding data to the
  three NAND gates.

  */

  I_BUFFER INPUT_BUFFER_A;
  I_BUFFER INPUT_BUFFER_B;
  BUFFER OUTPUT_BUFFER_C;

  NAND NAND_1, NAND_2, NAND_3;

  void update_output(std::queue<COMPONENT*> &external_update_queue);

  OR();

};



#endif

#ifndef NAND_HPP
#define NAND_HPP

#include "COMPONENT.hpp"
#include <queue>

class NAND: public COMPONENT{

public:
  /*

  NAND gate comprised of three interface ports, acting as buffers for internal
  components & one AND & one OR components connected in series.

  */

  I_BUFFER INPUT_BUFFER_A;
  I_BUFFER INPUT_BUFFER_B;
  BUFFER OUTPUT_BUFFER_C;

  AND AND_1;
  NOT NOT_1;

  void update_output(std::queue<COMPONENT*> &external_update_queue);

  NAND();

};



#endif

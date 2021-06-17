//c++ main.cpp PORT.cpp COMPONENT.cpp
#include "connectivity.hpp"

void connectivity_test(){



  PORT I1(1);
  PORT I2(1);

  AND A1;

  NOT N1;

  A1.A.connect(I1);
  A1.B.connect(I2);

  N1.A.connect(A1.C);

  std::cout << "      " << std::endl;

  std::cout << "Address of AND PORT A is: "  << &(A1.A) << std::endl;
  std::cout << "Output of PORT I1 is:     "  << I1.get_fanout_address(0) << std::endl;

  std::cout << "      " << std::endl;

  std::cout << "Input of AND PORT A is:   "  << A1.A.get_input_address() << std::endl;
  std::cout << "Address of PORT I1 is:    "  << &I1 << std::endl;

  std::cout << "      " << std::endl;

  std::cout << "Address of AND PORT B is: "  << &(A1.B) << std::endl;
  std::cout << "Output of PORT I2 is:     "  << I2.get_fanout_address(0) << std::endl;

  std::cout << "      " << std::endl;

  std::cout << "Input of AND PORT B is:   "  << A1.B.get_input_address() << std::endl;
  std::cout << "Address of PORT I2 is:    "  << &I2 << std::endl;

  std::cout << "      " << std::endl;

  std::cout << "Address of NOT PORT A is: " << &(N1.A) << std::endl;
  std::cout << "Output of AND PORT C is:  "  << A1.C.get_fanout_address(0) << std::endl;

  std::cout << "      " << std::endl;

  std::cout << "Input of NOT PORT A is:   " << N1.A.get_input_address()  << std::endl;
  std::cout << "Address of AND PORT C is: "  << &(A1.C) << std::endl;


  std::cout << "      " << std::endl;



  I1.set_state(0);
  I2.set_state(0);

  A1.update_output();

  std::cout << "      " << std::endl;
  std::cout << "      " << std::endl;
  std::cout << "      " << std::endl;
  std::cout << "      " << std::endl;

  std::cout << "Output of A1 is: "  << A1.C.get_state() << std::endl;

  I1.set_state(1);
  I2.set_state(1);

  A1.update_output();

  std::cout << "Output of A1 is: "  << A1.C.get_state() << std::endl;

  std::cout << "      " << std::endl;


  std::cout << I1.get_input_address() << std::endl;


}

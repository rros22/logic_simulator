

ADDER_8 A8;

OUTPUT_PORT A_O1;
OUTPUT_PORT A_O2;
OUTPUT_PORT A_O3;
OUTPUT_PORT A_O4;
OUTPUT_PORT A_O5;
OUTPUT_PORT A_O6;
OUTPUT_PORT A_O7;
OUTPUT_PORT A_O8;

OUTPUT_PORT B_O1;
OUTPUT_PORT B_O2;
OUTPUT_PORT B_O3;
OUTPUT_PORT B_O4;
OUTPUT_PORT B_O5;
OUTPUT_PORT B_O6;
OUTPUT_PORT B_O7;
OUTPUT_PORT B_O8;

OUTPUT_PORT CARRY;

A8.INPUT_BUFFER_A0.A.connect(A_O1);
A8.INPUT_BUFFER_A1.A.connect(A_O2);
A8.INPUT_BUFFER_A2.A.connect(A_O3);
A8.INPUT_BUFFER_A3.A.connect(A_O4);
A8.INPUT_BUFFER_A4.A.connect(A_O5);
A8.INPUT_BUFFER_A5.A.connect(A_O6);
A8.INPUT_BUFFER_A6.A.connect(A_O7);
A8.INPUT_BUFFER_A7.A.connect(A_O8);

A8.INPUT_BUFFER_B0.A.connect(B_O1);
A8.INPUT_BUFFER_B1.A.connect(B_O2);
A8.INPUT_BUFFER_B2.A.connect(B_O3);
A8.INPUT_BUFFER_B3.A.connect(B_O4);
A8.INPUT_BUFFER_B4.A.connect(B_O5);
A8.INPUT_BUFFER_B5.A.connect(B_O6);
A8.INPUT_BUFFER_B6.A.connect(B_O7);
A8.INPUT_BUFFER_B7.A.connect(B_O8);

A8.INPUT_BUFFER_CARRY_IN.A.connect(CARRY);



std::queue<COMPONENT*> update_queue;

// A8.update_output(update_queue);
//
// for (int i = 0; i < A8.output_list.size(); i++){
//
//   std::cout << (*(A8.output_list[i])).B.get_state() << " ";
// }
//
// std::cout << std::endl;

A_O1.set_state(0);
A_O2.set_state(0);
A_O3.set_state(1);
A_O4.set_state(1);
A_O5.set_state(0);
A_O6.set_state(0);
A_O7.set_state(0);
A_O8.set_state(1);

B_O1.set_state(0);
B_O2.set_state(0);
B_O3.set_state(1);
B_O4.set_state(0);
B_O5.set_state(1);
B_O6.set_state(0);
B_O7.set_state(0);
B_O8.set_state(0);

CARRY.set_state(0);

A8.update_output(update_queue);

for (int i = 0; i < A8.output_list.size(); i++){

  std::cout << (*(A8.output_list[A8.output_list.size()-1-i])).B.get_state() << " ";
}

std::cout << "     " << A8.OUTPUT_BUFFER_CARRY.B.get_state() << std::endl;

std::cout << std::endl;

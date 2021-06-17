


MULTIPLIER_4 MULT1;

OUTPUT_PORT A_O1;
OUTPUT_PORT A_O2;
OUTPUT_PORT A_O3;
OUTPUT_PORT A_O4;

OUTPUT_PORT B_O1;
OUTPUT_PORT B_O2;
OUTPUT_PORT B_O3;
OUTPUT_PORT B_O4;

MULT1.INPUT_BUFFER_X0.A.connect(A_O1);
MULT1.INPUT_BUFFER_X1.A.connect(A_O2);
MULT1.INPUT_BUFFER_X2.A.connect(A_O3);
MULT1.INPUT_BUFFER_X3.A.connect(A_O4);

MULT1.INPUT_BUFFER_Y0.A.connect(B_O1);
MULT1.INPUT_BUFFER_Y1.A.connect(B_O2);
MULT1.INPUT_BUFFER_Y2.A.connect(B_O3);
MULT1.INPUT_BUFFER_Y3.A.connect(B_O4);



std::queue<COMPONENT*> update_queue;

MULT1.update_output(update_queue);

for (int i = 0; i < MULT1.output_list.size(); i++){

  std::cout << (*(MULT1.output_list[MULT1.output_list.size()-1-i])).B.get_state() << " ";
}

std::cout << std::endl;


A_O1.set_state(0);
A_O2.set_state(0);
A_O3.set_state(1);
A_O4.set_state(1);

B_O1.set_state(1);
B_O2.set_state(1);
B_O3.set_state(1);
B_O4.set_state(0);


MULT1.update_output(update_queue);

for (int i = 0; i < MULT1.output_list.size(); i++){

  std::cout << (*(MULT1.output_list[MULT1.output_list.size()-1-i])).B.get_state() << " ";
}

std::cout << std::endl;

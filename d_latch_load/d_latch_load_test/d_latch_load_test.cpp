D_LATCH_LOAD MEM1;


OUTPUT_PORT LOAD;
OUTPUT_PORT DATA;
OUTPUT_PORT CLK;

MEM1.INPUT_BUFFER_LOAD.A.connect(LOAD);
MEM1.INPUT_BUFFER_DATA.A.connect(DATA);
MEM1.INPUT_BUFFER_CLK.A.connect(CLK);

std::queue<COMPONENT*> update_queue;

std::cout << LOAD.get_state() << " ";
std::cout << DATA.get_state() << " ";
std::cout << CLK.get_state() << "     ";


std::cout << MEM1.OUTPUT_BUFFER_Q.B.get_state() << std::endl;

MEM1.update_output(update_queue);

std::cout << LOAD.get_state() << " ";
std::cout << DATA.get_state() << " ";
std::cout << CLK.get_state() << "     ";


std::cout << MEM1.OUTPUT_BUFFER_Q.B.get_state() << std::endl;


//test begins

LOAD.set_state(1);
DATA.set_state(1);
CLK.set_state(1);


MEM1.update_output(update_queue);

std::cout << LOAD.get_state() << " ";
std::cout << DATA.get_state() << " ";
std::cout << CLK.get_state() << "     ";


std::cout << MEM1.OUTPUT_BUFFER_Q.B.get_state() << std::endl;

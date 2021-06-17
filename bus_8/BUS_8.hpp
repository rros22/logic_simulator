#ifndef BUS_8_HPP
#define BUS_8_HPP

class BUS_8: public COMPONENT{

public:

  //inputs
  INPUT_PORT DATA_IN0;
  INPUT_PORT DATA_IN1;
  INPUT_PORT DATA_IN2;
  INPUT_PORT DATA_IN3;
  INPUT_PORT DATA_IN4;
  INPUT_PORT DATA_IN5;
  INPUT_PORT DATA_IN6;
  INPUT_PORT DATA_IN7;

  //outputs
  OUTPUT_PORT DATA_OUT0;
  OUTPUT_PORT DATA_OUT1;
  OUTPUT_PORT DATA_OUT2;
  OUTPUT_PORT DATA_OUT3;
  OUTPUT_PORT DATA_OUT4;
  OUTPUT_PORT DATA_OUT5;
  OUTPUT_PORT DATA_OUT6;
  OUTPUT_PORT DATA_OUT7;

  //update function
  void update_output(std::queue<COMPONENT*> &external_update_queue);

  //constructor
  BUS_8();


};


#endif

#ifndef PORT_HPP
#define PORT_HPP

#include <vector>
#include <string>
#include <iostream>

//COMPONENT class instance for compilation purposes
class COMPONENT;


/*

The class port holds the state of the terminals and serves to interface
between components. A port is owned by a component. A port will have one input
connection if it is a input port. A port will have one or more output connections
if it is an output port. A port can have one input and one or more output
connections if it is an interface port for components containing multiple
subcomponents

*/

class PORT{

protected:

  //type of port (type 0 = I, type 1 = O, type 2 = I/O)
  int type;
  //component owning the port
  COMPONENT* owner;
  //name given to the port
  std::string name;

public:



  //setter funcntions

  void set_type(int type);
  //sets port owner
  void set_owner(COMPONENT* owner);
  //sets port name
  void set_name(std::string name);


  //getter functions

  //returns type of port
  int get_type();
  //returns pointer to component owning port
  COMPONENT* get_owner();
  //returns name given to port
  std::string get_name();

};




//instance for compilation purposes
class OUTPUT_PORT;

class INPUT_PORT: public PORT{

private:

  //address of the input of the port
  OUTPUT_PORT* input_address;

public:


  //constructor

  INPUT_PORT();


  /*

  Connectivity functions. Connectivity is designed as an input to
  output process. When an input calls the connect() function, passing the address
  an output i.e. input.connect(*output), the address of the output is stored at
  the input's, input_address variable. After that, the add_fanout_address()
  function is called internally, and the address of the input is appended to
  the outputs fanout (broadcast) list.

  Inputs store the addresses of the outputs for the purpose state updates,
  having the output address, inputs can read its state when needed, without having
  to explicitly ask the output.

  Outputs store the inputs address for signal propagation purposes, in order to
  notify when a state change has ocurred.

  */


  /*assigns a port to the input_address of this port. Calls the
  add_fanout_address() on the port stored in the input_address passing the
  address of the port acting as input */
  void connect(OUTPUT_PORT &output_port);


  //getter functions

  //returns address of port connected to input
  OUTPUT_PORT* get_input_address();


  //external getter fucntions

  /* Retrieves state value from output port whose address is stored in
   "input_address". Only needed for simplification purposes. */
  bool get_input();

};





class OUTPUT_PORT: public PORT{

private:

  //output addresses
  std::vector<INPUT_PORT*> fanout_addresses;
  //value of the port
  bool state;

public:


  //constructor

  OUTPUT_PORT();


  //connectivity functions

  //adds a port to the fanout list of this port for signal propagation.
  void add_fanout_address(INPUT_PORT *input_port);


  //getter functions

  //returns address of i-indexed port being broadcasted
  INPUT_PORT* get_fanout_address(int i);
  //returns amount of fanout connections
  int get_fanout_size();
  //returns logic value of the port as an output (excludes ports acting as inputs)
  bool get_state();


  //setter funcntions

  //sets the logic value of the port
  void set_state(bool state);

};


#endif

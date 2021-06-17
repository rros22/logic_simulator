#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <vector>
#include <queue>
#include <string>
#include <iostream>


#include "PORT.hpp"

/*

 The component class is to serve as a parent class from which simple and
compound components can be derived. Components serve as directories to
ports and define the arithmetic and logic

*/

class COMPONENT{

protected:

  //component type, to be set by component constructor
  std::string type;
  //integer unique to component when it is created
  int id;
  //name given to the component
  std::string name;
  //component owner, if within another one
  COMPONENT* owner;
  //flag to determine if component has been initialised, for fanout queue push
  bool initialisation_flag;

public:

  //constructor for initialisation_flag setting
  COMPONENT();

  //setter functions


  //sets ID of component
  void set_ID(int id);
  //sets name of component
  void set_name(std::string name);
  //sets owner of component
  virtual void set_owner(COMPONENT* owner);


  //getter functions


  //returns component type, set by specific component constructor
  std::string get_type();
  //returns component ID
  int get_ID();
  //returns component given name
  std::string get_name();
  //returns component owning component
  COMPONENT* get_owner();
  //uptade output template, virtual needed
  virtual void update_output(std::queue<COMPONENT*> &update_queue);
  //return initialisation_flag
  bool get_initialisation_flag(){

    return initialisation_flag;
  }


};

/*

All objects derived from the component class are written below.

*/


/*

AND gate class.

*/

class AND: public COMPONENT{

public:

  /*

  AND gate comprised of three ports. A,B input ports, corresponding to "type 0 "
  when calling PORT(int type) constructor && C output port, corresponding to
  "type 1 " when calling PORT(int type) constructor.

  Default port constructor called as variables can only be initialised when
  calling AND constructor (relevant because of type setting port type will be
  stablished with the set_type(int type) method).

  */

  INPUT_PORT A;
  INPUT_PORT B;
  OUTPUT_PORT C;


  /*

  The update_output() method calls the set_state() method upon the OUTPUT port
  C, taking as parameter the && of the state of output ports connected to A,B
  input ports.

  */

  void update_output(std::queue<COMPONENT*> &update_queue);

  /*

  The AND() constructor sets the paramters of the ports within the AND gate
  object, such as ownership or name.

  */

  AND();

};




/*

NOT gate class.

*/

class NOT: public COMPONENT{

public:

  /*

  NOT gate comprised of TWO ports. A input port, corresponding to "type 0 "
  when calling PORT(int type) constructor && B output port, corresponding to
  "type 1 " when calling PORT(int type) constructor.

  Default port constructor called as variables can only be initialised when
  calling NOT constructor (relevant because of type setting port type will be
  stablished with the set_type(int type) method).

  */

  INPUT_PORT A;
  OUTPUT_PORT B;

  /*

  The update_output() method calls the set_state() method upon the OUTPUT port
  B, taking as parameter the ! of the state of output port A input port.

  */

  void update_output(std::queue<COMPONENT*> &update_queue);

  /*

  The NOT() constructor sets the paramters of the ports within the AND gate
  object, such as ownership or name.

  */

  NOT();

};



/*

Buffer class.

*/

class BUFFER: public COMPONENT{

public:


  /*

  As the name implies it forwards the signal from the port it is connected to

  */

  INPUT_PORT A;
  OUTPUT_PORT B;


  void update_output(std::queue<COMPONENT*> &update_queue);

  BUFFER();


};




/*

Interface Buffer class.

*/

class I_BUFFER: public BUFFER{

public:


  /*

  The interface buffer behaves the same as the buffer class, but its ports
  belong to the component owning the buffer. Hence it is more a container
  of ports than a component with a function.

  */


  //also sets port owner to component owner
  void set_owner(COMPONENT* owner);


  I_BUFFER();


};




/*

Tri-state Buffer class.

*/

class TRI_BUFFER: public COMPONENT{

public:


  /*

  The tri-state buffer behaves the same as the buffer class, but it will not
  communicate updates if the ENABLE port is low.

  */


  INPUT_PORT A;
  OUTPUT_PORT B;

  INPUT_PORT ENABLE;

  //update function
  void update_output(std::queue<COMPONENT*> &update_queue);


  TRI_BUFFER();


};

#endif

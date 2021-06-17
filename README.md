# logic_simulator

A gate-level logic simulator featuring an embedded asynchronous event-driven update scheme i.e. the  simulator only updates those  components whose inputs were affected by the state change of the previous time step.

A queue of events is set up to track components whose state needs to be updated and the simulator only provides an output once the queue is empty.  This allows for repeated update calls on a given component, were its inputs to toggle multiple times, and thus, the order of the update sequence at the start of the simulation is irrelevant.  The simulator is only triggered if there is a state change, and thus when modelling feedback, the simulator will stop running once state is settled within the first two feedback cycles, avoiding an infinite update loop.


Global  state  updates  are  obtained  by  performing  inward  recursive  calls  of  update_output() method, described in Figure 14, for every component within the global level, for every hierarchical level of each component until the axiomatically defined components are reached, where state updates are implicitly defined.  At every level, state propagation is implemented using a system of nested queues.  Once state has settled for a given hierarchical level, it is propagated in an outward recursive fashion, traveling, bottom up through the structure of nested queues for every hierarchical level until reaching the global level.

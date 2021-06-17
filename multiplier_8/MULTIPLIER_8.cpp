#include "MULTIPLIER_8.hpp"
#include <iostream>
#include <vector>


/*

MULTIPLIER_8 class methods

*/

//constructor


MULTIPLIER_8::MULTIPLIER_8(){


  //ownerships, using "this" pointer

  //inputs
  INPUT_BUFFER_A0.set_owner(this);
  INPUT_BUFFER_A1.set_owner(this);
  INPUT_BUFFER_A2.set_owner(this);
  INPUT_BUFFER_A3.set_owner(this);
  INPUT_BUFFER_A4.set_owner(this);
  INPUT_BUFFER_A5.set_owner(this);
  INPUT_BUFFER_A6.set_owner(this);
  INPUT_BUFFER_A7.set_owner(this);

  INPUT_BUFFER_B0.set_owner(this);
  INPUT_BUFFER_B1.set_owner(this);
  INPUT_BUFFER_B2.set_owner(this);
  INPUT_BUFFER_B3.set_owner(this);
  INPUT_BUFFER_B4.set_owner(this);
  INPUT_BUFFER_B5.set_owner(this);
  INPUT_BUFFER_B6.set_owner(this);
  INPUT_BUFFER_B7.set_owner(this);

  //outputs
  OUTPUT_BUFFER_MULT_0.set_owner(this);
  OUTPUT_BUFFER_MULT_1.set_owner(this);
  OUTPUT_BUFFER_MULT_2.set_owner(this);
  OUTPUT_BUFFER_MULT_3.set_owner(this);
  OUTPUT_BUFFER_MULT_4.set_owner(this);
  OUTPUT_BUFFER_MULT_5.set_owner(this);
  OUTPUT_BUFFER_MULT_6.set_owner(this);
  OUTPUT_BUFFER_MULT_7.set_owner(this);

  OUTPUT_BUFFER_MULT_8.set_owner(this);
  OUTPUT_BUFFER_MULT_9.set_owner(this);
  OUTPUT_BUFFER_MULT_10.set_owner(this);
  OUTPUT_BUFFER_MULT_11.set_owner(this);
  OUTPUT_BUFFER_MULT_12.set_owner(this);
  OUTPUT_BUFFER_MULT_13.set_owner(this);
  OUTPUT_BUFFER_MULT_14.set_owner(this);
  OUTPUT_BUFFER_MULT_15.set_owner(this);




  //internal logic
  AND_0.set_owner(this);
  AND_1.set_owner(this);
  AND_2.set_owner(this);
  AND_3.set_owner(this);
  AND_4.set_owner(this);
  AND_5.set_owner(this);
  AND_6.set_owner(this);
  AND_7.set_owner(this);
  AND_8.set_owner(this);
  AND_9.set_owner(this);

  AND_10.set_owner(this);
  AND_11.set_owner(this);
  AND_12.set_owner(this);
  AND_13.set_owner(this);
  AND_14.set_owner(this);
  AND_15.set_owner(this);
  AND_16.set_owner(this);
  AND_17.set_owner(this);
  AND_18.set_owner(this);
  AND_19.set_owner(this);

  AND_20.set_owner(this);
  AND_21.set_owner(this);
  AND_22.set_owner(this);
  AND_23.set_owner(this);
  AND_24.set_owner(this);
  AND_25.set_owner(this);
  AND_26.set_owner(this);
  AND_27.set_owner(this);
  AND_28.set_owner(this);
  AND_29.set_owner(this);

  AND_30.set_owner(this);
  AND_31.set_owner(this);
  AND_32.set_owner(this);
  AND_33.set_owner(this);
  AND_34.set_owner(this);
  AND_35.set_owner(this);
  AND_36.set_owner(this);
  AND_37.set_owner(this);
  AND_38.set_owner(this);
  AND_39.set_owner(this);

  AND_40.set_owner(this);
  AND_41.set_owner(this);
  AND_42.set_owner(this);
  AND_43.set_owner(this);
  AND_44.set_owner(this);
  AND_45.set_owner(this);
  AND_46.set_owner(this);
  AND_47.set_owner(this);
  AND_48.set_owner(this);
  AND_49.set_owner(this);

  AND_50.set_owner(this);
  AND_51.set_owner(this);
  AND_52.set_owner(this);
  AND_53.set_owner(this);
  AND_54.set_owner(this);
  AND_55.set_owner(this);
  AND_56.set_owner(this);
  AND_57.set_owner(this);
  AND_58.set_owner(this);
  AND_59.set_owner(this);

  AND_60.set_owner(this);
  AND_61.set_owner(this);
  AND_62.set_owner(this);
  AND_63.set_owner(this);



  ADDER_8_0.set_owner(this);
  ADDER_8_1.set_owner(this);
  ADDER_8_2.set_owner(this);
  ADDER_8_3.set_owner(this);
  ADDER_8_4.set_owner(this);
  ADDER_8_5.set_owner(this);
  ADDER_8_6.set_owner(this);




  /*

  Define internal component connections

  */

  //ADDERS


  //ADDER_8_0
  ADDER_8_0.INPUT_BUFFER_B0.A.connect(AND_1.C);
  ADDER_8_0.INPUT_BUFFER_B1.A.connect(AND_2.C);
  ADDER_8_0.INPUT_BUFFER_B2.A.connect(AND_3.C);
  ADDER_8_0.INPUT_BUFFER_B3.A.connect(AND_4.C);
  ADDER_8_0.INPUT_BUFFER_B4.A.connect(AND_5.C);
  ADDER_8_0.INPUT_BUFFER_B5.A.connect(AND_6.C);
  ADDER_8_0.INPUT_BUFFER_B6.A.connect(AND_7.C);

  ADDER_8_0.INPUT_BUFFER_B7.A.connect(P0); //connect to co

  ADDER_8_0.INPUT_BUFFER_CARRY_IN.A.connect(P0);

  ADDER_8_0.INPUT_BUFFER_A0.A.connect(AND_8.C);
  ADDER_8_0.INPUT_BUFFER_A1.A.connect(AND_9.C);
  ADDER_8_0.INPUT_BUFFER_A2.A.connect(AND_10.C);
  ADDER_8_0.INPUT_BUFFER_A3.A.connect(AND_11.C);
  ADDER_8_0.INPUT_BUFFER_A4.A.connect(AND_12.C);
  ADDER_8_0.INPUT_BUFFER_A5.A.connect(AND_13.C);
  ADDER_8_0.INPUT_BUFFER_A6.A.connect(AND_14.C);
  ADDER_8_0.INPUT_BUFFER_A7.A.connect(AND_15.C);


  //ADDER_8_1
  ADDER_8_1.INPUT_BUFFER_B0.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_1.INPUT_BUFFER_B1.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_1.INPUT_BUFFER_B2.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_1.INPUT_BUFFER_B3.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_1.INPUT_BUFFER_B4.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_1.INPUT_BUFFER_B5.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_1.INPUT_BUFFER_B6.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_1.INPUT_BUFFER_B7.A.connect(ADDER_8_0.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_1.INPUT_BUFFER_A0.A.connect(AND_16.C);
  ADDER_8_1.INPUT_BUFFER_A1.A.connect(AND_17.C);
  ADDER_8_1.INPUT_BUFFER_A2.A.connect(AND_18.C);
  ADDER_8_1.INPUT_BUFFER_A3.A.connect(AND_19.C);
  ADDER_8_1.INPUT_BUFFER_A4.A.connect(AND_20.C);
  ADDER_8_1.INPUT_BUFFER_A5.A.connect(AND_21.C);
  ADDER_8_1.INPUT_BUFFER_A6.A.connect(AND_22.C);
  ADDER_8_1.INPUT_BUFFER_A7.A.connect(AND_23.C);

  ADDER_8_1.INPUT_BUFFER_CARRY_IN.A.connect(P0);


  //ADDER_8_2
  ADDER_8_2.INPUT_BUFFER_B0.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_2.INPUT_BUFFER_B1.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_2.INPUT_BUFFER_B2.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_2.INPUT_BUFFER_B3.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_2.INPUT_BUFFER_B4.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_2.INPUT_BUFFER_B5.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_2.INPUT_BUFFER_B6.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_2.INPUT_BUFFER_B7.A.connect(ADDER_8_1.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_2.INPUT_BUFFER_A0.A.connect(AND_24.C);
  ADDER_8_2.INPUT_BUFFER_A1.A.connect(AND_25.C);
  ADDER_8_2.INPUT_BUFFER_A2.A.connect(AND_26.C);
  ADDER_8_2.INPUT_BUFFER_A3.A.connect(AND_27.C);
  ADDER_8_2.INPUT_BUFFER_A4.A.connect(AND_28.C);
  ADDER_8_2.INPUT_BUFFER_A5.A.connect(AND_29.C);
  ADDER_8_2.INPUT_BUFFER_A6.A.connect(AND_30.C);
  ADDER_8_2.INPUT_BUFFER_A7.A.connect(AND_31.C);

  ADDER_8_2.INPUT_BUFFER_CARRY_IN.A.connect(P0);


  //ADDER_8_3
  ADDER_8_3.INPUT_BUFFER_B0.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_3.INPUT_BUFFER_B1.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_3.INPUT_BUFFER_B2.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_3.INPUT_BUFFER_B3.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_3.INPUT_BUFFER_B4.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_3.INPUT_BUFFER_B5.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_3.INPUT_BUFFER_B6.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_3.INPUT_BUFFER_B7.A.connect(ADDER_8_2.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_3.INPUT_BUFFER_A0.A.connect(AND_32.C);
  ADDER_8_3.INPUT_BUFFER_A1.A.connect(AND_33.C);
  ADDER_8_3.INPUT_BUFFER_A2.A.connect(AND_34.C);
  ADDER_8_3.INPUT_BUFFER_A3.A.connect(AND_35.C);
  ADDER_8_3.INPUT_BUFFER_A4.A.connect(AND_36.C);
  ADDER_8_3.INPUT_BUFFER_A5.A.connect(AND_37.C);
  ADDER_8_3.INPUT_BUFFER_A6.A.connect(AND_38.C);
  ADDER_8_3.INPUT_BUFFER_A7.A.connect(AND_39.C);

  ADDER_8_3.INPUT_BUFFER_CARRY_IN.A.connect(P0);


  //ADDER_8_4
  ADDER_8_4.INPUT_BUFFER_B0.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_4.INPUT_BUFFER_B1.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_4.INPUT_BUFFER_B2.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_4.INPUT_BUFFER_B3.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_4.INPUT_BUFFER_B4.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_4.INPUT_BUFFER_B5.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_4.INPUT_BUFFER_B6.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_4.INPUT_BUFFER_B7.A.connect(ADDER_8_3.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_4.INPUT_BUFFER_A0.A.connect(AND_40.C);
  ADDER_8_4.INPUT_BUFFER_A1.A.connect(AND_41.C);
  ADDER_8_4.INPUT_BUFFER_A2.A.connect(AND_42.C);
  ADDER_8_4.INPUT_BUFFER_A3.A.connect(AND_43.C);
  ADDER_8_4.INPUT_BUFFER_A4.A.connect(AND_44.C);
  ADDER_8_4.INPUT_BUFFER_A5.A.connect(AND_45.C);
  ADDER_8_4.INPUT_BUFFER_A6.A.connect(AND_46.C);
  ADDER_8_4.INPUT_BUFFER_A7.A.connect(AND_47.C);

  ADDER_8_4.INPUT_BUFFER_CARRY_IN.A.connect(P0);


  //ADDER_8_5
  ADDER_8_5.INPUT_BUFFER_B0.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_5.INPUT_BUFFER_B1.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_5.INPUT_BUFFER_B2.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_5.INPUT_BUFFER_B3.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_5.INPUT_BUFFER_B4.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_5.INPUT_BUFFER_B5.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_5.INPUT_BUFFER_B6.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_5.INPUT_BUFFER_B7.A.connect(ADDER_8_4.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_5.INPUT_BUFFER_A0.A.connect(AND_48.C);
  ADDER_8_5.INPUT_BUFFER_A1.A.connect(AND_49.C);
  ADDER_8_5.INPUT_BUFFER_A2.A.connect(AND_50.C);
  ADDER_8_5.INPUT_BUFFER_A3.A.connect(AND_51.C);
  ADDER_8_5.INPUT_BUFFER_A4.A.connect(AND_52.C);
  ADDER_8_5.INPUT_BUFFER_A5.A.connect(AND_53.C);
  ADDER_8_5.INPUT_BUFFER_A6.A.connect(AND_54.C);
  ADDER_8_5.INPUT_BUFFER_A7.A.connect(AND_55.C);

  ADDER_8_5.INPUT_BUFFER_CARRY_IN.A.connect(P0);


  //ADDER_8_5
  ADDER_8_6.INPUT_BUFFER_B0.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_1.B);
  ADDER_8_6.INPUT_BUFFER_B1.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_2.B);
  ADDER_8_6.INPUT_BUFFER_B2.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_3.B);
  ADDER_8_6.INPUT_BUFFER_B3.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_4.B);
  ADDER_8_6.INPUT_BUFFER_B4.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_5.B);
  ADDER_8_6.INPUT_BUFFER_B5.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_6.B);
  ADDER_8_6.INPUT_BUFFER_B6.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_7.B);
  ADDER_8_6.INPUT_BUFFER_B7.A.connect(ADDER_8_4.OUTPUT_BUFFER_CARRY.B);

  ADDER_8_6.INPUT_BUFFER_A0.A.connect(AND_56.C);
  ADDER_8_6.INPUT_BUFFER_A1.A.connect(AND_57.C);
  ADDER_8_6.INPUT_BUFFER_A2.A.connect(AND_58.C);
  ADDER_8_6.INPUT_BUFFER_A3.A.connect(AND_59.C);
  ADDER_8_6.INPUT_BUFFER_A4.A.connect(AND_60.C);
  ADDER_8_6.INPUT_BUFFER_A5.A.connect(AND_61.C);
  ADDER_8_6.INPUT_BUFFER_A6.A.connect(AND_62.C);
  ADDER_8_6.INPUT_BUFFER_A7.A.connect(AND_63.C);

  ADDER_8_6.INPUT_BUFFER_CARRY_IN.A.connect(P0);



  //AND gates

  //unbelonging
  AND_0.A.connect(INPUT_BUFFER_A0.B);
  AND_0.B.connect(INPUT_BUFFER_B0.B);

  //belonging to ADDER_0
  AND_1.A.connect(INPUT_BUFFER_A1.B);
  AND_2.A.connect(INPUT_BUFFER_A2.B);
  AND_3.A.connect(INPUT_BUFFER_A3.B);
  AND_4.A.connect(INPUT_BUFFER_A4.B);
  AND_5.A.connect(INPUT_BUFFER_A5.B);
  AND_6.A.connect(INPUT_BUFFER_A6.B);
  AND_7.A.connect(INPUT_BUFFER_A7.B);

  AND_1.B.connect(INPUT_BUFFER_B0.B);
  AND_2.B.connect(INPUT_BUFFER_B0.B);
  AND_3.B.connect(INPUT_BUFFER_B0.B);
  AND_4.B.connect(INPUT_BUFFER_B0.B);
  AND_5.B.connect(INPUT_BUFFER_B0.B);
  AND_6.B.connect(INPUT_BUFFER_B0.B);
  AND_7.B.connect(INPUT_BUFFER_B0.B);


  AND_8.A.connect(INPUT_BUFFER_A0.B);
  AND_9.A.connect(INPUT_BUFFER_A1.B);
  AND_10.A.connect(INPUT_BUFFER_A2.B);
  AND_11.A.connect(INPUT_BUFFER_A3.B);
  AND_12.A.connect(INPUT_BUFFER_A4.B);
  AND_13.A.connect(INPUT_BUFFER_A5.B);
  AND_14.A.connect(INPUT_BUFFER_A6.B);
  AND_15.A.connect(INPUT_BUFFER_A7.B);

  AND_8.B.connect(INPUT_BUFFER_B1.B);
  AND_9.B.connect(INPUT_BUFFER_B1.B);
  AND_10.B.connect(INPUT_BUFFER_B1.B);
  AND_11.B.connect(INPUT_BUFFER_B1.B);
  AND_12.B.connect(INPUT_BUFFER_B1.B);
  AND_13.B.connect(INPUT_BUFFER_B1.B);
  AND_14.B.connect(INPUT_BUFFER_B1.B);
  AND_15.B.connect(INPUT_BUFFER_B1.B);



  //belonging to ADDER_1
  AND_16.A.connect(INPUT_BUFFER_A0.B);
  AND_17.A.connect(INPUT_BUFFER_A1.B);
  AND_18.A.connect(INPUT_BUFFER_A2.B);
  AND_19.A.connect(INPUT_BUFFER_A3.B);
  AND_20.A.connect(INPUT_BUFFER_A4.B);
  AND_21.A.connect(INPUT_BUFFER_A5.B);
  AND_22.A.connect(INPUT_BUFFER_A6.B);
  AND_23.A.connect(INPUT_BUFFER_A7.B);

  AND_16.B.connect(INPUT_BUFFER_B2.B);
  AND_17.B.connect(INPUT_BUFFER_B2.B);
  AND_18.B.connect(INPUT_BUFFER_B2.B);
  AND_19.B.connect(INPUT_BUFFER_B2.B);
  AND_20.B.connect(INPUT_BUFFER_B2.B);
  AND_21.B.connect(INPUT_BUFFER_B2.B);
  AND_22.B.connect(INPUT_BUFFER_B2.B);
  AND_23.B.connect(INPUT_BUFFER_B2.B);


  //belonging to ADDER_2
  AND_24.A.connect(INPUT_BUFFER_A0.B);
  AND_25.A.connect(INPUT_BUFFER_A1.B);
  AND_26.A.connect(INPUT_BUFFER_A2.B);
  AND_27.A.connect(INPUT_BUFFER_A3.B);
  AND_28.A.connect(INPUT_BUFFER_A4.B);
  AND_29.A.connect(INPUT_BUFFER_A5.B);
  AND_30.A.connect(INPUT_BUFFER_A6.B);
  AND_31.A.connect(INPUT_BUFFER_A7.B);

  AND_24.B.connect(INPUT_BUFFER_B3.B);
  AND_25.B.connect(INPUT_BUFFER_B3.B);
  AND_26.B.connect(INPUT_BUFFER_B3.B);
  AND_27.B.connect(INPUT_BUFFER_B3.B);
  AND_28.B.connect(INPUT_BUFFER_B3.B);
  AND_29.B.connect(INPUT_BUFFER_B3.B);
  AND_30.B.connect(INPUT_BUFFER_B3.B);
  AND_31.B.connect(INPUT_BUFFER_B3.B);


  //belonging to ADDER_3
  AND_32.A.connect(INPUT_BUFFER_A0.B);
  AND_33.A.connect(INPUT_BUFFER_A1.B);
  AND_34.A.connect(INPUT_BUFFER_A2.B);
  AND_35.A.connect(INPUT_BUFFER_A3.B);
  AND_36.A.connect(INPUT_BUFFER_A4.B);
  AND_37.A.connect(INPUT_BUFFER_A5.B);
  AND_38.A.connect(INPUT_BUFFER_A6.B);
  AND_39.A.connect(INPUT_BUFFER_A7.B);

  AND_32.B.connect(INPUT_BUFFER_B4.B);
  AND_33.B.connect(INPUT_BUFFER_B4.B);
  AND_34.B.connect(INPUT_BUFFER_B4.B);
  AND_35.B.connect(INPUT_BUFFER_B4.B);
  AND_36.B.connect(INPUT_BUFFER_B4.B);
  AND_37.B.connect(INPUT_BUFFER_B4.B);
  AND_38.B.connect(INPUT_BUFFER_B4.B);
  AND_39.B.connect(INPUT_BUFFER_B4.B);


  //belonging to ADDER_4
  AND_40.A.connect(INPUT_BUFFER_A0.B);
  AND_41.A.connect(INPUT_BUFFER_A1.B);
  AND_42.A.connect(INPUT_BUFFER_A2.B);
  AND_43.A.connect(INPUT_BUFFER_A3.B);
  AND_44.A.connect(INPUT_BUFFER_A4.B);
  AND_45.A.connect(INPUT_BUFFER_A5.B);
  AND_46.A.connect(INPUT_BUFFER_A6.B);
  AND_47.A.connect(INPUT_BUFFER_A7.B);

  AND_40.B.connect(INPUT_BUFFER_B5.B);
  AND_41.B.connect(INPUT_BUFFER_B5.B);
  AND_42.B.connect(INPUT_BUFFER_B5.B);
  AND_43.B.connect(INPUT_BUFFER_B5.B);
  AND_44.B.connect(INPUT_BUFFER_B5.B);
  AND_45.B.connect(INPUT_BUFFER_B5.B);
  AND_46.B.connect(INPUT_BUFFER_B5.B);
  AND_47.B.connect(INPUT_BUFFER_B5.B);


  //belonging to ADDER_5
  AND_48.A.connect(INPUT_BUFFER_A0.B);
  AND_49.A.connect(INPUT_BUFFER_A1.B);
  AND_50.A.connect(INPUT_BUFFER_A2.B);
  AND_51.A.connect(INPUT_BUFFER_A3.B);
  AND_52.A.connect(INPUT_BUFFER_A4.B);
  AND_53.A.connect(INPUT_BUFFER_A5.B);
  AND_54.A.connect(INPUT_BUFFER_A6.B);
  AND_55.A.connect(INPUT_BUFFER_A7.B);

  AND_48.B.connect(INPUT_BUFFER_B6.B);
  AND_49.B.connect(INPUT_BUFFER_B6.B);
  AND_50.B.connect(INPUT_BUFFER_B6.B);
  AND_51.B.connect(INPUT_BUFFER_B6.B);
  AND_52.B.connect(INPUT_BUFFER_B6.B);
  AND_53.B.connect(INPUT_BUFFER_B6.B);
  AND_54.B.connect(INPUT_BUFFER_B6.B);
  AND_55.B.connect(INPUT_BUFFER_B6.B);


  //belonging to ADDER_5
  AND_56.A.connect(INPUT_BUFFER_A0.B);
  AND_57.A.connect(INPUT_BUFFER_A1.B);
  AND_58.A.connect(INPUT_BUFFER_A2.B);
  AND_59.A.connect(INPUT_BUFFER_A3.B);
  AND_60.A.connect(INPUT_BUFFER_A4.B);
  AND_61.A.connect(INPUT_BUFFER_A5.B);
  AND_62.A.connect(INPUT_BUFFER_A6.B);
  AND_63.A.connect(INPUT_BUFFER_A7.B);

  AND_56.B.connect(INPUT_BUFFER_B7.B);
  AND_57.B.connect(INPUT_BUFFER_B7.B);
  AND_58.B.connect(INPUT_BUFFER_B7.B);
  AND_59.B.connect(INPUT_BUFFER_B7.B);
  AND_60.B.connect(INPUT_BUFFER_B7.B);
  AND_61.B.connect(INPUT_BUFFER_B7.B);
  AND_62.B.connect(INPUT_BUFFER_B7.B);
  AND_63.B.connect(INPUT_BUFFER_B7.B);


  //outputs
  OUTPUT_BUFFER_MULT_0.A.connect(AND_0.C);

  OUTPUT_BUFFER_MULT_1.A.connect(ADDER_8_0.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_2.A.connect(ADDER_8_1.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_3.A.connect(ADDER_8_2.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_4.A.connect(ADDER_8_3.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_5.A.connect(ADDER_8_4.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_6.A.connect(ADDER_8_5.OUTPUT_BUFFER_SUM_0.B);
  OUTPUT_BUFFER_MULT_7.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_0.B);

  OUTPUT_BUFFER_MULT_8.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_1.B);
  OUTPUT_BUFFER_MULT_9.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_2.B);
  OUTPUT_BUFFER_MULT_10.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_3.B);
  OUTPUT_BUFFER_MULT_11.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_4.B);
  OUTPUT_BUFFER_MULT_12.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_5.B);
  OUTPUT_BUFFER_MULT_13.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_6.B);
  OUTPUT_BUFFER_MULT_14.A.connect(ADDER_8_6.OUTPUT_BUFFER_SUM_7.B);
  OUTPUT_BUFFER_MULT_15.A.connect(ADDER_8_6.OUTPUT_BUFFER_CARRY.B);










  //output list definition
  output_list.push_back(&OUTPUT_BUFFER_MULT_0);
  output_list.push_back(&OUTPUT_BUFFER_MULT_1);
  output_list.push_back(&OUTPUT_BUFFER_MULT_2);
  output_list.push_back(&OUTPUT_BUFFER_MULT_3);
  output_list.push_back(&OUTPUT_BUFFER_MULT_4);
  output_list.push_back(&OUTPUT_BUFFER_MULT_5);
  output_list.push_back(&OUTPUT_BUFFER_MULT_6);
  output_list.push_back(&OUTPUT_BUFFER_MULT_7);

  output_list.push_back(&OUTPUT_BUFFER_MULT_8);
  output_list.push_back(&OUTPUT_BUFFER_MULT_9);
  output_list.push_back(&OUTPUT_BUFFER_MULT_10);
  output_list.push_back(&OUTPUT_BUFFER_MULT_11);
  output_list.push_back(&OUTPUT_BUFFER_MULT_12);
  output_list.push_back(&OUTPUT_BUFFER_MULT_13);
  output_list.push_back(&OUTPUT_BUFFER_MULT_14);
  output_list.push_back(&OUTPUT_BUFFER_MULT_15);


}



//update function

void MULTIPLIER_8::update_output(std::queue<COMPONENT*> &external_update_queue){

  // //store previous state
  // std::vector<bool> prev_state;
  // bool prev_state_carry;

  // prev_state.push_back(OUTPUT_BUFFER_SUM_0.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_1.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_2.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_3.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_4.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_5.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_6.B.get_state());
  // prev_state.push_back(OUTPUT_BUFFER_SUM_7.B.get_state());
  //
  // prev_state_carry = OUTPUT_BUFFER_CARRY.B.get_state();

  //internal update queue
  std::queue<COMPONENT*> internal_update_queue;

  INPUT_BUFFER_A0.update_output(internal_update_queue);
  INPUT_BUFFER_A1.update_output(internal_update_queue);
  INPUT_BUFFER_A2.update_output(internal_update_queue);
  INPUT_BUFFER_A3.update_output(internal_update_queue);
  INPUT_BUFFER_A4.update_output(internal_update_queue);
  INPUT_BUFFER_A5.update_output(internal_update_queue);
  INPUT_BUFFER_A6.update_output(internal_update_queue);
  INPUT_BUFFER_A7.update_output(internal_update_queue);

  INPUT_BUFFER_B0.update_output(internal_update_queue);
  INPUT_BUFFER_B1.update_output(internal_update_queue);
  INPUT_BUFFER_B2.update_output(internal_update_queue);
  INPUT_BUFFER_B3.update_output(internal_update_queue);
  INPUT_BUFFER_B4.update_output(internal_update_queue);
  INPUT_BUFFER_B5.update_output(internal_update_queue);
  INPUT_BUFFER_B6.update_output(internal_update_queue);
  INPUT_BUFFER_B7.update_output(internal_update_queue);

  // INPUT_BUFFER_CARRY_IN.update_output(internal_update_queue);

  while(!internal_update_queue.empty()){

    // if ((*(internal_update_queue.front())).get_owner() == this){

      (*(internal_update_queue.front())).update_output(internal_update_queue);
      internal_update_queue.pop();
    // }

    // else {
    //
    //   internal_update_queue.pop();
    // }

  }

  // //initialisation forced run
  //
  // if (!(this->initialisation_flag)){
  //
  //   this->initialisation_flag = 1;
  //
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_0.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_0.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_1.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_1.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_2.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_2.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_3.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_3.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_4.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_4.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_5.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_5.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_6.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_6.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_SUM_7.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_SUM_7.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
  //   }
  //
  //
  //
  // }
  //
  //
  // //normal update cycle
  //
  // for (int i = 0; i < output_list.size(); i++){
  //
  //   if (prev_state[i] != (*(output_list[i])).B.get_state()){
  //
  //     for (int i = 0; i < (*(output_list[i])).B.get_fanout_size(); i++ ){
  //
  //       external_update_queue.push((*((*(output_list[i])).B.get_fanout_address(i))).get_owner());
  //     }
  //   }
  // }
  //
  //
  // if (prev_state_carry != OUTPUT_BUFFER_CARRY.B.get_state()){
  //
  //   for (int i = 0; i < OUTPUT_BUFFER_CARRY.B.get_fanout_size(); i++ ){
  //
  //     external_update_queue.push((*(OUTPUT_BUFFER_CARRY.B.get_fanout_address(i))).get_owner());
  //   }
  // }

}

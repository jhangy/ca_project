#include "./hpp/simulator.hpp"
#include "./hpp/path_generator.hpp"

#include <iostream>
#include <vector>

int main(){

  std::cout<<"Start simulation: "<<std::endl;

  /* initialize the path generator */
  PathGenerator pa_gen;
  pa_gen.add_default_path_midterm();
  // pa_gen.show_path();

  /* initialize the Simulator */
  Simulator sim;
  sim.set_branch_ins_list(pa_gen.get_path());
  sim.set_predictor(PredictorList::PIECEWISELINEAR);
  // sim.show_w();
  /* run simulation*/
  sim.set_running_times(3);
  sim.show_GA();
  sim.show_GBR();
  sim.run();
  sim.show_GA();
  sim.show_GBR();
  sim.show_ad_his();
  sim.show_path();
  
  sim.show_pred_path();
  sim.show_acc_pred_path();

  // sim.show_w();

  double acc = sim.get_accuracy();
  std::cout<<"The predictor accuracy is: "<<acc<<std::endl;


  std::cout<<"End simulation. "<<std::endl;
  return 0;
}
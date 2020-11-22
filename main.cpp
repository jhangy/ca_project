#include "./hpp/simulator.hpp"
#include "./hpp/path_generator.hpp"

#include <iostream>
#include <vector>

int main(){

  std::cout<<"Start simulation: "<<std::endl;

  /* initialize the path generator */
  PathGenerator pa_gen;
  pa_gen.add_default_path();
  pa_gen.show_path();

  /* initialize the Simulator */
  Simulator sim;
  sim.set_branch_path(pa_gen.get_path());
  sim.set_predictor(PredictorList::BPREDICT_NOT_TAKEN);

  /* run simulation*/
  sim.show_path();
  sim.run();
  sim.show_pred_path();
  sim.show_acc_pred_path();

  double acc = sim.get_accuracy();
  std::cout<<"The predictor accuracy is: "<<acc<<std::endl;

  std::cout<<"End simulation. "<<std::endl;
  return 0;
}
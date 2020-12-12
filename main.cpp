#include "./hpp/simulator.hpp"
#include "./hpp/path_generator.hpp"

#include <iostream>
#include <vector>

int main(){

  std::cout<<"Start simulation: "<<std::endl;

  /* initialize the path generator */
  PathGenerator pa_gen;
  pa_gen.add_default_path_custom();
  // pa_gen.add_default_path_midterm();
  // pa_gen.show_path();

  /* initialize the Simulator */

  for(int i=1;i<10;i++){
    Simulator sim(10);
    sim.set_branch_ins_list(pa_gen.get_path());
    sim.set_predictor(PredictorList::PIECEWISELINEAR,i,10-i,10);
    sim.set_running_times(10);
    sim.run();
    double acc = sim.get_accuracy();
    std::cout<<"The predictor ("<<i<<","<<10-i<<","<<10<<") accuracy is: "<<acc<<std::endl;
  }

  std::cout<<"End simulation. "<<std::endl;
  return 0;
}
#ifndef __PREDICTOR_HPP__
#define __PREDICTOR_HPP__

#include <cstdio>
#include <vector>
#include <iostream>
#include "definition.hpp"

enum class PredictorList{
  NOPREDICOTR,
  BPREDICT_NOT_TAKEN
};

class PredictorBase{
  int _size_history_buffer;
  std::vector<BranchResult> _history_buffer;
public:
  ~PredictorBase(){}
  virtual BranchResult predict_branch(int index_pc, BranchResult next_branch){
    std::cout<<"[PredictorBase]This is fahter of predictor. Please initialize a type of predictor.";}
};

class BpredNotTaken:  public PredictorBase{

public:
  BpredNotTaken(){}
  ~BpredNotTaken(){}
  BranchResult predict_branch(int index_pc, BranchResult next_branch);
};

#endif
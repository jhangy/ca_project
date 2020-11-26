#ifndef __PREDICTOR_HPP__
#define __PREDICTOR_HPP__

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdint>

#include "definition.hpp"

enum class PredictorList{
  NOPREDICOTR,
  BPREDICT_NOT_TAKEN,
  PIECEWISELINEAR
};

class PredictorBase{

  int _size_history_buffer;
  std::vector<BranchResult> _history_buffer;

public:

  ~PredictorBase(){}

  virtual void initialize_W(int d1st, int d2nd, int d3rd){
    std::cout<<"[PredictorBase]This is fahter of predictor. Please initialize a type of predictor.";}

  virtual BranchResult predict_branch(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR){
    std::cout<<"[PredictorBase]This is fahter of predictor. Please initialize a type of predictor.";}

  virtual void update_weigths(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR, BranchResult outcome){
    std::cout<<"[PredictorBase]This is fahter of predictor. Please initialize a type of predictor.";}
    
};

class BpredNotTaken:  public PredictorBase{

public:

  BpredNotTaken(){}
  ~BpredNotTaken(){}
  BranchResult predict_branch(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR);
  void update_weigths(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR, BranchResult outcome){
    std::cout<<"[BpredNotTaken]No need to update.";}
};

class PiecewiseLinear:  public PredictorBase{
  int size_1d = 0;
  int size_2d = 0;
  int size_3d = 0;
  std::vector<std::vector<std::vector<int>>> W;

public:

  PiecewiseLinear(){}
  ~PiecewiseLinear(){}

  // initialisze size of W
  void initialize_W(int d1st, int d2nd, int d3rd);

  // predict branch
  BranchResult predict_branch(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR);

  // update outcome if not right
  void update_weigths(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR, BranchResult outcome);

};

#endif
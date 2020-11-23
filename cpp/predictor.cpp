#include "predictor.hpp"

BranchResult BpredNotTaken::predict_branch(int index_pc, BranchResult next_branch){
  return BranchResult::NOT_TAKEN;
}

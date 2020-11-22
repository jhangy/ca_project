#include "predictor.hpp"

BranchResult BpredNotTaken::predict_branch(BranchResult next_branch){
  return BranchResult::NOT_TAKEN;
}

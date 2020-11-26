#include "predictor.hpp"

BranchResult BpredNotTaken::predict_branch(int index_pc, std::vector<uint32_t> &GA, std::vector<BranchResult> &GHR){
  
  return BranchResult::NOT_TAKEN;

}


void PiecewiseLinear::initialize_W(int d1st, int d2nd, int d3rd ){

  std::vector<int> position_global_history;
  std::vector<std::vector<int>> global_history;

  size_1d = d1st;
  size_2d = d2nd;
  size_3d = d3rd;

  for(int k = 0 ; k < d3rd ; k++){
    position_global_history.push_back(0);
  }
  for(int j = 0 ; j < d2nd ; j++){
    global_history.push_back(position_global_history);
  }
  for(int i = 0 ; i < d1st ; i++){
    W.push_back(global_history);
  }

}

BranchResult PiecewiseLinear::predict_branch(int index_pc, 
                                             std::vector<uint32_t> &GA,  
                                             std::vector<BranchResult> &GHR){

BranchResult prediction=BranchResult::NOT_TAKEN;

int index_1d = index_pc%size_1d;

int predict_weight = 0;

int length_GA = GA.size();

predict_weight = W[index_1d][0][0];

if(length_GA>0){
  for(int ibr = 0; ibr < length_GA ; ibr++){
    int index_2d = GA[ibr]%size_2d;
    int index_3d = (ibr + 1)%size_3d;
    predict_weight = predict_weight + W[index_1d][index_2d][index_3d];
  }
}


if(predict_weight > -1){
  prediction = BranchResult::TAKEN;
}

return prediction;

}

void PiecewiseLinear::update_weigths(int index_pc,
                                     std::vector<uint32_t> &GA,
                                     std::vector<BranchResult> &GHR, 
                                     BranchResult outcome){

  int index_1d = index_pc%size_1d;

  int length_GA = GA.size();

  if(outcome == BranchResult::TAKEN){
    W[index_1d][0][0] = W[index_1d][0][0] + 1;
  }else{
    W[index_1d][0][0] = W[index_1d][0][0] - 1;
  }

  if(length_GA>0){
    for(int ibr = 0; ibr < length_GA ; ibr++){
      int index_2d = GA[ibr]%size_2d;
      int index_3d = (ibr + 1)%size_3d;
      if(GHR[ibr]==outcome){
        W[index_1d][index_2d][index_3d] = W[index_1d][index_2d][index_3d] + 1;
      }else{
        W[index_1d][index_2d][index_3d] = W[index_1d][index_2d][index_3d] - 1;
      }
    }
  }
  
}
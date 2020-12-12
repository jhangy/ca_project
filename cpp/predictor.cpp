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

  for(int k = 0 ; k < d3rd + 1 ; k++){
    position_global_history.push_back(0);
  }
  for(int j = 0 ; j < d2nd + 1 ; j++){
    global_history.push_back(position_global_history);
  }
  for(int i = 0 ; i < d1st ; i++){
    W.push_back(global_history);
  }

}

 void PiecewiseLinear::show_W(){

  for(int i = 0 ; i < size_1d; i++){ 
    std::cout<<"i = "<<i<<std::endl;
    for(int j = 0 ; j < size_2d + 1; j++){
      for(int k = 0 ; k < size_3d + 1; k++){
        std::cout<<"("<<i<<","<<j<<","<<k<<") = "<< W[i][j][k] <<" ";
      }
      std::cout<<"\n";
    }
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
    int index_2d = GA[ibr]%size_2d + 1;
    int index_3d = (ibr)%(size_3d) + 1;
    if(GHR[ibr]==BranchResult::TAKEN){
      predict_weight = predict_weight + W[index_1d][index_2d][index_3d];
    }else{
      predict_weight = predict_weight - W[index_1d][index_2d][index_3d];
    }      
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

  // std::cout<<"outcome!=prediction in PC: "<<index_pc<<std::endl;

  int index_1d = index_pc%size_1d;

  int length_GA = GA.size();

  if(outcome == BranchResult::TAKEN){
    W[index_1d][0][0] = W[index_1d][0][0] + 1;
  }else{
    W[index_1d][0][0] = W[index_1d][0][0] - 1;
  }

  if(length_GA>0){
    for(int ibr = 0; ibr < length_GA ; ibr++){
      int index_2d = GA[ibr]%size_2d + 1;
      int index_3d = (ibr)%(size_3d) + 1;
      if(GHR[ibr]==outcome){
        W[index_1d][index_2d][index_3d] = W[index_1d][index_2d][index_3d] + 1;
        // std::cout<<"("<<index_1d<<","<<index_2d<<","<<index_3d<<") + 1\n";
      }else{
        W[index_1d][index_2d][index_3d] = W[index_1d][index_2d][index_3d] - 1;
        // std::cout<<"("<<index_1d<<","<<index_2d<<","<<index_3d<<") - 1\n";
      }
    }
  }
  // show_W();
}
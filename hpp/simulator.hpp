#ifndef __SIMULATOR_HPP__
#define __SIMULATOR_HPP__

#include <cstdio>
#include <vector>

#include "definition.hpp"
#include "predictor.hpp"

class Simulator{

    // store the branch path which will be used to simulate predictor
    std::vector<BranchResult> branch_path;

    // store the result which is predicted by predictor
    std::vector<BranchResult> branch_pred;

    // the accuracy of every prediction
    std::vector<bool> pred_result;

    // Predictor
    PredictorBase * predictor;

public:

    Simulator();

    // initial the path of branch 
    void set_branch_path(std::vector<BranchResult> *b_path);

    // initial the predictor
    void set_predictor(PredictorList pred_ty);

    // run simulator
    void run();

    // evaluate accuracy
    double get_accuracy();

    //print path
    void show_path();

    //print prdict history
    void show_pred_path();

    //print true or fail
    void show_acc_pred_path();

    void view_branch_value(BranchResult br){
        switch(static_cast<BranchResult>(br)){
            case BranchResult::TAKEN:{
                std::cout<<"T  ";
                break;
            }
            case BranchResult::NOT_TAKEN:{
                std::cout<<"NT ";
                break;            
            }
        }
    }
};

#endif /* __SIMULATOR_HPP__ */
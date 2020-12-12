#ifndef __SIMULATOR_HPP__
#define __SIMULATOR_HPP__

#include <cstdio>
#include <vector>

#include "definition.hpp"
#include "predictor.hpp"

class Simulator{
    // maximum global history length
    int length_global_his = 10;

    // store the branch outcome history
    std::vector<BranchResult> branch_history;

    // store the address of branch outcome history
    std::vector<uint32_t> address_branch_history;

    // the buf of global branch history register 
    std::vector<BranchResult> branch_history_buf;

    // the buf of address of global branch history register 
    std::vector<uint32_t> address_branch_history_buf;

    // store the ins branch path which will be used to simulate predictor
    std::vector<BranchIns *> branch_ins_list;

    // store the result which is predicted by predictor
    std::vector<BranchResult> branch_pred;

    // the accuracy of every prediction
    std::vector<bool> pred_result;

    // Predictor
    PredictorBase * predictor;
    
    // run times
    int total_running = 1;

public:

    Simulator();
    Simulator(int size_his_reg);

    // set global history length
    void set_global_history_size(int size){length_global_his = size;}

    // set running times
    void set_running_times(int num){total_running = num;}

    // initial the path of branch 
    void set_branch_ins_list(std::vector<BranchIns *> *b_list);

    // initial the predictor
    void set_predictor(PredictorList pred_ty,int size_local_branch=5, int size_global_branch=5, int size_global_his=5);

    // run simulator
    void run();

    // evaluate accuracy
    double get_accuracy();

    //print path
    void show_path();

    //print GA
    void show_GA();

    //print address history
    void show_ad_his();

    //print GBR
    void show_GBR();

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
    
    // for debugging
    void show_w(){
        predictor->show_W();
    };

};

#endif /* __SIMULATOR_HPP__ */
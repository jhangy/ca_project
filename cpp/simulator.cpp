// #include "../hpp/simulator.hpp"
#include "simulator.hpp"

#include <iostream>

Simulator::Simulator(){
}

void Simulator::show_path(){
    int length = 0;
    
    if(branch_path.empty()){
        std::cout<<"[Simulator]The path is empty. Please add path.\n";
    }else{
        length = branch_path.size();
        std::cout<<"Branch Path is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                view_branch_value(branch_path[ibranch]);
            }else{
                std::cout<<"\n";
                view_branch_value(branch_path[ibranch]);
            }
        }
        std::cout<<"\n";
    }
}

void Simulator::show_pred_path(){
    int length = 0;
    if(branch_pred.empty()){
        std::cout<<"[Simulator]The predict history is empty.\n";
    }else{
        length = branch_pred.size();
        std::cout<<"Predict history is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                view_branch_value(branch_pred[ibranch]);
            }else{
                std::cout<<"\n";
                view_branch_value(branch_pred[ibranch]);
            }
        }
        std::cout<<"\n";
    }
}

void Simulator::show_acc_pred_path(){
    int length = 0;
    if(pred_result.empty()){
        std::cout<<"[Simulator]The predict result is empty.\n";
    }else{
        length = pred_result.size();
        std::cout<<"Predict result is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                std::cout<<pred_result[ibranch]<<" ";
            }else{
                std::cout<<"\n";
                std::cout<<pred_result[ibranch]<<" ";
            }
        }
        std::cout<<"\n";
    }
}

void Simulator::set_branch_path(std::vector<BranchResult> *b_path){
    branch_path.insert(branch_path.begin(),b_path->begin(), b_path->end());
}

void Simulator::set_predictor(PredictorList pred_ty){
    switch(static_cast<PredictorList>(pred_ty)){
        case PredictorList::NOPREDICOTR:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
            break;
        }
        case PredictorList::BPREDICT_NOT_TAKEN:{
            predictor = new BpredNotTaken;
            break;
        }
        default:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
        }
    }
}


void Simulator::run(){
    BranchResult current_branch = BranchResult::NOT_TAKEN;
    for(int ibranch=0;ibranch<branch_path.size();ibranch++){
        BranchResult predicted_branch =  predictor->predict_branch(current_branch);
        branch_pred.push_back(predicted_branch);
        if(predicted_branch == branch_path[ibranch]){
            pred_result.push_back(true);
        }else{
            pred_result.push_back(false);
        }
    }
}

double Simulator::get_accuracy(){
    double acc = 0;
    if(pred_result.empty()){
        std::cout<<"[Simulator]No result!\n";
    }else{
        int right = 0;
        int wrong = 0;
        for(int i=0;i<pred_result.size();i++){
            if(pred_result[i]==true){
                right++;
            }else{
                wrong++;
            }
        }
        return double(double(right)/double(pred_result.size()));
    }
}
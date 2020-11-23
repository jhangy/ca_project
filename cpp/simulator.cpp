// #include "../hpp/simulator.hpp"
#include "simulator.hpp"

#include <iostream>

Simulator::Simulator(){
}

void Simulator::show_path(){
    int length = 0;
    
    if(branch_history.empty()){
        std::cout<<"[Simulator]The path is empty. Please add path.\n";
    }else{
        length = branch_history.size();
        std::cout<<"Branch Path is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                view_branch_value(branch_history[ibranch]);
            }else{
                std::cout<<"\n";
                view_branch_value(branch_history[ibranch]);
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

void Simulator::set_branch_ins_list(std::vector<BranchIns *> *b_list){
    std::cout<<"Num of ins branch: "<<b_list->size()<<std::endl;
    branch_ins_list.insert(branch_ins_list.begin(),b_list->begin(), b_list->end());
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

    for(int irun = 0; irun < total_running ; irun++){

        for(int ibranch=0;ibranch<branch_ins_list.size();ibranch++){

            BranchResult current_branch = branch_ins_list[ibranch]->get_cur_dir();
            int pc_now = branch_ins_list[ibranch]->get_index_pc();
            BranchResult predicted_branch =  predictor->predict_branch(pc_now, current_branch);
            
            branch_history.push_back(current_branch);
            branch_pred.push_back(predicted_branch);

            if(predicted_branch == current_branch){
                pred_result.push_back(true);
            }else{
                pred_result.push_back(false);
            }
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
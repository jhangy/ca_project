// #include "../hpp/simulator.hpp"
#include "simulator.hpp"

#include <iostream>

Simulator::Simulator(){
    // the size of global history reg is set to 10
    for(int i = 0; i < length_global_his; i++){
        branch_history_buf.push_back(BranchResult::TAKEN);
    }
    for(int i = 0; i < length_global_his; i++){
        address_branch_history_buf.push_back(0);
    }
    predictor=nullptr;
}

Simulator::Simulator(int size_his_reg){
    length_global_his = size_his_reg;
    for(int i = 0; i < length_global_his; i++){
        branch_history_buf.push_back(BranchResult::TAKEN);
    }
    for(int i = 0; i < length_global_his; i++){
        address_branch_history_buf.push_back(0);
    }
    predictor=nullptr;
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

void Simulator::show_GBR(){
    int length = 0;
    
    if(branch_history_buf.empty()){
        std::cout<<"[Simulator]The buf is empty. Please add buf.\n";
    }else{
        length = branch_history_buf.size();
        std::cout<<"GBR is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                view_branch_value(branch_history_buf[ibranch]);
            }else{
                std::cout<<"\n";
                view_branch_value(branch_history_buf[ibranch]);
            }
        }
        std::cout<<"\n";
    }
}


void Simulator::show_GA(){
    int length = 0;
    
    if(address_branch_history_buf.empty()){
        std::cout<<"[Simulator]The GA is empty. Please add buf.\n";
    }else{
        length = address_branch_history_buf.size();
        std::cout<<"GBR is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                std::cout<<address_branch_history_buf[ibranch]<<" ";
            }else{
                std::cout<<"\n";
                std::cout<<address_branch_history_buf[ibranch]<<" ";
            }
        }
        std::cout<<"\n";
    }
}

void Simulator::show_ad_his(){
    int length = 0;
    
    if(address_branch_history.empty()){
        std::cout<<"[Simulator]The GA is empty. Please add buf.\n";
    }else{
        length = address_branch_history.size();
        std::cout<<"addr_his is :"<<length<<std::endl;
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                std::cout<<address_branch_history[ibranch]<<" ";
            }else{
                std::cout<<"\n";
                std::cout<<address_branch_history[ibranch]<<" ";
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

void Simulator::set_predictor(PredictorList pred_ty, int size_local_branch, int size_global_branch, int size_global_his){
    if(predictor==nullptr){
        switch(static_cast<PredictorList>(pred_ty)){
        case PredictorList::NOPREDICOTR:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
            break;
        }
        case PredictorList::BPREDICT_NOT_TAKEN:{
            predictor = new BpredNotTaken;
            break;
        }
        case PredictorList::PIECEWISELINEAR:{
            predictor = new PiecewiseLinear;
            predictor->initialize_W(size_local_branch,size_global_branch,size_global_his);
            break;
        }
        default:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
        }
        }
    }else{
        delete predictor;
        predictor==nullptr;
        switch(static_cast<PredictorList>(pred_ty)){
        case PredictorList::NOPREDICOTR:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
            break;
        }
        case PredictorList::BPREDICT_NOT_TAKEN:{
            predictor = new BpredNotTaken;
            break;
        }
        case PredictorList::PIECEWISELINEAR:{
            predictor = new PiecewiseLinear;
            predictor->initialize_W(size_local_branch,size_global_branch,size_global_his);
            break;
        }
        default:{
            std::cout<<"[Simulator]Should initialize a predictor\n";
        }
        }
    }
    
}


void Simulator::run(){

    for(int irun = 0; irun < total_running ; irun++){

        for(int ibranch=0;ibranch<branch_ins_list.size();ibranch++){

            BranchResult current_branch_result = branch_ins_list[ibranch]->get_cur_dir();
            int pc_now = branch_ins_list[ibranch]->get_index_pc();
            BranchResult predicted_branch =  predictor->predict_branch(pc_now, address_branch_history_buf, branch_history_buf);

            if(predicted_branch == current_branch_result){
                pred_result.insert(pred_result.begin(),true);
            }else{
                pred_result.insert(pred_result.begin(),false);
                predictor->update_weigths(pc_now, address_branch_history_buf, branch_history_buf,current_branch_result);
            }
            
            address_branch_history_buf.pop_back();
            address_branch_history_buf.insert(address_branch_history_buf.begin(),pc_now);
            address_branch_history.insert(address_branch_history.begin(),pc_now);

            branch_history_buf.pop_back();
            branch_history_buf.insert(branch_history_buf.begin(),current_branch_result);
            branch_history.insert(branch_history.begin(),current_branch_result);

            branch_pred.insert(branch_pred.begin(),predicted_branch);

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
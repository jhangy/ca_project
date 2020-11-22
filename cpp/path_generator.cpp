#include "path_generator.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

PathGenerator::PathGenerator(){

    random_threshold = 0.5;

}


void PathGenerator::add_T(){
    BranchIns *new_br = new BranchIns;
    new_br->set_directioin(BranchResult::TAKEN);
    branch_ins_list.push_back(new_br);
}

void PathGenerator::add_NT(){
    BranchIns *new_br = new BranchIns;
    new_br->set_directioin(BranchResult::NOT_TAKEN);
    branch_ins_list.push_back(new_br);
}

void PathGenerator::show_path(){
    int length = 0;
    if(branch_ins_list.empty()){
        std::cout<<"[PathGenerator]The path is empty. Please add path.\n";
        exit(0);
    }else{
        length = branch_ins_list.size();
        for(int ibranch=0;ibranch < length;ibranch++){
            if((ibranch==0) | (ibranch%10!=0)){
                view_branch_value(branch_ins_list[ibranch]->get_cur_dir());
            }else{
                std::cout<<"\n";
                view_branch_value(branch_ins_list[ibranch]->get_cur_dir());
            }
        }
        std::cout<<"\n";
    }
}

void PathGenerator::add_for_branch(int num_loop){

    for(int iT = 0; iT < num_loop - 1 ;iT++){
        add_T();
    }
    add_NT();

}


void PathGenerator::add_random(int num_branch){

    // T for > Threshold
    // Gaussion at 50 %
    for(int inum=0;inum<num_branch;inum++){
        srand(time(NULL));
        double ans_rand = double(double(rand())/double(RAND_MAX));
        bool add_Taken = (ans_rand>random_threshold)?1:0;
        if(add_Taken){
            add_T();
        }else{
            add_NT();
        }
    }

}

void PathGenerator::add_Dbranch(std::vector<BranchResult> *path){
    if(path->size()!=0){
        // std::cout<<"the dynamic path size is: "<<path->size()<<std::endl;
        BranchInsDynamic *new_dbr = new BranchInsDynamic;
        new_dbr->set_path(path);
        branch_ins_list.push_back(new_dbr);
    }else{
        std::cout<<"The path is 0."<<std::endl;
    }
}

void PathGenerator::add_default_path(){
    std::vector<BranchResult> local_path = {BranchResult::NOT_TAKEN, 
                                            BranchResult::NOT_TAKEN, 
                                            BranchResult::TAKEN, 
                                            BranchResult::TAKEN};
    add_for_branch(5);
    add_Dbranch(&local_path);
    add_NT();
    add_T();
    add_Dbranch(&local_path);
    add_random(4);
    
}

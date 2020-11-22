#include "path_generator.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

PathGenerator::PathGenerator(){

    random_threshold = 0.5;

}


void PathGenerator::add_T(){
    branch_path.push_back(BranchResult::TAKEN);
}

void PathGenerator::add_NT(){
    branch_path.push_back(BranchResult::NOT_TAKEN);
}

void PathGenerator::show_path(){
    int length = 0;
    if(branch_path.empty()){
        std::cout<<"[PathGenerator]The path is empty. Please add path.\n";
        exit(0);
    }else{
        length = branch_path.size();
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

void PathGenerator::add_for_branch(int num_loop){
    
    for(int iT = 0; iT < num_loop - 1 ;iT++){
        add_T();
    }
    add_NT();

}

void PathGenerator::repeat_path(int times){

    if(times!=0){
        std::vector<BranchResult> path_now;
        path_now.assign(branch_path.begin(), branch_path.end());

        for(int it=0;it<times;it++){
            branch_path.insert(branch_path.end(),path_now.begin(),path_now.end());
        }

    }else{
        std::cout<<"[PathGenerator]Please enter a valid repeat times.\n";
    }

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

void PathGenerator::add_default_path(){
    add_for_branch(5);
    add_T();
    add_T();
    add_NT();
    add_NT();
    add_T();
    add_T();
    add_random(10);
    repeat_path(3);
}

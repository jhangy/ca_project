#ifndef __PATHGENERATOR_HPP__
#define __PATHGENERATOR_HPP__

#include <cstdio>
#include <vector>

#include "definition.hpp"

class PathGenerator{

    // random threshlod default is 0.5, 50% T 50% NT
    double random_threshold;

    // ins branch
    std::vector<BranchIns *> branch_ins_list;

public:

    // constructor  
    PathGenerator();

    // add default path
    void add_default_path();
    void add_default_path_midterm();
    void add_default_path_custom();
    
    // add taken branch to path
    void add_T();
    void add_T_windex(int pc_ind);

    // add not taken branch to path
    void add_NT();
    void add_NT_windex(int pc_ind);

    // add a local dynamic branch
    void add_Dbranch(std::vector<BranchResult> *path);

    // print branch path
    void show_path();

    // add a for loop branch, 
    // Taken for every loop except for the last loop: T, T..... NT.
    void add_for_branch(int num_loop);

    // repeat the path which is stored in the branch_path.
    void repeat_path(int times);

    // add random path
    void add_random(int num_branch);

    // return pointer of branch_path
    std::vector<BranchIns *> *get_path(){return &branch_ins_list;}

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

#endif
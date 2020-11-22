#ifndef __PATHGENERATOR_HPP__
#define __PATHGENERATOR_HPP__

#include <cstdio>
#include <vector>

#include "definition.hpp"

class PathGenerator{

    // random threshlod default is 0.5, 50% T 50% NT
    double random_threshold;

    // path of branch
    std::vector<BranchResult> branch_path;

public:

    // constructor  
    PathGenerator();

    // add default path
    void add_default_path();

    // add taken branch to path
    void add_T();
    
    // add not taken branch to path
    void add_NT();
    
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
    std::vector<BranchResult> *get_path(){return &branch_path;}

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
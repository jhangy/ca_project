#ifndef __DEFINITION_HPP__
#define __DEFINITION_HPP__

#include <cstdio>
#include <iostream>
#include <vector>

enum class BranchResult{
    TAKEN,
    NOT_TAKEN
};

class BranchIns{
    BranchResult directon;
public:
    ~BranchIns(){};
    virtual BranchResult get_cur_dir(){return directon;}
    void set_directioin(BranchResult dir){
        directon = dir;
    }
};

class BranchInsDynamic : public BranchIns{
    int counter = 0;
    std::vector<BranchResult> path;
public: 
    ~BranchInsDynamic();
    BranchResult get_cur_dir(){
        if(counter < path.size()){
            int cur = counter;
            counter++;
            return path[cur];
        }else{
            if(path.size()!=0){
                int cur = 0;
                counter = 1;
                return path[cur];
            }else{
                std::cout<<"[BranchInsDynamic] The dynamic branch is empty.\n";
                exit(0);
            }
        }
    };

    void set_path(std::vector<BranchResult> *b_path){
        path.insert(path.begin(),b_path->begin(), b_path->end());
    };

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

    void show_path(){
        for(int ibr=0;ibr<path.size();ibr++){
            view_branch_value(path[ibr]);
        }
    }

};

#endif /* __DEFINITION_HPP__ */
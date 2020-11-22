# ca_project
1. clone the repository
    > git clone https://github.com/jhangy/ca_project.git

2. build makefile from CMakeList:
    >cmake .

3. make file:
    > make

4. execute:
    > ./main

# Tips
1. It is safe to rexecute the step 2->4 when you finish modifing code.

# CMakeList Modifying

1. If you add new .cpp file, please add the new file path in SET(SRCS ./cpp/__new_file__ ./cpp/path_generator.cpp ./cpp/predictor.cpp ./cpp/simulator.cpp main.cpp).

2. Then, do step 2->4 again.

# Some git usage:

1. branch:  
    > git checkout -b <branch_name>

2. jump to exist branch:
    > git chekcout <target_branch>

3. add modified file:
    > git add <file_path>

4. commit:
    > git commit -m "reason"

5. push to repository:  
  a. do not push the main branch
    > git push origin <current_branch>
  
6. see the branch you have
    > git branch

7. update newest repository information
    > git fetch --all

8. update newest branch to current branch:  
  a. Need to fetch the newest information of repository first(execute the item 7)  
  b. checkout the target branch
    > git pull origin <target_branch>
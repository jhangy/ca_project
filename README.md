# ca_project
1. build makefile from CMakeList:
command > cmake .
2. make file:
command > make
3. execute:
command > ./main

# Tips
1. It is safe to rexecute the step 1->3 when you finish modifing code.

# CMakeList modifying
1. If you add new .cpp file, please add the file path in SET(SRCS ./cpp/__new_file__ ./cpp/path_generator.cpp ./cpp/predictor.cpp ./cpp/simulator.cpp main.cpp).
2. then do step 1->3 again.
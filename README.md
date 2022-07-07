# MST-Instances
Minimum Spanning Tree instances used in the manuscript "An oracle-based framework for robust combinatorial optimization" 

The repository contains the folder "MST_Instances.zip", with 50 randomly generated instances of the Minimum Spanning Tree Problem. 

The instances are generated on complete graphs of five different sizes (20, 30, 40, 50, 60 nodes). 
For each size we randomly generate 10 different nominal cost vectors. 

The scenarios can be generated by using the code "discrete_scenario_generator.cpp"

They are generated by adding to the vector of nominal costs a random unit
vector, multiplied by a scalar factor beta.
In the manuscript, we considered three values for beta (1, 2, 3) and three different numbers of scenarios (10, 100, 1000). 

Viel Spaß e buon divertimento!

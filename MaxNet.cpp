// MaxNet Neural Network 

#include <iostream>
using namespace std;

class MaxNet{
    public:
        double activations[4], epsilon;
        MaxNet(){
            activations[0] = 0.3;
            activations[1] = 0.5;
            activations[2] = 0.7;
            activations[3] = 0.9;
            epsilon = 0.2;
    
        }
};

double SumofElements(MaxNet network){
    double sum = 0; 
    for (int i = 0; i < 4; i++){
        sum = sum + network.activations[i];
    }
    return sum;

};

int CheckActivations(MaxNet network){
    int number = 0;
    for(int i = 0; i < 4; i++){
        if(network.activations[i] == 0.0) number++;
    }
    return number;
}

MaxNet PerformUpdation(MaxNet network, double sumOfElements){
    for(int i = 0; i < 4; i++){
        network.activations[i] = network.activations[i] - (network.epsilon*(sumOfElements - network.activations[i]));
        if(network.activations[i] <= 0){
            network.activations[i] = 0;
        }
    }
    return network;
};

int main(){
    MaxNet network;

    int iteration = 0;
    cout << "Iteration 0"<< endl;
    cout << "Activations are:\na(0) = " + to_string(network.activations[0]) + "\na(1) = " + to_string(network.activations[1]) + "\na(2) = " + to_string(network.activations[2]) + "\na(3) = " + to_string(network.activations[3]);
    cout << endl;
    cout << endl;
    iteration++;

    while(CheckActivations(network) < 3){
        cout << "Iteration " + to_string(iteration) << endl;
        network = PerformUpdation(network, SumofElements(network));
        iteration++;
        cout << "Activations are:\na(0) = " + to_string(network.activations[0]) + "\na(1) = " + to_string(network.activations[1]) + "\na(2) = " + to_string(network.activations[2]) + "\na(3) = " + to_string(network.activations[3]);
        cout << endl;
        cout << endl;
    }
}
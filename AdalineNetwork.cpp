// Adaline Network

#include <iostream>
using namespace std;

class NeuralNetwork{
    public:
        double weights[2];
        double bias;
        double learningRate;
        NeuralNetwork(){
            weights[0] = 0.2;
            weights[1] = 0.2;
            bias = 0.2;
            learningRate = 0.2;
        }
};

NeuralNetwork PerformWeightAndBiasUpdates(NeuralNetwork network, double inputValues[], double targetValue){
    float yin = 0.0;
    for(int i = 0; i < 2; i++){
        yin = yin + network.weights[i] * inputValues[i];
    }
    yin = yin + network.bias;

    for(int i = 0; i < 2; i++){
        network.weights[i] = network.weights[i] + network.learningRate*(targetValue - yin)*inputValues[i];
    }
    network.bias = network.bias + network.learningRate*(targetValue - yin); 

    cout << "MSE Error is " + to_string((targetValue - yin)*(targetValue - yin)) << endl;
    return network;
};

int main(){

    double inputValues[4][2] = {{1.0, 1.0}, {1.0, -1.0}, {-1.0, 1.0}, {-1.0, -1.0}};
    double targetValues[4] = {-1.0, 1.0, -1.0, -1.0};

    // Display input values truth table
    cout << "Truth table is" << endl;
    cout << "x1 \t x2 \t     t" << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cout << to_string(inputValues[i][j]) + " ";
        }
        cout << to_string(targetValues[i]);
        cout << endl;
    }
    cout << endl;

    NeuralNetwork network;

    // Train Network for 20 Epochs.
    for(int i = 0; i < 20; i++){
        cout << "Epoch " + to_string(i+1) + " : " << endl;
        for(int j = 0; j < 4; j++){
            network = PerformWeightAndBiasUpdates(network, inputValues[j], targetValues[j]);
        }
        cout << endl;   
    }
    
    cout << endl;
    cout << "Weights after training are" << endl;
    cout << to_string(network.weights[0]) + " " + to_string(network.weights[1]) << endl;
    cout << "Bias after training is" << endl;
    cout << to_string(network.bias);
}
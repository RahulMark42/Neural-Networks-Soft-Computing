#include <iostream>
#include <math.h>
using namespace std;

class NeuralNetwork{
    public:
        double weights_input_hidden[2][2];
        double bias_input_hidden[2];
        double weights_hidden_output[2];
        double bias_hidden_output;
        double learning_rate;
        NeuralNetwork(){
            weights_input_hidden[0][0] = 0.05;
            weights_input_hidden[0][1] = 0.1;
            weights_input_hidden[1][0] = 0.2;
            weights_input_hidden[1][1] = 0.2;
            bias_input_hidden[0] = 0.3;
            bias_input_hidden[1] = 0.15;
            weights_hidden_output[0] = 0.5;
            weights_hidden_output[1] = 0.5;
            bias_hidden_output = 0.5;
            learning_rate = 0.5;
        }
};

double BipolarActivationFunction(double value){
    if(value >= 0) return 1.0;
    else return -1.0;
};

int main(){

    //XOR Function
    int inputs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int targets[4] = {-1, 1, 1, -1};

    NeuralNetwork network;

    for(int i = 0; i < 4; i++){
        double zin1 = network.weights_input_hidden[0][0]*inputs[i][0] + network.weights_input_hidden[1][0]*inputs[i][1] + network.bias_input_hidden[0]; 
        double zin2 = network.weights_input_hidden[0][1]*inputs[i][0] + network.weights_input_hidden[1][1]*inputs[i][1] + network.bias_input_hidden[1];
        double z1 = BipolarActivationFunction(zin1);
        double z2 = BipolarActivationFunction(zin2);
        double y = BipolarActivationFunction(z1*network.weights_hidden_output[0] + z2*network.weights_hidden_output[1] + network.bias_hidden_output);


        if(targets[i] != y && targets[i] == -1){
            if(zin1 > 0.0){
                network.weights_input_hidden[0][0] = network.weights_input_hidden[0][0] + network.learning_rate*(targets[i] - zin1)*inputs[i][0]; 
                network.weights_input_hidden[1][0] = network.weights_input_hidden[1][0] + network.learning_rate*(targets[i] - zin1)*inputs[i][1]; 
                network.bias_input_hidden[0] = network.bias_input_hidden[0] + network.learning_rate*(targets[i] - zin1);
            }
            if(zin2 > 0.0){
                network.weights_input_hidden[0][1] = network.weights_input_hidden[0][1] + network.learning_rate*(targets[i] - zin2)*inputs[i][0];
                network.weights_input_hidden[1][1] = network.weights_input_hidden[1][1] + network.learning_rate*(targets[i] - zin2)*inputs[i][1];
                network.bias_input_hidden[1] = network.bias_input_hidden[1] + network.learning_rate*(targets[i] - zin2);
            }
        }

        if(targets[i] != y && targets[i] == 1){
            if(abs(zin1) < abs(zin2) || abs(zin1) == abs(zin2)){
                network.weights_input_hidden[0][0] = network.weights_input_hidden[0][0] + network.learning_rate*(targets[i] - zin1)*inputs[i][0]; 
                network.weights_input_hidden[1][0] = network.weights_input_hidden[1][0] + network.learning_rate*(targets[i] - zin1)*inputs[i][1];
                network.bias_input_hidden[0] = network.bias_input_hidden[0] + network.learning_rate*(targets[i] - zin1);
            }
            if(abs(zin1) > abs(zin2) || abs(zin1) == abs(zin2)){
                network.weights_input_hidden[0][1] = network.weights_input_hidden[0][1] + network.learning_rate*(targets[i] - zin2)*inputs[i][0];
                network.weights_input_hidden[1][1] = network.weights_input_hidden[1][1] + network.learning_rate*(targets[i] - zin2)*inputs[i][1];
                network.bias_input_hidden[1] = network.bias_input_hidden[1] + network.learning_rate*(targets[i] - zin2);
            }
        }

        cout << "Weights and biases after updating for " + to_string(i +  1) + " input are:" << endl;
        cout << "w11 = " + to_string(network.weights_input_hidden[0][0]) << endl;
        cout << "w12 = " + to_string(network.weights_input_hidden[0][1]) << endl;
        cout << "w21 = " + to_string(network.weights_input_hidden[1][0]) << endl;
        cout << "w22 = " + to_string(network.weights_input_hidden[1][1]) << endl;
        cout << "b1 = " + to_string(network.bias_input_hidden[0]) << endl;
        cout << "b2 = " + to_string(network.bias_input_hidden[1]) << endl;
        cout << endl;
    }
}
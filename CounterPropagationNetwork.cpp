#include <iostream>
using namespace std;

class Network{
    public:
        double v[4][2];
        double w[2][2];
        double alpha;
        double beta;

        Network(){
            v[0][0] = 0.6;
            v[0][1] = 0.4;
            v[1][0] = 0.6;
            v[1][1] = 0.4;
            v[2][0] = 0.4;
            v[2][1] = 0.6;
            v[3][0] = 0.4;
            v[3][1] = 0.6;

            w[0][0] = 0.5;
            w[0][1] = 0.5;
            w[1][0] = 0.5;
            w[1][1] = 0.5;

            alpha = 0.2;
            beta = 0.2;
        };

};

double CalculateEuclidanDistance(double inputsX[4], double outputsY[2], Network network, int cluster){
    double distance = 0;
    for(int i = 0; i <  4; i++){
        distance = distance + (inputsX[i] - network.v[i][cluster - 1])*(inputsX[i] - network.v[i][cluster - 1]);

    }
    for(int j = 0; j < 2; j++){
        distance = distance + (outputsY[j] - network.w[j][cluster - 1])*(outputsY[j] - network.w[j][cluster - 1]);
    }
    return distance;

};

int main(){
    double inputsX[4] = {1.0, 0.0, 0.0, 0.0};
    double outputsY[2] = {1, 0};
    Network network;
    

    // Calculating only for one Iteration, comparing euclidan distances to 2 clusters
    double d1 = CalculateEuclidanDistance(inputsX, outputsY, network, 1);
    double d2 = CalculateEuclidanDistance(inputsX, outputsY, network, 2);

    if(d1 <= d2){
        for(int i = 0; i <  4; i++){
            network.v[i][0] = network.v[i][0] + network.alpha*(inputsX[i] - network.v[i][0]);
        }   
        for(int j = 0; j < 2; j++){
            network.w[j][0] = network.w[j][0] + network.beta*(outputsY[j] - network.w[j][0]);
        }
    }
    if(d1 > d2){
        for(int i = 0; i <  4; i++){
            network.v[i][1] = network.v[i][1] + network.alpha*(inputsX[i] - network.v[i][1]);
        }   
        for(int j = 0; j < 2; j++){
            network.w[j][1] = network.w[j][1] + network.beta*(outputsY[j] - network.w[j][1]);
        }

    }

    cout << "Weights after updation of V are: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cout << to_string(network.v[i][j]) + " ";
        }
        cout << endl;
    }
    cout <<  endl;
    cout << "Weights after updation of W are: " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << to_string(network.w[i][j]) + " ";
        }
        cout << endl;
    }





}
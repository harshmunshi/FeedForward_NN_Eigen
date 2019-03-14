#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

VectorXd Sigmoid(VectorXd& x){

	return 1.0 / (1.0 + (-x).array().exp());
}

VectorXd FeedForward(std::vector<MatrixXd> const& weights, VectorXd const& input){

	VectorXd state;
	VectorXd output;

	state = input;
	for (auto i = 0; i != weights.size(); ++i)
	{
		state = weights[i].transpose()*state;
		std::cout << "State "<< i << ": \n" << state << endl;
		if (i != weights.size()) {
			state = Sigmoid(state);
		}
		output = state;
		

	}
	return output;

}

// For forward propogation (without any training) we need number of hidden layers, number of neurons
// in each layer and number of outputs. we can then apply wTx + b which will be a vector and then apply
// sigmoid function to the vector.


int main(){

	int depth;
	int num_neurons;
	std::vector<int> v;
	std::vector<MatrixXd> weights;
	VectorXd input;
	VectorXd output;

	// define vectors for input and output

	cout << "Enter the depth of the network: ";
	cin >> depth;

	for (int i = 0; i < depth; ++i)
	{
		// for each layer input the number of neurons
		cout << "Layer " << i << " neurons: ";
		cin >> num_neurons;
		v.push_back(num_neurons);
	}

	for (auto i = 0; i != v.size()-1; ++i)
	{
		size_t rows = v[i];
		size_t cols = v[i+1];
		std::cout << "Matrix " << i+1 << " has shape " << rows << " "<< cols <<endl;
		weights.push_back(MatrixXd::Random(rows, cols));
		std::cout << "The recent weight was \n" << weights[i] << endl;
		if (i == 0){
			input = VectorXd::Random(v[i]);
			std::cout << "The randm Vector is \n" << input << endl;
		}
	}


	output = FeedForward(weights, input);

	std::cout << endl;
	for (auto i=0; i != output.size(); ++i){
		std::cout << output[i] << ' ';
	}
	std::cout << endl;
	return 0;

}
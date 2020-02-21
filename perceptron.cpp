#include <vector>
#include <cmath>

using namespace std;





class perceptron{
	private:
		vector<float> weights;
		float activationFunction(float input);
		float derivitiveActivationFunction(float input);

		// Helper Functions
		// Vector Dot Product
		float dotProduct(vector<float> a, vector<float> b){
			auto aSize = a.size();
			if(aSize != b.size()){
				throw "Incompatible vectors. Both vectors must be the same size.";
			}
			float c;
			for(unsigned i: {(long unsigned)0, aSize}){
				c+=(a[i]*b[i]);
			}
			return c;
		}

		// Sigmoid activation functions.
		auto sigmoid = [](float input){ return 1.0/(1.0+exp(-input));};
		auto sigmoidDerivitive = [](float input){ return sigmoid(input)*(1-sigmoid(input));};

		// Back Propigation (ToDo)

	public:
		perceptron(){
			// Randomise the weights
			// select the activation functions(default to Sigmoid)
			// 
		}
		float queryPerceptron(vector<float> inputs){
			if(inputs.size() != (weights.size()-1)){
				throw "number of inputs doesn't match number of weights(inputs=weights+bias)";
			}
			inputs.push_back(1.0);
			return activationFunction(dotProduct(weights, inputs));
		}
};

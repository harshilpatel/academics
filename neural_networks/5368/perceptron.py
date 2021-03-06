# Patel, Harshilkumar
# 1001-717-222
# 2019-09-23
# Assignment-01-01

import numpy as np
import itertools

import logging

logger = logging.getLogger("Perceptron")
logger.setLevel(logging.DEBUG)

formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
console_handler = logging.StreamHandler()
console_handler.setFormatter(formatter)

logger.addHandler(console_handler)

class Perceptron(object):
    def __init__(self, input_dimensions=2,number_of_classes=4,seed=None):
        """
        Initialize Perceptron model
        :param input_dimensions: The number of features of the input data, for example (height, weight) would be two features.
        :param number_of_classes: The number of classes.
        :param seed: Random number generator seed.
        """
        if seed != None:
            np.random.seed(seed)
        self.input_dimensions = input_dimensions
        self.number_of_classes=number_of_classes
        self._initialize_weights()

    def _initialize_weights(self):
        """
        Initialize the weights, initalize using random numbers.
        Note that number of neurons in the model is equal to the number of classes
        """
        self.weights = np.random.randn(self.number_of_classes, self.input_dimensions + 1)
        # raise Warning("You must implement _initialize_weights! This function should initialize (or re-initialize) your model weights. Bias should be included in the weights")

    def initialize_all_weights_to_zeros(self):
        """
        Initialize the weights, initalize using random numbers.
        """
        logger.debug("initialize weights to zero")
        self.weights = np.zeros((self.number_of_classes, self.input_dimensions + 1))
        # raise Warning("You must implement this function! This function should initialize (or re-initialize) your model weights to zeros. Bias should be included in the weights")

    def predict(self, X):
        """
        Make a prediction on an array of inputs
        :param X: Array of input [input_dimensions,n_samples]. Note that the input X does not include a row of ones
        as the first row.
        :return: Array of model outputs [number_of_classes ,n_samples]
        """

        bias_input = np.ones((1,X.shape[1]))

        X = np.vstack((bias_input, X))
        logger.info("input for prediction: \n%s\n", X)
        logger.info("weights for prediction: \n%s\n", self.weights)

        A = np.zeros((self.weights.shape[0], X.shape[1]))

        for i in range(X.shape[1]):
            # loops over all iWp pairs
            logger.debug("predicted output: \n%s\n", A)
            A[:,i] = np.dot(self.weights, X[:,i])
            logger.debug("predicted output: \n%s\n", A)
            for j in range(A.shape[0]):
                A[j,i] = 1 if A[j,i] >= 0 else 0

        A = A.astype(int)
        logger.info("predicted output: \n%s\n", A)
        return A
        # raise Warning("You must implement predict. This function should make a prediction on a matrix of inputs")


    def print_weights(self):
        """
        This function prints the weight matrix (Bias is included in the weight matrix).
        """

        print("****** Model weights ******\n",model.weights)
        # raise Warning("You must implement print_weights")

    def train(self, X, Y, num_epochs=10, alpha=0.001):
        """
        Given a batch of data, and the necessary hyperparameters,
        this function adjusts the self.weights using Perceptron learning rule.
        Training should be repeted num_epochs time.
        :param X: Array of input [input_dimensions,n_samples]
        :param y: Array of desired (target) outputs [number_of_classes ,n_samples]
        :param num_epochs: Number of times training should be repeated over all input data
        :param alpha: Learning rate
        :return: None
        """

        logger.info(" --- weights before train:  \n %s \n", self.weights)

        for i in range(num_epochs):
            # loops for epochs requested
            for j in range(X.shape[1]):
                # loops over the test inputs
                y_pred = self.predict(X)

                y_real = Y[:,j:j+1]
                y_predicted = y_pred[:,j:j+1]

                if not np.array_equal(y_real, y_predicted):
                    # runs if theres is a mismatch
                    diff = np.subtract(y_real, y_predicted)
                    
                    p = X[:,j:j+1]
                    weights_dx = np.dot(diff, p.T)

                    self.weights[:,1:] += ( alpha * weights_dx)
                    self.weights[:,0:1] += (alpha * diff)

                    logger.debug("e: \n%s\n", diff.shape)
                    logger.debug("p: \n%s\n", p.shape)
                    logger.debug("t: \n%s\n", y_real)
                    logger.debug("a: \n%s\n", y_predicted)
                    logger.debug("adjusted weights: \n %s \n", self.weights[:,:-1])
                    logger.debug("adjusted bias: \n %s \n", self.weights[:,-1])
                    
            
        logger.info(" --- weights after train: \n %s \n", self.weights)
        # raise Warning("You must implement train")

    def calculate_percent_error(self,X, Y):
        """
        Given a batch of data this function calculates percent error.
        For each input sample, if the output is not hte same as the desired output, Y,
        then it is considered one error. Percent error is number_of_errors/ number_of_samples.
        :param X: Array of input [input_dimensions,n_samples]
        :param y: Array of desired (target) outputs [number_of_classes ,n_samples]
        :return percent_error
        """

        errors = 0
        
        y_pred = self.predict(X)
        for j in range(Y.shape[1]):
            if not np.array_equal(Y[:,j:j+1], y_pred[:,j:j+1]):
                errors += 1
        
        p_errors = (errors/X.shape[1])

        logger.debug("errors: %s, p_errors: %s", errors, p_errors)
        return p_errors

        # raise Warning("You must implement calculate_percent_error")

if __name__ == "__main__":
    """
    This main program is a sample of how to run your program.
    You may modify this main program as you desire.
    """

    input_dimensions = 2
    number_of_classes = 2

    model = Perceptron(input_dimensions=input_dimensions, number_of_classes=number_of_classes, seed=1)
    X_train = np.array([[-1.43815556, 0.10089809, -1.25432937, 1.48410426],
                        [-1.81784194, 0.42935033, -1.2806198, 0.06527391]])
    print(model.predict(X_train))
    Y_train = np.array([[1, 0, 0, 1], [0, 1, 1, 0]])
    model.initialize_all_weights_to_zeros()
    print("****** Model weights ******\n",model.weights)
    print("****** Input samples ******\n",X_train)
    print("****** Desired Output ******\n",Y_train)
    percent_error=[]
    for k in range (20):
        model.train(X_train, Y_train, num_epochs=1, alpha=0.0001)
        percent_error.append(model.calculate_percent_error(X_train,Y_train))
    print("******  Percent Error ******\n",percent_error)
    print("****** Model weights ******\n",model.weights)
import numpy as np
import pandas as pd

class BayesianNetwork:
    def __init__(self, n_labels=10, n_pixels=784, n_values=2) -> None:
        '''
        n_labels: number of labels, 10 for digit recognition
        n_pixels: number of pixels, 256 for 16x16 image
        n_values: number of values for each pixel, 0 for black, 1 for white
        '''
        self.n_labels = n_labels
        self.n_pixels = n_pixels
        self.n_values = n_values
        # prior probability
        self.labels_prior = np.zeros(n_labels)
        self.pixels_prior = np.zeros((n_pixels, n_values))
        # conditional probability
        self.pixels_cond_label = np.zeros((n_pixels, n_values, n_labels))

    # fit the model with training data
    def fit(self, pixels, labels):
        '''
        pixels: (n_samples, n_pixels, )
        labels: (n_samples, )
        '''
        n_samples = len(labels)
        # TODO: calculate prior probability and conditional probability

        # Calculate prior probability
        for label in labels:
            self.labels_prior[label] += 1
        
        # Calculate conditional probability
        for i in range(n_samples):
            label = labels[i]
            for pixel in range(self.n_pixels):
                pixel_value = pixels[i, pixel]
                self.pixels_prior[pixel, pixel_value] += 1
                self.pixels_cond_label[pixel, pixel_value, label] += 1
                
        # Normalize conditional probability
        for pixel in range(self.n_pixels):
            for value in range(self.n_values):
                self.pixels_prior[pixel, value] /= n_samples
                for label in range(self.n_labels):
                    self.pixels_cond_label[pixel, value, label] /= self.labels_prior[label]
        
        self.labels_prior /= n_samples

    # predict the labels for new data
    def predict(self, pixels):
        '''
        pixels: (n_samples, n_pixels, )
        return labels: (n_samples, )
        '''
        n_samples = len(pixels)
        labels = np.zeros(n_samples)
        # TODO: predict for new data
        
        for i in range(n_samples):
            pixel_values = pixels[i]
            label_scores = np.zeros(self.n_labels)
            
            for label in range(self.n_labels):
                label_scores[label] = self.labels_prior[label]
                for pixel in range(self.n_pixels):
                    pixel_value = pixel_values[pixel]
                    label_scores[label] *= self.pixels_cond_label[pixel, pixel_value, label]
                    
            labels[i] = np.argmax(label_scores)
        
        return labels

    # calculate the score (accuracy) of the model
    def score(self, pixels, labels):
        '''
        pixels: (n_samples, n_pixels, )
        labels: (n_samples, )
        '''
        n_samples = len(labels)
        labels_pred = self.predict(pixels)
        return np.sum(labels_pred == labels) / n_samples
    
if __name__ == '__main__':
    # load data
    train_data = np.loadtxt('../data/train.csv', delimiter=',', dtype=np.uint8)
    test_data = np.loadtxt('../data/test.csv', delimiter=',', dtype=np.uint8)
    pixels_train, labels_train = train_data[:, :-1], train_data[:, -1]
    pixels_test, labels_test = test_data[:, :-1], test_data[:, -1]
    # build bayesian network
    bn = BayesianNetwork()
    bn.fit(pixels_train, labels_train)
    print('test score: %f' % bn.score(pixels_test, labels_test))
## Lab4 Python Image style conversion

The Tensorflow hub contains various pre-trained models. Any style conversion can be done through Tensorflow hub.

This artistic style migration model consists of two sub-models:
Style prediction model: a neural network based on MobilenetV2 that converts the input style image into a 100-dimensional style bottleneck vector.Style transformation model: a neural network that applies the style bottleneck vector to the content image and creates a stylized image.

First, I import TF-related dependencies, download content and style images, and pre-trained Tensorflow lite models. 

Pre-processing the input.

The content and style images must be RGB images with float32 numbers with pixel values between [0..1].

The size of the style image must be (1, 256, 256, 3). We crop the image centrally and resize it.

The content image must be (1, 384, 384, 3). We crop the image centrally and resize it. 

Then I visualize the image for input and run style migration using Tensorflow lite to perform style prediction, then style transformation, and finally incorporate the style of the content image into the programmatic output so that the output looks more like the content image.


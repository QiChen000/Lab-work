## Lab3 Python Image dataset conversion

I downloaded the dataset about masks from Kaggle and imported it into python notebook examples. I found that some instances wouldn't load because the images in my dataset were of different sizes. I batch process my images to the same size and center the focus of the images through the website Birme. I uploaded the resized dataset again and changed the length of the file.

I did vertical flip, horizontal flip, brightness enhancement, color mapping with three channels, horizontal stitching, and shuffling the order randomly.

The vertical flip is done by array slicing, equivalent to moving the last row of the image to the first row and the penultimate row to the second row... For row indicators, slicing is done using ::-1, a negative step means starting from the last element and looking for the next point to the left. For column indicators and RGB channels, using only: means that the size does not change.



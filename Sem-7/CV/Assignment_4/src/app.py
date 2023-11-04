import cv2
import numpy as np
from flask import Flask, request, jsonify, send_file
import matplotlib.pyplot as plt
from io import BytesIO
import os

app = Flask(__name__)

def determine_parameters(input_image):
    # Convert the input image to grayscale
    grayscale_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)

    # Apply adaptive thresholding to determine the optimal threshold value
    threshold_value,tup = cv2.threshold(grayscale_image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Determine the optimal Gaussian blur kernel size and standard deviation based on the image size
    height, width = grayscale_image.shape
    kernel_size = (max(3, int(width / 10) | 1), max(3, int(height / 10) | 1))
    sigma = (kernel_size[1] * 0.5 - 1) * 0.2

    return threshold_value, kernel_size, sigma

def segment_and_blur_background(input_image):
    # Determine parameters based on the input image
    threshold_value, kernel_size, sigma = determine_parameters(input_image)

    # Convert the input image to grayscale
    grayscale_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)

    # Apply binary thresholding using the determined threshold value
    _, binary_mask = cv2.threshold(grayscale_image, threshold_value, 255, cv2.THRESH_BINARY)

    # Invert the binary mask
    inverted_mask = cv2.bitwise_not(binary_mask)

    # Apply Gaussian blur to the background using the determined kernel size and sigma
    blurred_background = cv2.GaussianBlur(input_image, kernel_size, sigma)

    # Combine the segmented subject and blurred background
    input_image[inverted_mask == 255] = blurred_background[inverted_mask == 255]

    return input_image

@app.route('/segment_and_blur', methods=['POST'])
def segment_and_blur():
    if 'image' not in request.files:
        return jsonify({'error': 'No image provided'})

    image = request.files['image'].read()
    image = cv2.imdecode(np.frombuffer(image, np.uint8), cv2.IMREAD_COLOR)

    blurred_image = segment_and_blur_background(image)

    # Save the blurred image to a temporary file
    output_filename = 'blurred_output.jpg'
    cv2.imwrite(output_filename, blurred_image)

    return send_file(output_filename, mimetype='image/jpeg')

if __name__ == '__main__':
    app.run(debug=True)

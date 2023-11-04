import cv2
import numpy as np
from flask import Flask, jsonify, request, send_file
from io import BytesIO

app = Flask(__name__)

# Initialize the buffer to store processed image data
buffered = None


def determine_parameters(input_image):
    # Convert the input image to grayscale
    grayscale_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)

    # Apply adaptive thresholding to determine the optimal threshold value
    threshold_value, _ = cv2.threshold(
        grayscale_image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

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
    _, binary_mask = cv2.threshold(
        grayscale_image, threshold_value, 255, cv2.THRESH_BINARY)

    # Invert the binary mask
    inverted_mask = cv2.bitwise_not(binary_mask)

    # Apply Gaussian blur to the background using the determined kernel size and sigma
    blurred_background = cv2.GaussianBlur(input_image, kernel_size, sigma)

    # Combine the segmented subject and blurred background
    input_image[inverted_mask ==
                255] = blurred_background[inverted_mask == 255]

    return input_image


@app.route('/segment_and_blur', methods=['POST'])
def segment_and_blur():
    if 'image' not in request.files:
        return jsonify({'error': 'No image provided'})

    global buffered

    image = request.files['image'].read()
    image = cv2.imdecode(np.frombuffer(image, np.uint8), cv2.IMREAD_COLOR)

    blurred_image = segment_and_blur_background(image)

    # Convert the blurred image to a byte buffer
    buffered = BytesIO()
    image_data = cv2.imencode('.jpg', blurred_image)[1].tostring()
    buffered.write(image_data)
    buffered.seek(0)

    return jsonify(
        {
            "message": "Image Processed",
        }
    )

@app.route('/getprocessed', methods=['GET'])
def get_processed():
    global buffered
    if buffered is not None:
        return send_file(buffered, mimetype='image/jpeg')
    else:
        return "No processed image available"
    
@app.route('/', methods=['GET'])
def hi():
    return jsonify({'message': 'Hello From CV!'})

if __name__ == '__main__':
    app.run(debug=True)

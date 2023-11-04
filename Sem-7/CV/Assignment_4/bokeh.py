import gradio as gr
import cv2



def determine_parameters(input_image):
    # Convert the input image to grayscale
    grayscale_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)

    # Apply adaptive thresholding to determine the optimal threshold value
    threshold_value, tup = cv2.threshold(grayscale_image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Determine the optimal Gaussian blur kernel size and standard deviation based on the image size
    height, width = grayscale_image.shape
    # Ensure kernel size is odd and at least 3
    kernel_size = (max(3, int(width / 10) | 1), max(3, int(height / 10) | 1))
    sigma = (kernel_size[1]*0.5 - 1)*0.2

    return threshold_value, kernel_size, sigma

def apply_bokeh_effect(input_image):
    # Check if the input image is loaded correctly
    if input_image is None:
        print("Error: Check if the input image path is correct")
        return

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

demo = gr.Interface(apply_bokeh_effect, gr.Image(), "image", css="body {background-color: #f2f2f2;}")
demo.launch()

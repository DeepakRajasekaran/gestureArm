# gestureArm
Control the InMoov Robotic Arm using hand gestures captured through a webcam. This project utilizes computer vision techniques to track hand movements and translate them into control signals for the robotic arm.

## Description

This project enables users to control an InMoov robotic arm using their hand gestures. It leverages the OpenCV library for hand tracking and detection, allowing real-time recognition of hand movements. By mapping specific hand gestures to corresponding robotic arm actions, users can control the arm's fingers and perform various predefined actions.

## Installation

To install and set up the project on your local machine, follow these steps:

1. Install [Python 3.8.10](https://www.python.org/downloads/release/python-3810/) on your system.
2. Clone this repository to your local machine.
3. Navigate to the project directory.
4. Install the required dependencies by running: `pip install mediapipe`.

## Usage

To use the InMoov Robotic Arm Control, follow these guidelines:

1. Connect the InMoov robotic arm to your system and ensure it is properly powered.
2. Run the `hand_tracking.py` script using the command: `python hand_tracking.py`.
3. A window will open displaying the webcam feed with hand tracking overlays.
4. Perform hand gestures in front of the webcam to control the robotic arm.
5. See the console output for information about the recognized gestures and corresponding arm actions.

## License

This project is licensed under the [MIT License](LICENSE-MIT) & [GNU v3.0](LICENSE-GNU).

You may choose to use the project under either the terms of the MIT License or the GPL. Please refer to the respective license files for more details.

## Support

If you encounter any issues or have questions, feel free to create an issue in the [issue tracker](https://github.com/DeepakRajasekaran/gestureArm/issues/new/choose).

## Acknowledgements

This project makes use of the following libraries and resources:

- [OpenCV](https://opencv.org/) - Open Source Computer Vision Library.
- [cvzone](https://github.com/cvzone/cvzone) - A Python library for computer vision applications.
- [Mediapipe](https://mediapipe.dev/) - A cross-platform framework for building multimodal applied machine learning pipelines.
- [InMoov](http://inmoov.fr/) - Open source 3D-printed life-size robot.


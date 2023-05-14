
# Project Gesture  Controlled Arm
# Things used - Arduino, Python, OpenCV, Inmoov Arm
# Author: Deepak Rajasekaran. S
# Assisted by ChatGPT

# Mission - To control the Arm using Laptop WebCam

# State - Not tested yet

# ----------------------------------------------------------------
# Code for Hand tracking and sending the data to arduino

import cv2
import time
import serial
from cvzone.HandTrackingModule import HandDetector

# Open serial port to communicate with Arduino==v 1 ser = serial.Serial('COM7', 9600)  # Change COM port to match your Arduino

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=10)

while True:
    # Capture frame-by-frame
    success, img = cap.read()

    # Detect hand and get landmarks
    hands, img = detector.findHands(img)
    if hands:
        hand = hands[0]
        fingers = detector.fingersUp(hand)
        finger_count = ''.join(str(i) for i in fingers)
        finger_count = '#'+finger_count
        print(finger_count)

        # Send data to Arduino
        ser.write(finger_count.encode())

    # Display the resulting image
    cv2.imshow('Hand Tracking', img)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the capture and close serial port
cap.release()
cv2.destroyAllWindows()
ser.close()



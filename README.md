# RoboticArm_RealTime_remoteTooling
A simple project to create a robotic arm that can be controlled remotely via a webapp. 

# Tech stack
Front end: Native JavaScript.
Backend: NodeJS
Robotics arm onboarc computing system: Raspberry pi and Ardino.

# How it works?
Input about the different degrees at which the arm has to be adjusted can be given to the fronend webapp. The inputs
are handled by the backend nodejs server, which connects to the serverless function created using PubNub's easy serverless function as service 
implementation which is programmed to transmit the inpupt in real-time from the frontend to the on-board compute node on the robotic arm which is the raspberry pi.

An application developed in python is used inside Raspberry pi to act as a listener. This python application waits for any input from the backend to change the angles on the robotics arm. The input from the Rapsberry pi is send to an arduino to control the motors on the robotic arm.

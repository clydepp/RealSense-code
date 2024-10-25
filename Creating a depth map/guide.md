Creation of a depth map using the RealSense D435 requires multiple steps

## Prerequisites
- Must have C++ and Python installed
- Must run the system on Ubuntu 22 (version to be confirmed)
- Must have OpenCV and CMake
- Must have Intel RealSense SDK 2 installed for camera streaming

## Implementation
The D435 is a stereo-based depth camera/sensor, meaning that the voxel locations within the generated 3D maps are constructed by multiple images with a known, preset offset. The depth camera has an inbuilt stereo matching algorithm (we will not change this), and has parameters which affect the sensitivity and confidence probabilities of calculated distances. The 3D map created by the camera is constantly updated, generating approximate depth values in real time. 

1. Initialise the depth camera - obtain RGB colour camera and depth map streams
2. Test and calibrate parameters of the depth camera - use online resources and proven value sets
3. Downsample the depth map - reduces run time latency, this will require calculation and use of map-area confidence algorithms
4. Return the two streams to i. the controller and ii. the computer system for post-processing
5. Implement multithreading for points 2-4?
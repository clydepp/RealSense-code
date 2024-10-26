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

## Considerations
### Downsampling
For faster output to the controller, the colour video stream can be (and should be) downsampled. This is so that the frame-by-frame post processing is much faster for object detection. This differs in the depth camera sense. A captured frame from a depth camera consists of a 3D plane``[x, y, z]``. Within the 2D plane``[x, y]``, this is fine to downscale - provided that the main image is preserved - and markings do not drastically change. However, it is prudent that the z-axis is not scaled - this will affect and invalidate the depth measurements themselves. Doing this will mean that the distances calculated will exhibit incorrect behaviour for most values ``distance*(new_resolution/original_resolution)``.

### Post-processing
#### What do we want to achieve?
- A system that prevents the vehicle from collisions, this can be done by reversing or maintaining positions
- Use of an interrupt algorithm - requiring less resources (compared to using a listening loop)
- Display of the colour camera display - with warnings and data on minimal distance to vehicle
- A sensor system that is **FAST (and accurate)**

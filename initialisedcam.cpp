// consult https://docs.ros.org/en/humble/p/librealsense2/genindex.html for rs2 commands

#include <librealsense2/rs.hpp>
#include <iostream>

int main(int argc, char* argv[]) try
{
    // pipeline initialised to configure the camera with best settings
    // footage from camera is captured by the pipeline
    rs2::pipeline p;

    p.start();

    bool nocollision = true;
    while (nocollision){
        rs2::frameset frames = p.wait_for_frames();

        // capture frame 
        rs2::depth_frame cframe = frames.get_depth_frame();
        
        // set the width and height of the frame
        auto width = cframe.get_width();
        auto height = cframe.get_height();

        float dist_to_center = cframe.get_distance(width/2, height/2);

        if (dist_to_center < 2){
            std::cout << "Case of object too close" << std::endl;
            // insert code for appropriate movement
            // this should be a function call
        }
        else {
            std::cout << "The camera is roughly " << dist_to_center << " metres away\n";
        }
    }

    return 0;
}

catch (const rs2::error & e) {
    std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
    return EXIT_FAILURE;
}
catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}

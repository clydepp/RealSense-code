import cv2
import numpy as np

# this is to be converted into c++

def downsample()
# color = o3d.io.read_image(color_file)
# tmp_color_mat = np.asarray(color) 

depth = o3d.io.read_image(depth_file)   
tmp_depth_mat = np.asarray(depth)    
width = int(tmp_color_mat.shape[1] / 2)
height = int(tmp_color_mat.shape[0] / 2)
dim = (width, height)
# tmp_color_mat = cv2.resize(tmp_color_mat, dim, interpolation = cv2.INTER_NEAREST)
tmp_depth_mat = cv2.resize(tmp_depth_mat, dim, interpolation = cv2.INTER_NEAREST)
# color = o3d.geometry.Image(tmp_color_mat.astype(np.uint8))
depth = o3d.geometry.Image(tmp_depth_mat.astype(np.uint16))
rm *.tga

./a5 -input scene3_01_cube_orthographic.txt -size 200 200 -output output3_01.tga 
./a5 -input scene3_02_cube_perspective.txt -size 200 200 -output output3_02.tga 
./a5 -input scene3_03_bunny_mesh_200.txt -size 200 200 -output output3_03.tga 
./a5 -input scene3_04_bunny_mesh_1k.txt -size 200 200 -output output3_04.tga 
./a5 -input scene3_05_axes_cube.txt -size 200 200 -output output3_05.tga 
./a5 -input scene3_06_crazy_transforms.txt -size 200 200 -output output3_06.tga 
./a5 -input scene3_07_plane.txt -size 200 200 -output output3_07.tga
./a5 -input scene3_08_sphere.txt -size 200 200 -output output3_08.tga  
./a5 -input scene3_09_exponent_variations.txt -size 300 300 -output output3_09.tga 
./a5 -input scene3_10_exponent_variations_back.txt -size 300 300 -output output3_10.tga 
./a5 -input scene3_11_weird_lighting_diffuse.txt -size 200 200 -output output3_11.tga 
./a5 -input scene3_12_weird_lighting_specular.txt -size 200 200 -output output3_12.tga

./a5 -input scene4_01_sphere_shadow.txt -size 200 200 -output output4_01.tga -shadows 
./a5 -input scene4_02_colored_shadows.txt -size 200 200 -output output4_02.tga -shadows
./a5 -input scene4_03_mirrored_floor.txt -size 200 200 -output output4_03.tga -shadows -bounces 1 -weight 0.01 

./a5 -input scene4_04_reflective_sphere.txt -size 200 200 -output output4_04a.tga -shadows -bounces 0 -weight 0.01
./a5 -input scene4_04_reflective_sphere.txt -size 200 200 -output output4_04b.tga -shadows -bounces 1 -weight 0.01
./a5 -input scene4_04_reflective_sphere.txt -size 200 200 -output output4_04c.tga -shadows -bounces 2 -weight 0.01
./a5 -input scene4_04_reflective_sphere.txt -size 200 200 -output output4_04d.tga -shadows -bounces 3 -weight 0.01

./a5 -input scene4_10_point_light_distance.txt -size 200 200 -output output4_10.tga -shadows 

./a5 -input scene4_11_point_light_circle.txt -size 200 200 -output output4_11.tga -shadows 
./a5 -input scene4_12_point_light_circle_d_attenuation.txt -size 200 200 -output output4_12.tga -shadows 
./a5 -input scene4_13_point_light_circle_d2_attenuation.txt -size 200 200 -output output4_13.tga -shadows 

./a5 -input scene6_13_checkerboard.txt -size 200 200 -output output6_13.tga -shadows 

./a5 -input scene6_15_marble_cubes.txt -size 300 300 -output output6_15.tga 

./a5 -input scene6_17_marble_vase.txt -size 300 300 -output output6_17a.tga -bounces 1 -shadows

./a5 -input scene7_01_sphere_triangle.txt -size 180 180 -output output7_01.tga 

./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01b.tga 20 -uniform_samples 4 
./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01c.tga 20 -jittered_samples 4 
./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01e.tga 20 -uniform_samples 9  
./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01f.tga 20 -jittered_samples 9 
./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01h.tga 20 -uniform_samples 36 
./a5 -input scene7_01_sphere_triangle.txt -size 9 9 -render_samples samples7_01i.tga 20 -jittered_samples 36

./a5 -input scene7_01_sphere_triangle.txt -size 12 12 -output output7_01_low_res.tga 
./a5 -input scene7_01_sphere_triangle.txt -size 12 12 -render_samples samples7_01b_low_res.tga 15 -uniform_samples 9 
./a5 -input scene7_01_sphere_triangle.txt -size 12 12 -render_samples samples7_01c_low_res.tga 15 -jittered_samples 9 
./a5 -input scene7_01_sphere_triangle.txt -size 12 12 -output output7_01d_low_res.tga -uniform_samples 9 -box_filter 0.5 
./a5 -input scene7_01_sphere_triangle.txt -size 12 12 -output output7_01g_low_res.tga -jittered_samples 9 -box_filter 0.5 

./a5 -input scene7_02_checkerboard.txt -size 180 180 -output output7_02.tga 
./a5 -input scene7_02_checkerboard.txt -size 9 9 -render_samples samples7_02b.tga 20 -uniform_samples 16 
./a5 -input scene7_02_checkerboard.txt -size 9 9 -render_samples samples7_02c.tga 20 -jittered_samples 16 
./a5 -input scene7_02_checkerboard.txt -size 180 180 -output output7_02d.tga -uniform_samples 16 -box_filter 0.5 
./a5 -input scene7_02_checkerboard.txt -size 180 180 -output output7_02g.tga -jittered_samples 16 -box_filter 0.5 

./a5 -input scene7_03_marble_vase.txt  -size 200 200 -output output7_03a.tga -shadows 
./a5 -input scene7_03_marble_vase.txt  -size 200 200 -output output7_03b.tga -shadows -jittered_samples 4 -box_filter 0.4 
./a5 -input scene7_03_marble_vase.txt  -size 200 200 -output output7_03c.tga -shadows -jittered_samples 9 -box_filter 0.4 
./a5 -input scene7_03_marble_vase.txt  -size 200 200 -output output7_03d.tga -shadows -jittered_samples 36 -box_filter 0.4

./a5 -input boundBunny.txt -size 200 200 -output output3_04_BOUND.tga

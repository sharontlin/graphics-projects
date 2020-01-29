%PS0DEMO - Demo script for PS0
% You can run this thing by typing "main" at the MATLAB prompt.  Or, you
% can run parts of it interactively using cell mode.  In the MATLAB
% editor, go to the "Cell" menu and "Enable Cell Mode."  Then, you can go
% to a section and Ctrl-Enter to execute it.

%% Read in an image
% The function "imread" will create an (m x n x 3) array containing 8-bit
% unsigned integers.  This may be an inconvenient represenation for future
% assignments because of precision and overflow issues.  You can convert
% to a floating-point representation using "im2double" if desired.
Iorig = imread('image.jpg');

%% Show the image
% The function "imshow" will pop up a window displaying the image.  If the
% image is too big, it'll scale it to the proper size.  Alternatively, you
% can use "imtool" for a nicer user interface.
imshow(Iorig);
title('Original Image');

%% Crop the image
% Let's use MATLAB indexing to isolate a particular portion.  MATLAB
% indexes images from the upper-right corner, starting with 1 (unlike C/C++
% and Java).  Note that we can use "end" as a shortcut for array bounds.
Icrop  = Iorig(200:end-30,200:end-30,:);

% Pop up a new figure window and draw the image.
figure;
imshow(Icrop);
title('Cropped Image');

%% Resize the image
% Okay, let's resize it by subsampling.  We're going to use the same
% indexing operation, except that we're going to use an extra parameter to
% specify a stride.  This is a stupid way to resize an image!  If you zoom
% in, you'll notice bad aliasing.  A more proper way is to use "imresize"
% with bilinear or bicubic resampling (basically, what Photoshop does).
Ismall = Icrop(1:2:end,1:2:end,:);

% Pop up a new figure window and draw the image.
figure;
imshow(Ismall);
title('Small Image');

%% Channels
% We can view the three color channels of the image.  We're going to use
% "subplot" for a nice side-by-side view.
figure;
subplot(1,3,1);
imshow(Ismall(:,:,1)); title('Red');
subplot(1,3,2);
imshow(Ismall(:,:,2)); title('Green');
subplot(1,3,3);
imshow(Ismall(:,:,3)); title('Blue');

%% Grayscale
% MATLAB functions are all individually contained in files.  You can "edit
% ps0grayscale" to see the code for this function.
Igray = ps0grayscale(Icrop);
figure;
imshow(Igray);
title('Grayscale Image');

%% Threshold
% Similar to the Photoshop operation of the same name. "edit ps0threshold"
% for details.  
Ithre = ps0threshold(Igray, 80);
figure;
imshow(Ithre);
title('Threshold Image');














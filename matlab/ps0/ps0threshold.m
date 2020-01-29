%PS0THRESHOLD - Threshold to black-and-white bitmap.
% Demonstrates logical indexing.
function out = ps0threshold(in,val)

% Check to make sure that we have a grayscale image by seeing the size of
% the third dimension (which would be 3 if it's an RGB image).
if size(in,3) ~= 1
    error('Requires grayscale image!');
end

% Functions in MATLAB just write to an output variable (which can be the
% same as the input variable).  This isn't necessary, but it's just a demo.
out = in;

% This demonstrates "logical indexing."  The line "out > val" results in a
% logical (that is, 0/1) matrix which can be used to select specific
% elements of the image.  This is much faster than writing a loop.
out(out > val)  = 255;
out(out <= val) = 0;
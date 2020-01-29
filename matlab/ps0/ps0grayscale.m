%PS0GRAYSCALE - Convert image to grayscale.
function J = ps0grayscale(I)

% Just a linear combination of the RGB channels.  The result of this
% operation is a single-channel image. Notice that we can add and multiply
% matrices really easily in MATLAB without needing loops.
J = 0.30 * I(:,:,1) + 0.59*I(:,:,2) + 0.11*I(:,:,3);

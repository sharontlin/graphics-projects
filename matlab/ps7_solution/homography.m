function [H] = homography(from, to)
%   homography   Compute homography from im1_points to im2_points
%       [H] = HOMOGRAPHY(from, to)
% 
%   points should be given in the format output by ginput:
%
%       [from(:,1) from(:,2); to(:,1) to(:,2); x3 y3; ...]
%
%   for image 1 & image 2. The resulting homography H is defined such that:
%
%       to = H * from
%

    n = size(from,1);
    assert(n == size(to,1));

    % Set up the system of equations for all the x and y values
    ax = [from(:,1) from(:,2) ones(n, 1) zeros(n, 3) -from(:,1).*to(:,1) -from(:,2).*to(:,1)];
    ay = [zeros(n, 3) from(:,1) from(:,2) ones(n, 1) -from(:,1).*to(:,2) -from(:,2).*to(:,2)];
    
    % Merge x and y equations into an 8*n system and solve
    A = [ax; ay];
    b = [to(:,1); to(:,2)];
    x = A\b;
    
    % H = [x(1) x(2) x(3); x(4) x(5) x(6); x(7) x(8) 1]
    H = reshape([x; 1], 3, 3)';

end

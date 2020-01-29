function out = bilateral( I, w, sigma_d, sigma_r )
%  out = bilateral( I, w, sigma_d, sigma_r )
%  'out' is a bilateral filtered version of input GRAYSCALE image 'I'
%  'w' - use a (2w-1) x (2w-1) sized kernel
%  'sigma_d' - spatial standard deviation
%  'sigma_r' - (intensity) range standard deviation
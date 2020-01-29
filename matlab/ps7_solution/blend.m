%   BLEND   warp and blend images into a common view.
%       [IM] = BLEND(IM1, IM2, H21, IM3, H31, ...)
% 
%   Blend takes a variable number of arguments. The first argument is the image
%   to be used at the center of the blend (unwarped). The remaining arguments 
%   are pairs of images and the homographies mapping from those images to the 
%   first, in interleaved order.
%
%   The images will be accumulated in the order given: im1 first, then im2 on 
%   top of that, and so on.

function IM = blend(im1, varargin)

    % make sure there are N*2 arguments after the first image
    assert(mod(nargin-1,2) == 0);
    nImages = 1 + (nargin-1)/2;
    
    h = size(im1,1);
    w = size(im1,2);
    % corners in image-local homogeneous coordinates
    ch = [1 1 1; w 1 1; w h 1; 1 h 1];
    
    % Pack the images & homographies into a struct array
    images = struct([]);
    images(1).im = im1;
    images(1).H = eye(3);
    for ii=2:nImages
        images(ii).im = varargin{(ii-1)*2-1};
        images(ii).H  = varargin{(ii-1)*2};
    end
    
    for ii=1:nImages
        images(ii).bounds = project_homog( images(ii).H * ch' );
    end

    % compute bounds on the whole set of images
    [ll,ur] = bound_set([images.bounds]);
    offset = -ll;
    w = int32(ceil(ur(1)+offset(1)));
    h = int32(ceil(ur(2)+offset(2)));
    IM = zeros(h,w,3);
    xCoords = repmat(double(1:w), [h 1]);
    yCoords = repmat(double(1:h)', [1 w]);
    
    % Translate everything so that the lower-left corner is 0,0
    % Set up translation matrix for the offset into the output canvas.
    offsetTranslation = eye(3);
    offsetTranslation(1:2,3) = offsetTranslation(1:2,3) + offset';
    for ii=1:nImages
        % add offset translation into the homography matrix
        images(ii).H = offsetTranslation * images(ii).H;
        % translate the bounds
        images(ii).bounds(:,1) = images(ii).bounds(:,1) + offset(1);
        images(ii).bounds(:,2) = images(ii).bounds(:,2) + offset(2);
    end
    
    for ii=1:nImages
        % sompute masks
        mask = false(h,w); % set up dimensions
        mask(:) = inpolygon( xCoords, yCoords,  ...
                             images(ii).bounds(:,1), ...
                             images(ii).bounds(:,2) );
        
        % compute coordinates at which to sample by solving pixelCoord = H*sampleCoord
        sampleCoords = images(ii).H \ [xCoords(mask)'; yCoords(mask)'; ones(1,sum(mask(:)))];
        
        % resample and blend
        for c=1:3
            % load the existing color channel
            tmp = IM(:,:,c);
            % replace pixels at current mask with interpolated results for current image
            tmp(mask) = interp2(images(ii).im(:,:,c), sampleCoords(1,:) ./ sampleCoords(3,:), sampleCoords(2,:) ./ sampleCoords(3,:));
            % save back out
            IM(:,:,c) = tmp;
        end
    end
end

function p = project_homog(homog_points)
    p = [homog_points(1,:)./homog_points(3,:); homog_points(2,:)./homog_points(3,:)]';
end

function [ll,ur] = bound_set(bounds)
%   CORNERS   Find lower-left/upper-right corners of the bound set
%       [[LL,UR]] = BOUND_SET(BOUNDS)

    Xs = bounds(:, 1:2:end); Xs = Xs(:);
    Ys = bounds(:, 2:2:end); Ys = Ys(:);
    ll = [min(Xs) min(Ys)];
    ur = [max(Xs) max(Ys)];

end %  function
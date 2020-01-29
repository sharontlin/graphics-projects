Scale = 0.5 % speed up testing
im1 = imresize(im2double(imread('im1.jpg')), Scale);
im2 = imresize(im2double(imread('im2.jpg')), Scale);

load points.mat;
pts12 = pts12*Scale;
pts21 = pts21*Scale;

H12 = homography(pts12, pts21);

pts12_2 = [pts12'; ones(1, size(pts12,1))];
pts12_2 = H12*pts12_2;
pts12_2 = [pts12_2(1,:) ./ pts12_2(3,:); pts12_2(2,:) ./ pts12_2(3,:)]';

figure(1);
imshow(im2); hold on;
plot(pts21(:,1), pts21(:,2), 'r*');
plot(pts12_2(:,1), pts12_2(:,2), 'g*');

imtool(blend(im2, im1, H12));
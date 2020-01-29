# graphics-projects

Computer graphics projects from MKS66. Currently adding completed files.

### Dependencies

- Imagemagick
- XQuartz

### To Run

You'll need to install Imagemagick. On a Mac you can run:

```
brew install imagemagick --with-x11
```

If you have a newer version of Homebrew, you may not be able to run the command. There is a [workaround](https://stackoverflow.com/questions/44624479/how-to-use-imagemagick-with-xquartz).

```
git clone https://github.com/ImageMagick/ImageMagick.git
cd ImageMagick/
env CFLAGS="$(xml2-config --cflags)" XML_CFLAGS="$(xml2-config --cflags)" XML_LIBS="$(xml2-config --libs)" ./configure
make
sudo make install
```

### Projects

- 3d: Torus, sphere, box
- cstack: Stack library, coordinate system
- curves: Circles, hermites, Bezier curves 
- lighting: Phong reflection with flat shading
- line: Bresenham's Line Algorithm
- matrix: Matrix template
- mdl: Motion Description Language
- mdl_animation: Keyframe animations
- picmaker: Converting ppm to png
- polygons: Vector math and backface culling
- solids: Scanline conversion and z-buffering
- transform: Transformation matrix parser


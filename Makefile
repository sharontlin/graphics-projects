#include <fstream>
#include <iostream>

const int width = 500;
const int height = 500;

int main() {
    std::ofstream image;
    image.open("image.ppm");
    char header[30];
    sprintf(header, "P3 %d %d 255 ", width, height);
    image << header;
    char line[20];
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            sprintf(line, "%d %d %d ", (i * j) % 256, abs((i >> 1) % 256), abs((j >> 1) % 256));
            image << line;
        }
    }
    image.close();
    return 0;
}

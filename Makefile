all: main.c
	gcc -o out main.c
	./out

clean:
	rm out
    
run:
	./exec.out
    
convert:
	convert image.ppm image.png

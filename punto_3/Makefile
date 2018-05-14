caos.pdf: caos.py data.txt
	python3 caos.py
data.txt: caos.cpp
	c++ caos.cpp -o caos.x
	./caos.x > data.txt

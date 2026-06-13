build:
	g++ -std=c++23 -O2 ./main.cpp -o main
run:
	./main
clean:
	rm ./main output.txt errors.txt
execute:
	chmod +x run.sh && ./run.sh

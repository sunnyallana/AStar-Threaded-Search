all: singleThreaded multiThreaded

singleThreaded: src/singleThreaded.cpp
	g++ -o single $^ -lpthread

multiThreaded: src/multiThreaded.cpp
	g++ -o multi $^ -lpthread

clean:
	rm -f single multi

run_single: singleThreaded
	./single

run_multi: multiThreaded
	./multi
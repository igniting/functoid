run:
	g++ example.cpp -o example.out
	./example.out

check:
	g++ *.h

clean:
	rm -f *.gch *.out

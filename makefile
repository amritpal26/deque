Deque.o : Deque.h Deque.cpp
	g++ -c Deque.cpp

clean: 
	rm -f *.o
	rm -f testing/*.o
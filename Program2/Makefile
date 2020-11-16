postfix_eval: postfix_eval.cc stack.h
	g++ -Wall -Werror -o postfix_eval postfix_eval.cc

cpplint:
	/home/cs36cjp/public/cpplint/cpplint postfix_eval.cc

test_deque: test_deque.cc deque.h
	g++ -Wall -Werror -o test_deque test_deque.cc -pthread -lgtest

clean:
	rm postfix_eval test_deque

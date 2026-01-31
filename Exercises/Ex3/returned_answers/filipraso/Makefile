CXX      := g++
CXXFLAGS := -O2 -Wall -Wextra -std=c++17
LIBDLL   := met.dll
IMPLIB   := libmet.dll.a
TEST     := test.exe

.PHONY: all clean run

all: $(LIBDLL) $(TEST)

$(LIBDLL): MET.cpp MET.h
	$(CXX) $(CXXFLAGS) -shared -o $(LIBDLL) MET.cpp -Wl,--out-implib,$(IMPLIB)

$(TEST): test.cpp MET.h $(IMPLIB)
	$(CXX) $(CXXFLAGS) -o $(TEST) test.cpp -L. -lmet

run: all
	./$(TEST)

clean:
	rm -f $(LIBDLL) $(IMPLIB) $(TEST)

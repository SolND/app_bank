CXXFLAGS:=-g -Wall -I/usr/local/include/
OBJ= main.o bank_node.o bank_tree.o admin.o staff.o node.o hash_table.o customer.o


all: $(OBJ)
	$(CXX) -o app_bank $(OBJ) $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm $(OBJ) app_bank -f *.o
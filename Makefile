CXXFLAGS:=-g -Wall -I/usr/local/include/
OBJ_DIR := build
OBJ := $(addprefix $(OBJ_DIR)/, main.o bank_node.o bank_tree.o admin.o staff.o node.o hash_table.o customer.o)

all: $(OBJ)
	$(CXX) -o app_bank $(OBJ) $(CXXFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(OBJ_DIR) app_bank

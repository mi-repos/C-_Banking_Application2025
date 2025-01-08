CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp src/BankingApp.cpp src/Account.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = banking_app

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

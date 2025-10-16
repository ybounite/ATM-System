NAME   = ATM-System
CPP    = c++
CFLAGS = -Wall -Wextra -Werror -g3
RM     = rm -rf

SRC = ATM_Simulation.cpp \
	  StringUtils.cpp\
	  ATM_ManagementSystem/LoginCleint.cpp \
	  ATM_ManagementSystem/FindCleint.cpp \
	  ATM_ManagementSystem/ATM_Deposit.cpp \
	  ATM_ManagementSystem/ATM_QuickWithdraw.cpp \
	  ATM_ManagementSystem/ATM_NormalWithdraw.cpp \
	  ATM_ManagementSystem/CheckBalance.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)	
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

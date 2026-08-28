# ATM System

A comprehensive ATM (Automated Teller Machine) system simulation built with C++. This project provides a realistic command-line based ATM interface with essential banking operations.

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building](#building)
- [Usage](#usage)
- [Architecture](#architecture)
- [File Descriptions](#file-descriptions)
- [Contributing](#contributing)
- [License](#license)

## Features

The ATM System includes the following core features:

- **User Authentication**: Secure login using account number and PIN code
- **Quick Withdraw**: Predefined withdrawal amounts for fast transactions
- **Normal Withdraw**: Custom withdrawal amounts with validation
- **Deposit**: Add funds to customer accounts
- **Balance Inquiry**: Check current account balance
- **Logout**: Secure logout functionality
- **Session Management**: Maintain user session throughout transaction lifecycle
- **Color-Coded CLI**: Enhanced user experience with colored terminal output
- **Data Persistence**: Client information stored in external files
- **Input Validation**: Comprehensive validation for all transactions

## Project Structure

```
ATM-System/
├── ATM-System/
│   ├── ATM_Simulation.cpp          # Main program entry point
│   ├── StringUtils.cpp              # String utility functions
│   ├── Makefile                     # Build configuration
│   ├── includes/
│   │   └── ATM_Simulation.hpp       # Header file with declarations
│   └── ATM_ManagementSystem/
│       ├── LoginCleint.cpp          # Client login functionality
│       ├── FindCleint.cpp           # Client search and retrieval
│       ├── ATM_QuickWithdraw.cpp    # Quick withdrawal implementation
│       ├── ATM_NormalWithdraw.cpp   # Custom withdrawal implementation
│       ├── ATM_Deposit.cpp          # Deposit functionality
│       └── CheckBalance.cpp         # Balance inquiry implementation
└── README.md                         # Documentation

```

## Requirements

- **Compiler**: C++11 or higher
- **Operating System**: Linux/Unix-based systems (uses `system("clear")`)
- **Build Tool**: GNU Make

## Installation

### Clone the Repository

```bash
git clone https://github.com/ybounite/ATM-System.git
cd ATM-System/ATM-System
```

### Directory Setup

Ensure the data directory exists for client information:

```bash
mkdir -p ../DataClient
```

The system expects client data in: `../DataClient/Clients.txt`

## Building

### Compile the Project

Using the provided Makefile:

```bash
make
```

### Build Options

```bash
make          # Compile the project
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Clean and rebuild
```

### Manual Compilation

If you prefer to compile manually:

```bash
c++ -Wall -Wextra -Werror -g3 -o ATM-System \
  ATM_Simulation.cpp \
  StringUtils.cpp \
  ATM_ManagementSystem/LoginCleint.cpp \
  ATM_ManagementSystem/FindCleint.cpp \
  ATM_ManagementSystem/ATM_Deposit.cpp \
  ATM_ManagementSystem/ATM_QuickWithdraw.cpp \
  ATM_ManagementSystem/ATM_NormalWithdraw.cpp \
  ATM_ManagementSystem/CheckBalance.cpp
```

## Usage

### Run the Application

```bash
./ATM-System
```

### User Flow

1. **Login Screen**: Enter your account number and PIN code
2. **Main Menu**: Choose from available operations:
   - `[1]` Quick Withdraw - Select predefined amounts
   - `[2]` Normal Withdraw - Enter custom amount
   - `[3]` Deposit - Add funds to your account
   - `[4]` Check Balance - View account balance
   - `[5]` Logout - Log out and return to login screen
   - `[6]` Exit - Close the application

### Example Session

```
::::::::::::::::::::::::::::::::::::::::::
        Login Screen
::::::::::::::::::::::::::::::::::::::::::

Enter Account Number? 1001
Enter Pin Code? 1234

::::::::::::::::::::::::::::::::::::::::::
        ATM Main Menue Screen
::::::::::::::::::::::::::::::::::::::::::
  [1] Quick Withdraw.
  [2] Normal Withdraw.
  [3] Deposit.
  [4] Check Balance.
  [5] Logout.
  [6] Exit.
::::::::::::::::::::::::::::::::::::::::::

Choose what do you want to do? [1 to 6] ?
```

## Architecture

### Data Structure

The system uses a client data structure (`stDataClient`) to manage account information:

```cpp
struct stDataClient
{
    string AccountNumber;      // Unique account identifier
    string PinCode;            // Secure PIN for authentication
    string Name;               // Account holder name
    string Phone;              // Contact phone number
    double AccountBalance;     // Current account balance
    bool MarkForUpdate;        // Flag for data persistence
};
```

### Main Components

1. **Authentication Module** (`LoginCleint.cpp`, `FindCleint.cpp`)
   - Validates user credentials
   - Loads client information from file
   - Manages login sessions

2. **Transaction Module** (`ATM_QuickWithdraw.cpp`, `ATM_NormalWithdraw.cpp`, `ATM_Deposit.cpp`)
   - Processes financial transactions
   - Validates transaction amounts
   - Updates account balances

3. **Query Module** (`CheckBalance.cpp`)
   - Retrieves account balance
   - Displays account information

4. **Utility Module** (`StringUtils.cpp`)
   - String manipulation functions
   - Formatting utilities

## File Descriptions

### Core Files

| File | Purpose |
|------|---------|
| `ATM_Simulation.cpp` | Main program logic, menu system, and control flow |
| `ATM_Simulation.hpp` | Header file with all declarations, enums, and structures |
| `StringUtils.cpp` | Utility functions for string operations |
| `Makefile` | Build configuration and compilation rules |

### Management System Files

| File | Purpose |
|------|---------|
| `LoginCleint.cpp` | Authentication and login screen |
| `FindCleint.cpp` | Client lookup functionality |
| `ATM_QuickWithdraw.cpp` | Quick withdrawal with preset amounts |
| `ATM_NormalWithdraw.cpp` | Custom withdrawal processing |
| `ATM_Deposit.cpp` | Deposit transactions |
| `CheckBalance.cpp` | Account balance inquiries |

### Data Files

| File | Purpose |
|------|---------|
| `../DataClient/Clients.txt` | Client data storage (format: separated values) |

## Code Features

### Color-Coded Output

The system uses ANSI color codes for better UI experience:

- **YELLOW**: Headings and titles
- **GREEN**: Success messages
- **RED**: Error messages
- **BLUE**: Borders and separators
- **WHITE**: Regular text

### Input Validation

- PIN code verification
- Transaction amount validation
- Account number validation
- Sufficient balance checking

### String Processing

- String splitting and joining utilities
- Tab formatting for aligned output
- Case handling

## Building with Different Compilers

The project uses standard C++ and can be compiled with various compilers:

```bash
# Using GCC
g++ -Wall -Wextra -Werror -g3 -o ATM-System ...

# Using Clang
clang++ -Wall -Wextra -Werror -g3 -o ATM-System ...
```

## Known Limitations

- Platform-specific: Uses `system("clear")` for clearing screen (Unix/Linux only)
- Terminal-based UI: Requires terminal support for ANSI color codes
- Local data storage: Uses file-based client data (not production-ready for concurrent access)
- PIN stored in plain text in data files (not secure for production)

## Future Enhancements

Potential improvements for production use:

- [ ] Multi-user concurrent access handling
- [ ] Database integration (PostgreSQL, MySQL)
- [ ] Encrypted PIN storage
- [ ] Transaction history logging
- [ ] Account transfer functionality
- [ ] Multiple currency support
- [ ] Admin panel for account management
- [ ] Cross-platform UI support
- [ ] Network/remote access capability
- [ ] Comprehensive error handling and logging

## Contributing

Contributions are welcome! Please feel free to:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Code Style

The project follows these conventions:

- **Naming**: camelCase for functions and variables, PascalCase for classes/structs
- **Comments**: Clear comments for non-obvious logic
- **Formatting**: 4-space indentation
- **Functions**: Single responsibility principle

## Troubleshooting

### Build Issues

**Error: "No such file or directory"**
- Ensure all source files are present
- Check file paths in Makefile
- Verify you're in the correct directory

**Compilation Warnings/Errors**
- Use `-Wall -Wextra` flags to identify issues
- Ensure C++11 or higher compiler version

### Runtime Issues

**"cannot find Clients.txt"**
- Create the `DataClient` directory
- Ensure client data file is properly formatted

**Screen not clearing**
- The `system("clear")` command is Unix/Linux specific
- Modify for Windows: use `system("cls")` instead

## License

This project is open source and available under the MIT License. See LICENSE file for details.

## Author

Created by [ybounite](https://github.com/ybounite)

## Support

For issues, questions, or suggestions, please open an issue on the GitHub repository.

---

**Last Updated**: August 2026

#ifndef TERMINAL_REDIRECT_H
#define TERMINAL_REDIRECT_H

#include <string>

// Opens a new terminal window, changes to the current working directory, and runs the specified program.
void openNewTerminalAndRunProgram(const std::string& programPath);

#endif // TERMINAL_REDIRECT_H

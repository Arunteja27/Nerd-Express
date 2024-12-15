#include "TerminalRedirect.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h> // For getcwd()
#include <string>
#include <sstream> // For escaping

// Function to escape single quotes in the file path for AppleScript
std::string escapeSingleQuotes(const std::string& path) {
    std::ostringstream escapedPath;
    for (char c : path) {
        if (c == '\'') {
            escapedPath << "\\'"; // Escape the single quote
        } else {
            escapedPath << c;
        }
    }
    return escapedPath.str();
}

void openNewTerminalAndRunProgram(const std::string& programPath) {
    // Get the current working directory
    char cwd[1024];
    if (!getcwd(cwd, sizeof(cwd))) {
        std::cerr << "Error: Unable to get current working directory." << std::endl;
        return;
    }

    // Escape single quotes in the working directory
    std::string escapedCwd = escapeSingleQuotes(cwd);

    // Construct the AppleScript command
    std::string script = "osascript -e 'tell application \"Terminal\" "
                         "to do script \"cd ";
    script += escapedCwd;
    script += " && ";
    script += programPath;
    script += "\"'";

    // Debug the constructed script (optional)
    std::cerr << "Executing script: " << script << std::endl;

    // Execute the AppleScript
    int result = system(script.c_str());
    if (result != 0) {
        std::cerr << "Error: Failed to open new terminal window and run the program." << std::endl;
    }
}

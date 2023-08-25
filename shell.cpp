#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <iterator>

struct CommandDB {
    std::unordered_set<std::string> commands;

    CommandDB() {
        commands.insert("ls");
        commands.insert("cd");
        commands.insert("mkdir");
        commands.insert("rm");
        commands.insert("cp");
        commands.insert("pwd");
        commands.insert("sudo");
        commands.insert("ifconfig");
        commands.insert("neofetch");
        // Add more commands
    }

    bool commandExists(const std::string& command) {
        return commands.find(command) != commands.end();
    }
};

struct TerminalShell {
    std::string currentDirectory;
    std::string currentUser;
    CommandDB database;

    TerminalShell() : currentDirectory("/home/user"), currentUser("user") {}

    void run() {
        while (true) {
            std::cout << currentUser << "@" << currentDirectory << "$ ";
            std::string userInput;
            std::getline(std::cin, userInput);

            if (userInput == "exit") {
                std::cout << "Exiting terminal shell." << std::endl;
                break;
            }

            if (userInput == "su root") {
                currentUser = "root";
                continue;
            }

            executeCommand(userInput);
        }
    }

    void executeCommand(const std::string& userInput) {
        std::istringstream iss(userInput);
        std::vector<std::string> tokens(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

        if (tokens.empty()) {
            return;
        }

        std::string command = tokens[0];

        if (command == "pwd") {
            std::cout << currentDirectory << std::endl;
        }
        else if (command == "ls") {
            simulateLs();
        }
        else if (command == "cd") {
            simulateCd(tokens);
        }
        else if (command == "mkdir") {
            simulateMkdir(tokens);
        }
        else if (command == "rm") {
            simulateRm(tokens);
        }
        else if (command == "cp") {
            simulateCp(tokens);
        }
        else if (command == "sudo") {
            simulateSudo(tokens);
        }
        else if (command == "ifconfig") {
            simulateIfconfig();
        }
        else if (command == "neofetch") {
            simulateNeofetch();
        }
        else if (!database.commandExists(command)) {
            std::cout << "bash:" << command << ": command not found..." << std::endl;
        }
    }

    // Simulate ls command
    void simulateLs() {
        std::cout << "file1.txt  file2.cpp  folder1  folder2" << std::endl;
    }

    // Simulate cd command
    void simulateCd(const std::vector<std::string>& tokens) {
        if (tokens.size() < 2) {
            std::cout << "Usage: cd <directory>" << std::endl;
        }
        else {
            std::cout << "Changed directory to: " << tokens[1] << std::endl;
            currentDirectory = tokens[1];
        }
    }

    // Simulate mkdir command
    void simulateMkdir(const std::vector<std::string>& tokens) {
        if (tokens.size() < 2) {
            std::cout << "Usage: mkdir <directory>" << std::endl;
        }
        else {
            std::cout << "Created directory: " << tokens[1] << std::endl;
        }
    }

    // Simulate rm command
    void simulateRm(const std::vector<std::string>& tokens) {
        if (tokens.size() < 2) {
            std::cout << "Usage: rm <file/directory>" << std::endl;
        }
        else {
            std::cout << "Removed: " << tokens[1] << std::endl;
        }
    }

    // Simulate cp command
    void simulateCp(const std::vector<std::string>& tokens) {
        if (tokens.size() < 3) {
            std::cout << "Usage: cp <source> <destination>" << std::endl;
        }
        else {
            std::cout << "Copied " << tokens[1] << " to " << tokens[2] << std::endl;
        }
    }

    // Simulate sudo apt install {package} command
    void simulateSudo(const std::vector<std::string>& tokens) {
        if (tokens.size() < 4 || tokens[1] != "apt" || tokens[2] != "install") {
            std::cout << "Usage: sudo apt install {package}" << std::endl;
        }
        else {
            std::string package = tokens[3];
            std::cout << "Simulating installation of package: " << package << std::endl;
            std::cout << "Package " << package << " has been installed." << std::endl;
        }
    }
    void simulateIfconfig() {
        std::cout << "eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500" << std::endl;
        std::cout << "        inet 192.168.1.2  netmask 255.255.255.0  broadcast 192.168.1.255" << std::endl;
        std::cout << "        inet6 fe80::a00:27ff:fe45:fa07  prefixlen 64  scopeid 0x20<link>" << std::endl;
        std::cout << "        ether 08:00:27:45:fa:07  txqueuelen 1000  (Ethernet)" << std::endl;
        std::cout << "        RX packets 175  bytes 14093 (13.7 KiB)" << std::endl;
        std::cout << "        RX errors 0  dropped 0  overruns 0  frame 0" << std::endl;
        std::cout << "        TX packets 133  bytes 21119 (20.6 KiB)" << std::endl;
        std::cout << "        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0" << std::endl;
    }
    void simulateNeofetch() {
    std::cout << "         .-/+oossssoo+/-.               " << "OS: Ubuntu" << std::endl;
    std::cout << "     `:+ssssssssssssssssss+:`           " << "Host: user" << std::endl;
    std::cout << "   -+ssssssssssssssssssyyssss+-         " << "Kernel: Linux" << std::endl;
    std::cout << " .ossssssssssssssssssdMMMNysssso.       " << "Uptime: 1 hour" << std::endl;
    std::cout << "/ssssssssssshdmmNNmmyNMMMMhssssss/      " << "Packages: 1000" << std::endl;
    std::cout << "+sssshhhyNMMMyhhyyyyhmNMMMNhssss+      " << "Shell: Shell" << std::endl;
    std::cout << "ossyNMMMNyMMh     /mMMMNyNMMNoss      " << "Resolution: 1920x1080" << std::endl;
    std::cout << "+sssshhhyNMMMyhhyyyyhdNMMMNhssss+      " << "DE: Gnome" << std::endl;
    std::cout << "/sssssssssssdmmNNNNNNmmNMMMMhssss/      " << "WM: Window Manager" << std::endl;
    std::cout << ".ossssssssssssssssssdMMMNysssso.       " << "Theme: Gnome Black Theme" << std::endl;
    std::cout << " -+sssssssssssssssssyyyssss+-         " << "Icons: Gnome Black Icons" << std::endl;
    std::cout << "   -+ssssssssssssssssssyyssss+-         " << "Terminal: Terminal" << std::endl;
    std::cout << "     `:+ssssssssssssssssss+:`           " << "CPU: Ryzen 9 3960x" << std::endl;
    std::cout << "         .-/+oossssoo+/-               " << "GPU: RTX 4090" << std::endl;
    std::cout << "                                        " << "Memory: 64 GB " << std::endl;
    std::cout << "                                        " << "Disk: 256 GB" << std::endl;
}
};

int main() {
    TerminalShell shell;
    shell.run();
    return 0;
};

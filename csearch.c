#include <stdio.h>
#include <getopt.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function prototypes
void helperMessage(void);
void removeWhitespace(char *str);
void printHighlightedLine(const char *line, const char *word);
void search(FILE *file, const char *word);

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    const char *word = NULL;
    int opt = 0;

    // Options and long options
    const char *shortOpts = "f:w:hv";
    struct option longOpts[] = {
        {"file", required_argument, NULL, 'f'},
        {"word", required_argument, NULL, 'w'},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}};

    // Parse command-line arguments
    while ((opt = getopt_long(argc, argv, shortOpts, longOpts, NULL)) != -1) {
        switch (opt) {
        case 'f':
            // Open the specified file for reading
            file = fopen(optarg, "r");
            if (file == NULL) {
                perror("Error opening file");
                return 1;
            }
            break;
        case 'w':
            // Set the search word
            word = optarg;
            break;
        case 'h':
            // Display help message
            helperMessage();
            return 0;
        case 'v':
            // Display version information
            printf("Search is a simple word search utility for GNU/Linux systems.\n"
                   "Developed by skmishra 2023\n");
            return 0;
        default:
            // Display an error message for unknown options
            fprintf(stderr, "Error: Unknown option\n");
            return 1;
        }
    }

    // Check if both file and word are specified
    if (file == NULL || word == NULL) {
        fprintf(stderr, "Error: Both file and word must be specified\n");
        return 1;
    }

    // Call the search function
    search(file, word);

    // Close the file
    fclose(file);

    return 0;
}

// Display help message for command-line options
void helperMessage(void) {
    puts("This is a word search utility for the command line, similar to grep/fstring tool.\n"
         "-f, --file FILE          | Put the filename from which you want to search \n"
         "-w, --word WORD          | Word which you want to search \n"
         "-h, --help HELP          | Use this flag to get help about the flags and usage \n"
         "-v, --version VERSION    | Use this flag to print the version of the tool currently installed \n"
         "Example: search -f <filename>  -w <word>\n");
}

// Remove leading and trailing whitespace from a string
void removeWhitespace(char *str) {
    // Remove leading whitespace
    char *start = str;
    while (isspace((unsigned char)(*start))) {
        start++;
    }
    memmove(str, start, strlen(start) + 1);

    // Remove trailing whitespace
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)(str[len - 1]))) {
        str[--len] = '\0';
    }
}

// Print a line with matching word highlighted
void printHighlightedLine(const char *line, const char *word) {
    const char *matchStart = strstr(line, word);

    while (*line) {
        // Highlight the matching word
        if (line == matchStart) {
            printf("\x1b[1;31m");
        }
        putchar(*line);
        // Reset text color after printing the matching word
        if (line == matchStart + strlen(word) - 1) {
            printf("\x1b[0m");
        }
        line++;
    }
}

// Search for the specified word in the given file
void search(FILE *file, const char *word) {
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove newline character if present
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        // Check if the word is present in the line
        if (strstr(buffer, word)) {
            // Remove leading and trailing whitespace
            removeWhitespace(buffer);
            // Print the line with matching word highlighted
            printHighlightedLine(buffer, word);
            printf("\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/stat.h>

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s [-e] <source> <destination>\n", prog_name);
    exit(EXIT_FAILURE);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void perform_operation(const char *source, const char *destination, const char *command, const char *extra_args) {
    char command_buffer[1024];

    snprintf(command_buffer, sizeof(command_buffer), "%s %s \"%s\" \"%s\"", command, extra_args, source, destination);
    if (system(command_buffer) != 0) {
        handle_error("Operation failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usage(argv[0]);
    }

    int e_flag = 0;
    char *source = NULL;
    char *destination = NULL;
    const char *command = NULL;
    char extra_args[256] = "";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            e_flag = 1;
        } else if (argv[i][0] == '-') {
            strncat(extra_args, argv[i], sizeof(extra_args) - strlen(extra_args) - 1);
            strncat(extra_args, " ", sizeof(extra_args) - strlen(extra_args) - 1);
        } else if (!source) {
            source = argv[i];
        } else if (!destination) {
            destination = argv[i];
        } else {
            usage(argv[0]);
        }
    }

    if (!source || !destination) {
        usage(argv[0]);
    }

    if (strstr(argv[0], "mv") != NULL) {
        command = "mv";
    } else if (strstr(argv[0], "cp") != NULL) {
        command = "cp";
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (e_flag) {
    char source_copy[1024];
        strncpy(source_copy, source, sizeof(source_copy));
        char *dir = dirname(source_copy);

        char destination_buffer[1024];
        snprintf(destination_buffer, sizeof(destination_buffer), "%s/%s", dir, destination);

        perform_operation(source, destination_buffer, command, extra_args);
    } else {
        perform_operation(source, destination, command, extra_args);
    }

    return EXIT_SUCCESS;
}


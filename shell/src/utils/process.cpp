#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace livi {

static pid_t forkChecked() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        abort();
    }
    return pid;
}

void processStart(const char **argv) {
    pid_t pid;
    int status;

    pid = forkChecked();
    if (pid) {
        // parent
        waitpid(pid, &status, 0);
        return;
    }
    // child
    pid = forkChecked();
    if (pid) {
        // parent
        exit(0);
    }
    execvp(argv[0], (char **)argv);
    perror("execvpe");
    abort();
}

}  // namespace livi

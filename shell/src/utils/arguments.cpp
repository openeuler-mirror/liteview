namespace livi {

static int g_argc;
static char **g_argv;

void argumentsInit(int argc, char *argv[]) {
    g_argc = argc;
    g_argv = argv;
}

int argumentsGetArgc() {
    return g_argc;
}

char **argumentsGetargv() {
    return g_argv;
}

}  // namespace livi